/*
 * CartilageOperation.h
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#ifndef CartilageOperation_H_
#define CartilageOperation_H_

#include <LabeledResults.h>
#include <vector>
#include <iostream>
#include "MRIPCLProcess.h"
#include <MRIProcess.h>
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

using namespace std;

class CartilageOperation: public MRIPCLProcess {
    double leafSize;
    double radius;
    int minFriends;
public:
	CartilageOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput, double s, double r, int i, const char *loc);
	virtual ~CartilageOperation();
	const char *loc;
    std::vector<LabeledResults *> * Labeledinput;
    std::vector<LabeledResults *> * Labeledoutput;
	void Preprocess();
	void Fuse();
	void Postprocess();
	void Tomesh();
	void Megaprocess();
};

#endif /* CartilageOperation_H_ */
