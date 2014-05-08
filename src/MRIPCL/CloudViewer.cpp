/*
 * CloudViewer.cpp
 *
 *  Created on: May 7, 2014
 *	Author: Warren Woolsey
 *	Notes:	DO NOT IMPLEMENT INTO FINAL APP, NOT SAFE WITH MULTITHREADED APPLICATIONS
 *		WILL CAUSE SEG FAULT, USE PCL_VISUALIZER ONCE FLANN BUG HAS BEEN RESOLVED
 */

#include "CloudViewer.h"

CloudViewer::CloudViewer() {
	// TODO Auto-generated constructor stub
}

CloudViewer::CloudViewer(std::vector<LabeledResults *> * Labeledinput) {
        // TODO Auto-generated constructor stub
	this->Labeledinput = Labeledinput;
}


CloudViewer::~CloudViewer() {
        // TODO Auto-generated destructor stub
}

void CloudViewer::DisplayCloud () {
	/* instantiate pointer to cloud in */
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin(Labeledinput->at(BONE)->cloud);
	/* instantiate visualization */
	pcl::visualization::CloudViewer viewer ("Point Cloud Display");
  	viewer.showCloud (cloudin);
   	while (!viewer.wasStopped ());
}
