/*
 * FemerOperation.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */
#define FLANN_USE_CUDA
#include "FemerOperation.h"
#include "JustPlotPlease.h"

FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput, double s, double r, int i, const char *loc) {
        // Constructor called for filtering
        leafSize = s;
        radius = r;
        minFriends = i;
        this->loc = loc;
        this->Labeledoutput = Labeledoutput;
        this->Labeledinput = Labeledinput;
}

FemerOperation::~FemerOperation() {
	// TODO Auto-generated destructor stub
}

/*
 * Preprocess applies down-sampling radial outlier removal filtering to the post 
 * post processed point cloud
 */
void FemerOperation::Preprocess() {

	/* initialize input and output pointers, and value storage */
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(FEMER_SAG)->cloud);
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud, NullDeleter());
	long val 	= cloudin->size();
	long val1	= 0;

	/* initialize down-sampling filter and apply to cloudin, store output in cloud_filtered */
	cout << "Down-Sampling, number of points before down-sample: " << val << ".\n";
	pcl::VoxelGrid < pcl::PointXYZ > sor;
	sor.setInputCloud(cloudin);
	sor.setLeafSize(leafSize, leafSize, leafSize);
	sor.filter(*cloud_filtered);
	val1 = cloud_filtered->size();
	cout << val - val1 << " points removed in down-sampling.\n";

	/* initialize radius outlier removal filter and apply to cloud_filtered, store output in cloud_filtered. */
	cout << "Radius outlier removal filtering, number of points befor filter: " << val1 << ".\n";
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
	outrem.setInputCloud(cloud_filtered);
	outrem.setRadiusSearch(radius);
	outrem.setMinNeighborsInRadius(minFriends);
	outrem.filter (*cloud_filtered);
	cout << val1 - cloud_filtered->size() << " points removed in radius outlier removal filtering.\n";

	/* status of points removed in during preprocessing */
	cout << val - cloud_filtered->size() << " points removed in preprocessing.\n";
	return;
}

void FemerOperation::Fuse() {
	// Not implemented
	return;
}

void FemerOperation::Postprocess() {
	// Not implemented
	return;
}

/*
 * Tomesh writes the filtered point cloud to a mesh file (.vtk)
 */
void FemerOperation::Tomesh() {
	 /* initialize input pointer */
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud, NullDeleter());

        /* initialize normals point cloud, and KD search trees */
        pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> n;
        pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
        pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
        pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);


        /* implement search tree, and populate normals cloud */
        tree->setInputCloud (cloud_filtered);
        n.setInputCloud (cloud_filtered);
        n.setSearchMethod (tree);
        n.setKSearch (20);
        n.compute (*normals);

        /* concatenate the XYZ and normal fields */
        pcl::concatenateFields (*cloud_filtered, *normals, *cloud_with_normals);

        /* set cloud_with_normals as inpout to second search tree */
        tree2->setInputCloud (cloud_with_normals);

        /* initialize triangulation object */
        pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
        pcl::PolygonMesh triangles;

        /* set triangulation parameters */
        gp3.setSearchRadius (100);
        gp3.setMu (2.5);
        gp3.setMaximumNearestNeighbors (100);
        gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
        gp3.setMinimumAngle(M_PI/18); // 10 degrees
        gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
        gp3.setNormalConsistency(false);

        /* triangulate point cloud */
        gp3.setInputCloud (cloud_with_normals);
        gp3.setSearchMethod (tree2);
        gp3.reconstruct (triangles);
        std::vector<int> parts = gp3.getPartIDs();
        std::vector<int> states = gp3.getPointStates();

        /* save triangulation projection out to a .vtk file */
        Labeledoutput->at(FEMER)->Mesh = triangles;
        pcl::io::saveVTKFile (loc, triangles);
        cout << "Success, meshfile saved to: " << *loc << "\n";
	
	return;
}

void FemerOperation::Megaprocess() {

		long val = 0;
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(FEMER_SAG)->cloud);
  		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud, NullDeleter());
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
	  	//pcl::PolygonMesh Postprocessedmesh;


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
	  	 pcl::PCDWriter writer;
	  	    writer.write<pcl::PointXYZ> ("./tmp/FEMER.pcd", *cloud_filtered, false);
	  	  	// Finish
	  	  	pcl::io::saveVTKFile ("./tmp/FEMER.vtk", triangles);
	  	cout << "Mesh file saved to: /home/mri/mesh.vtk" << "\n";
}
