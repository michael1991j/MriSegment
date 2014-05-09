/*
 * FemerOperation.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#include "FemerOperation.h"

FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput, double r, int i) {
        // Constructor called for filtering
        leafSize = 0;
        radius = r;
        minFriends = i;
        this->Labeledoutput = Labeledoutput;
        this->Labeledinput = Labeledinput;
}

FemerOperation::FemerOperation(std::vector<LabeledResults *> * filtered_target, std::vector<LabeledResults *> * filtered_source, double s) {
        // Constructor called for registration
        leafSize = s;
        radius = 0;
        minFriends = 0;
        this->filtered_target = filtered_target;
        this->filtered_source = filtered_source;
}

FemerOperation::~FemerOperation() {
	// TODO Auto-generated destructor stub
}

void FemerOperation::Preprocess() {

  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin (Labeledinput->at(BONE)->cloud);
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem (true);
	//pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;

	cout << "Radius outlier filtering.\n" << "radius is: " << radius << "\n" << "minimum neighbors is: " << minFriends << "\n";
	
	cout << "points in cloud before filtering: " << cloudin->size() << "\n";

	// build the filter
	outrem.setInputCloud(cloudin);
	outrem.setRadiusSearch(radius);
	outrem.setMinNeighborsInRadius(minFriends);

	// apply filter
	outrem.filter (*cloudin);

        cout << "points in cloud after filtering: " << cloudin->size() << "\n";
        //cout << "points in cloud after filtering: " << cloud_filtered->size() << "\n";
}

void FemerOperation::Fuse() {

        pcl::PointCloud<pcl::PointXYZ>::Ptr target (filtered_target->at(FEMER)->cloud);
        pcl::PointCloud<pcl::PointXYZ>::Ptr source (filtered_source->at(FEMER)->cloud);

        /* Ensure clouds arent empty */
        if (target.size() == 0)
                PCL_ERROR ("target point cloud is empty, exiting registration.\n");
        else if(source.size() == 0)
                PCL_ERROR ("source point cloud is empty, exiting registration.\n");
        else
                cout << "target size is: " << target.size() << " source size is: " << source.size() << ".\n";

        /* Apply down sampling to increase speed */
        pcl::ApproximateVoxelGrid<pcl::PointXYZ> vox_filter;
        vox_filter.setLeafSize (leafSize, leafSize, leafSize);

        /* Apply filter to the source cloud */
        pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_output (new pcl::PointCloud<pcl::PointXYZ>);
        vox_filter.setInputCloud (source);
        vox_filter.filter (*filtered_output);
        cout << "post filtering source size: " << filtered_output.size() << ".\n";

        /* Initialize normal distribution transform */
        /* epsilon, step, and resolution can be edited to alter the resolution, and accuracy of the registration process */
        pcl::NormalDistributionsTransform<pcl::PointXYZ, pcl::PointXYZ> transform;
        transform.setTransformEpsilon (0.0001);
        transform.setStepSize (0.01);
        transform.setResolution (1.0);
        transform.setMaximumIterations (25);
        transform.setInputSource (filtered_output);
        transform.setInputTarget (target);

        /* May need to use an eigen vector to rotated the point cloud */
        /* if using point clouds from transverse and sagital, one will need to be rotated */
        Eigen::AngleAxisf init_rotation (0.6931, Eigen::Vector3f::UnitZ ());
        Eigen::Translation3f init_translation (1.79387, 0.720047, 0);
        Eigen::Matrix4f init_guess = (init_translation * init_rotation).matrix ();
        pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZ>);
        transform.align (*output_cloud, init_guess);

        cout << "Normal Distributions Transform has converged:" << transform.hasConverged () << " score: " << transform.getFitnessScore () << ".\n";

        /* Perform teh hax */
        pcl::transformPointCloud (*source, *target, transform.getFinalTransformation());

        cout << "michael is gay.\n";
        return;
}

void FemerOperation::Postprocess()
{


}
