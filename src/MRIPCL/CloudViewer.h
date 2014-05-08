/*
 * CloudViewer.h
 * 
 *  Created on: May 7, 2014
 *	Author: Warren Woolsey
 */

#ifndef CLOUDVIEWER_H_
#define CLOUDVIEWER_H_
#include <LabeledResults.h>
#include "MRIPCLProcess.h"
#include <MRIProcess.h>
#include <vector>
#include <iostream>
#include <pcl/visualization/cloud_viewer.h>
using namespace std;

class CloudViewer {
	public:
		CloudViewer();
		CloudViewer(std::vector<LabeledResults *> * Labeledinput);				 virtual ~CloudViewer();
		std::vector<LabeledResults *> * Labeledinput;
		void DisplayCloud();
};

#endif /* CLOUDVIEWER_H_ */
