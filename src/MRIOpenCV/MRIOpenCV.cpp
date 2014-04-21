/*
 * MRIOpenCV.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIOpenCV.h"

MRIOpenCV::MRIOpenCV() {
	// TODO Auto-generated constructor stub

}
void MRIOpenCV::RunProcess()
{

for(int i=0; i < this->Processes.size(); i++)
{
MRIProcess * process= this->Processes.front();
this->Processes.pop();
process->Setup();
process->Preprocess();
process->Segment();
process->PostSegmentProcess();
process->Label();
process->PostProcess();
}
}
MRIOpenCV::~MRIOpenCV() {
	// TODO Auto-generated destructor stub
}

