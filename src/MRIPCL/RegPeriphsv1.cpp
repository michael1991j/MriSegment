/*
 * RegPeriphsv1.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Warren Woolsey
 */

#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>

#include <pcl/io/pcd_io.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>

#include <pcl/features/normal_3d.h>

#include <pcl/registration/icp.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>

#include <pcl/visualization/pcl_visualizer.h>

RegPeriphs::RegPeriphs () {
	// TODO Auto-generated constructor stub
}

RegPeriphs::~RegPeriphs () {
	// TODO Auto-generated destructor stub
}

void downSamplePC (pcl::PointCloud<pcl::PointXYZ> *target) {
  //fill in later
}
