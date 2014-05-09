/*
 * FemerOperation.h
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#ifndef FEMEROPERATION_H_
#define FEMEROPERATION_H_

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

using namespace std;

class FemerOperation: public MRIPCLProcess {
                double leafSize;
                double radius;
                int minFriends;
        public:
                FemerOperation::FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput, double r, int i);
                FemerOperation (std::vector<LabeledResults *> * filtered_target, std::vector<LabeledResults *> * filtered_source, double s);
                virtual ~FemerOperation();
                std::vector<LabeledResults *> * Labeledinput;
                std::vector<LabeledResults *> * Labeledoutput;
                std::vector<LabeledResults *> * filtered_target;
                std::vector<LabeledResults *> * filtered_source;
                void Preprocess();
                void Fuse();
                void Postprocess();
};

#endif /* FEMEROPERATION_H_ */
