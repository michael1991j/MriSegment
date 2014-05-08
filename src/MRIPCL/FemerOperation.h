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
using namespace std;

class FemerOperation: public MRIPCLProcess {
		float radius;
		int minFriends;
	public:
		FemerOperation (std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput);
		virtual ~FemerOperation();
		std::vector<LabeledResults *> * Labeledinput;
		std::vector<LabeledResults *> * Labeledoutput;
		void Preprocess();
		void Fuse();
		void Postprocess();
};

#endif /* FEMEROPERATION_H_ */
