/*
 * LabeledResults.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "LabeledResults.h"

//! Constructor for function to generate new point cloud.
LabeledResults::LabeledResults() {
	// TODO Auto-generated constructor stub
this->cloud = new pcl::PointCloud<pcl::PointXYZ>();
}

LabeledResults::~LabeledResults() {
	// TODO Auto-generated destructor stub
}

