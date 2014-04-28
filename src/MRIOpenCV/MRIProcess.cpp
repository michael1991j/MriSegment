/*
 * MRIProcess.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIProcess.h"



MRIProcess::~MRIProcess() {
	// TODO Auto-generated destructor stub
}
void MRIProcess::run()
{
	this->Setup();
	this->Preprocess();
	this->Segment();
	this->PostSegmentProcess();
	this->Label();
	this->PostProcess();
}

