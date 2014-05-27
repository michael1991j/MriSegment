/*
 * MRIOpenCV.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIOpenCV.h"

//! Constructor for function that initiates the image processing algorithms.
MRIOpenCV::MRIOpenCV() {
	// TODO Auto-generated constructor stub
 this->Processes = new queue<MRIProcess *>();
}

//! Helper function that initiates the image processing algorithms.
void MRIOpenCV::RunProcess()
{

QThreadPool *threadPool = QThreadPool::globalInstance();
for(int i=0; i < this->Processes->size(); i++){
	cout <<  this->Processes->size();
	MRIProcess * process= this->Processes->front();
	this->Processes->pop();
	process->run();
//threadPool->start(process);
	}
threadPool->waitForDone();
}

//! Destructor for function that initiates the image processing algorithms.
MRIOpenCV::~MRIOpenCV() {
	// TODO Auto-generated destructor stub
}

