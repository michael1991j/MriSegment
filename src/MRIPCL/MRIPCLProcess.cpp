/*
 * MRIPCLProcess.cpp
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#include "MRIPCLProcess.h"
#include "PCLViewer.h"
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>


MRIPCLProcess::MRIPCLProcess() {
	// TODO Auto-generated constructor stub

}

MRIPCLProcess::~MRIPCLProcess() {
	// TODO Auto-generated destructor stub
}

/*
 * Preprocess accepts a pointer of type point cloud format
 * Preprocess runs a nearest neighbor filter on the point cloud and returns
 * a filtered cloud
 */
void Preprocess(pcl::PointCloud<pcl::PointXYZ> *cloud, float radius, int minimumHits) {

  if (*cloud == NULL)
    exit(0);

  // instantiate the output cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

  pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
  // build the filter
  outrem.setInputCloud(cloud);
  outrem.setRadiusSearch(radius);
  outrem.setMinNeighborsInRadius (minimumHits);
  // apply filter
  outrem.filter (*cloud_filtered);

  // print cloud before filter
  displayPointCloud(&cloud);

  // print cloud after filter
  displayPointCloud(&cloud_filtered);
  

}

void Fuse() {

}

void Postprocess() {

}
