/*
 * LabeledResults.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef LABELEDRESULTS_H_
#define LABELEDRESULTS_H_
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <string>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/registration/ndt.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/thread/thread.hpp>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/surface/mls.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/io/vtk_io.h>

#include <pcl/point_types.h>

#include <boost/thread/thread.hpp>


#include <pcl/io/vtk_io.h>

using namespace std;
#include <vector>
class LabeledResults {
public:
	LabeledResults( );
	virtual ~LabeledResults();
	std::vector<cv::Mat *> Result;
	pcl::PointCloud<pcl::PointXYZ> * cloud ;
	pcl::PolygonMesh  Mesh;
};

#endif /* LABELEDRESULTS_H_ */
