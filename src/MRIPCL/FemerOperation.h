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
using namespace std;
class FemerOperation: public MRIPCLProcess {
public:
	FemerOperation(std::vector<LabeledResults *> * Labeledinput, std::vector<LabeledResults *> * Labeledoutput);
	virtual ~FemerOperation();
	 void Preprocess();
	 void Fuse();
	 void Postprocess();
};

#endif /* FEMEROPERATION_H_ */
