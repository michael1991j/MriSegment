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
#include <MRISlice.h>
#include <vector>
#include <QRunnable>
#include "MRICommon.h"
using namespace std;

enum ImageType { FATCUBE, WATERCUBE,WATERSPGR  };
enum Tissue { BONE, CARTILAGE,FEMER };

class MRIProcess : public QRunnable {
public:
	 MRIProcess( )  {

		}

	virtual ~MRIProcess();
	 void run();
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
	std::vector< MRICommon *> * ImageStacks;
	std::vector<LabeledResults *> * LabeledOutput;
	int id;
};

#endif /* MRIPROCESS_H_ */
