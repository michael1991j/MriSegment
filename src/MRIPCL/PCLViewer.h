
/*
 * PCLViewer.h
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#ifndef PCLVIEWER_H_
#define PCLVIEWER_H_

class PCLViewer {
public:
	PCLViewer();
	virtual ~PCLViewer();
	void viewerOneOff (pcl::visualization::PCLVisualizer& viewer);
	void viewerPsycho (pcl::visualization::PCLVisualizer& viewer);
	void displayPointCloud (pcl::PointCloud<pcl::PointXYZ> *cloud);
};

#endif /* PCLVIEWER_H_ */
