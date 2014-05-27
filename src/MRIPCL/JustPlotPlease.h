/*
 * JustPlotPlease.h
 *
 *  Created on: May 12, 2014
 *      Author: mri
 */

#ifndef JustPlotPlease_H_
#define JustPlotPlease_H_
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <LabeledResults.h>
#include <iostream>
#include "MRIPCLProcess.h"
#include <MRIProcess.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/voxel_grid.h>
#include <ctype.h>

class JustPlotPlease {
public:
	JustPlotPlease();
	virtual ~JustPlotPlease();
	void PlusCloud(pcl::PointCloud<pcl::PointXYZ> * cloudnine, int id, unsigned char r, unsigned char g, unsigned char b);
	void ShowCloud(int id, char *  name);

	void ShowViewer();
	void RemoveCloud( int id);
	pcl::visualization::PCLVisualizer * viewer;
	std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> * clouds;
};

#endif /* JustPlotPlease_H_ */
