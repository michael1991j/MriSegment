/*
 * FemerOperation.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#include "FemerOperation.h"

FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput) {
    	// TODO Auto-generated constructor stub
	radius = 10;
	minFriends = 1;
	this->Labeledoutput = Labeledoutput;
	this->Labeledinput = Labeledinput;
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

void FemerOperation::Fuse()
{


}

void FemerOperation::Postprocess()
{


}
