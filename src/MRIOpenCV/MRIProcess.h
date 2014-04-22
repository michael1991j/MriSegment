/*
 * MRIProcess.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRIPROCESS_H_
#define MRIPROCESS_H_
#include <vector>
#include <iostream>
#include "LabeledResults.h"
#include <MRICommon.h>

class MRIProcess {
public:
	 MRIProcess(std::vector<MRICommon *>  ImageStacks ): ImageStacks(ImageStacks) { this->ImageStacks = ImageStacks; } ;
	virtual ~MRIProcess();
	virtual void Setup()
	{  }
	virtual void Preprocess()
	{  }
	virtual void Segment()
	{  }
	virtual void PostSegmentProcess()
	{  }
	virtual void Label()
	{  }
	virtual void PostProcess()
	{  }
	std::vector<MRICommon *> ImageStacks;
	 vector<LabeledResults> LabeledOutput;
};

#endif /* MRIPROCESS_H_ */
