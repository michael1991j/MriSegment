/*
 * FemerOperation.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#include "FemerOperation.h"
#include "JustPlotPlease.h"

FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput, double s, double r, int i) {
        // Constructor called for filtering
        leafSize = s;
        radius = r;
        minFriends = i;
        this->Labeledoutput = Labeledoutput;
        this->Labeledinput = Labeledinput;
}

FemerOperation::~FemerOperation() {
	// TODO Auto-generated destructor stub
}

void FemerOperation::Preprocess() {

  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(BONE)->cloud);
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;

	cout << "Radius outlier filtering.\n" << "radius is: " << radius << "\n" << "minimum neighbors is: " << minFriends << "\n";
	
	cout << "points in cloud before filtering: " << cloudin->size() << "\n";

	/* Create the filtering object */
	pcl::VoxelGrid < pcl::PointXYZ > sor;
	sor.setInputCloud(cloudin);
	sor.setLeafSize(leafSize, leafSize, leafSize);
	sor.filter(*cloud_filtered);

	/* build the filter */
	outrem.setInputCloud(cloudin);
	outrem.setRadiusSearch(radius);
	outrem.setMinNeighborsInRadius(minFriends);

	// apply filter
	outrem.filter (*cloud_filtered);

	cout << (cloudin->size() - cloud_filtered->size()) << " points removed.\n";
}

void FemerOperation::Fuse() {
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(BONE)->cloud);
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);

  		cout << "Empty Cloud Check.\n";
        /* Ensure clouds arent empty */
        if (cloudin->size() == 0)
                PCL_ERROR ("cloudin point cloud is empty, exiting registration.\n");
        else if(cloud_filtered->size() == 0)
                PCL_ERROR ("cloud_filtered point cloud is empty, exiting registration.\n");
        else
                cout << "cloudin size is: " << cloudin->size() << " cloud_filtered size is: " << cloud_filtered->size() << ".\n";

    	// Defining rotation matrix and translation vector
    	Eigen::Matrix4f transformation_matrix = Eigen::Matrix4f::Identity(); // We initialize this matrix to a null transformation.

    	// Defining a rotation matrix (see https://en.wikipedia.org/wiki/Rotation_matrix)
    	float theta = M_PI/4; // The angle of rotation in radians
    	transformation_matrix (0,0) = cos(theta);
    	transformation_matrix (0,1) = -sin(theta);
    	transformation_matrix (1,0) = sin(theta);
    	transformation_matrix (1,1) = cos(theta);

    	// Executing the transformation
    	pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZ> ());	// A pointer on a new cloud
    	pcl::transformPointCloud (*cloudin, *transformed_cloud, transformation_matrix);
}

void FemerOperation::Postprocess() {

		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);

		// Normal estimation*
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
		pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
		pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
		tree->setInputCloud (cloud_filtered);
		n.setInputCloud (cloud_filtered);
		n.setSearchMethod (tree);
		n.setKSearch (20);
		n.compute (*normals);
		//* normals should not contain the point normals + surface curvatures

		// Concatenate the XYZ and normal fields*
		pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
		pcl::concatenateFields (*cloud_filtered, *normals, *cloud_with_normals);
		//* cloud_with_normals = cloud + normals

		// Create search tree*
		pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
		tree2->setInputCloud (cloud_with_normals);

		// Initialize objects
		pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
		pcl::PolygonMesh triangles;

		// Set the maximum distance between connected points (maximum edge length)
		gp3.setSearchRadius (100);

		// Set typical values for the parameters
		gp3.setMu (2.5);
		gp3.setMaximumNearestNeighbors (100);
		gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
		gp3.setMinimumAngle(M_PI/18); // 10 degrees
		gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
		gp3.setNormalConsistency(false);

		// Get result
		gp3.setInputCloud (cloud_with_normals);
		gp3.setSearchMethod (tree2);
		gp3.reconstruct (triangles);

		// Additional vertex information
		std::vector<int> parts = gp3.getPartIDs();
		std::vector<int> states = gp3.getPointStates();

		// Finish
		pcl::io::saveVTKFile ("mesh.vtk", triangles);
}

void FemerOperation::Megaprocess() {

		long val = 0;
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(BONE)->cloud);
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);
  		pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;

  		cout << "Radius outlier filtering.\n" << "radius is: " << radius << "\n" << "minimum neighbors is: " << minFriends << "\n";

  		cout << "points in cloud before filtering: " << cloudin->size() << "\n";

  		/* Create the filtering object */
		pcl::VoxelGrid < pcl::PointXYZ > sor;
		sor.setInputCloud(cloudin);
		sor.setLeafSize(leafSize, leafSize, leafSize);
		sor.filter(*cloud_filtered);

  		cout << (cloudin->size() - cloud_filtered->size()) << " points removed with down sampling.\n";
		val = cloud_filtered->size();

  		/* build the filter */
  		outrem.setInputCloud(cloud_filtered);
  		outrem.setRadiusSearch(radius);
  		outrem.setMinNeighborsInRadius(minFriends);

  		// apply filter
  		outrem.filter (*cloud_filtered);

  		cout << (val - cloud_filtered->size()) << " points removed with outlier removal.\n";

  		cout << "Meshing.\n";

  		// Normal estimation*
  		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
  		pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  		pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
  		tree->setInputCloud (cloud_filtered);
  		n.setInputCloud (cloud_filtered);
  		n.setSearchMethod (tree);
  		n.setKSearch (20);
	  	n.compute (*normals);

	  	// Concatenate the XYZ and normal fields*
	  	pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
	  	pcl::concatenateFields (*cloud_filtered, *normals, *cloud_with_normals);

	  	// Create search tree*
	  	pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
	  	tree2->setInputCloud (cloud_with_normals);

	  	// Initialize objects
	  	pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
	  	pcl::PolygonMesh triangles;
	  	pcl::PolygonMesh Postprocessedmesh;


	  	// Set the maximum distance between connected points (maximum edge length)
	  	gp3.setSearchRadius (20000);

	  	// Set typical values for the parameters
	  	gp3.setMu (2.5);
	  	gp3.setMaximumNearestNeighbors (10000);
	  	gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
	  	gp3.setMinimumAngle(M_PI/18); // 10 degrees
	  	gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
	  	gp3.setNormalConsistency(false);

	  	// Get result
	  	gp3.setInputCloud (cloud_with_normals);
	  	gp3.setSearchMethod (tree2);
	  	gp3.reconstruct (triangles);


	  	// Additional vertex information
	  	std::vector<int> parts = gp3.getPartIDs();
	  	std::vector<int> states = gp3.getPointStates();
	  	Labeledoutput->at(FEMER)->Mesh = triangles;
	  	// Finish
	  	pcl::io::saveVTKFile ("/home/mri/mesh.vtk", Postprocessedmesh);
	  	cout << "Mesh file saved to: /home/mri/mesh.vtk" << "\n";
}
