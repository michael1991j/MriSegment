/*
 * MRIProcess.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIProcess.h"


//! Destructor for function that runs the image processing algorithms on the loaded image stack.
MRIProcess::~MRIProcess() {
	// TODO Auto-generated destructor stub
}

//! Helper function to run the image processing algorithms on the loaded image stack.
void MRIProcess::run()
{
	this->Setup();
	this->Preprocess();
	this->Segment();
	this->PostSegmentProcess();
	this->Label();
	this->PostProcess();
}

