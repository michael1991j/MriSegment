/*
 * FemerOperation.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#include "FemerOperation.h"

FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput) {
    	// TODO Auto-generated constructor stub
	radius = 1;
	minFriends = 1;
	this->Labeledoutput = Labeledoutput;
	this->Labeledinput = Labeledinput;
}

FemerOperation::~FemerOperation() {
	// TODO Auto-generated destructor stub
}

void FemerOperation::Preprocess()
{
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin(Labeledinput->at(BONE)->cloud);
  	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (Labeledoutput->at(FEMER)->cloud);


  pcl::RadiusOutlierRemoval<pcl::PointXYZ> rorfilter (true); // Initializing with true will allow us to extract the removed indices
	// in implementation

pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
// build the filter
outrem.setInputCloud(cloudin);
outrem.setRadiusSearch(radius);
outrem.setMinNeighborsInRadius (minFriends);
// apply filter
outrem.filter (*cloud_filtered);

// print cloud before filter
//displayPointCloud(&cloud);

// print cloud after filter
//displayPointCloud(&cloud_filtered);

}

void FemerOperation::Fuse()
{


}

void FemerOperation::Postprocess()
{


}
