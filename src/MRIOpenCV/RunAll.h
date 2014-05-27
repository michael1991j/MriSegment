/*
 * RunAll.h
 *
 *  Created on: May 11, 2014
 *      Author: mri
 */

#ifndef RUNALL_H_
#define RUNALL_H_
#include <iostream>
#include <vector>
#include <MRICommon.h>
#include "FindBoneFemer.h"
#include "FindBonePatella.h"
#include "FindBoneTibia.h"
#include "LabeledResults.h"
#include "FindCartilage.h"

#include "MRIProcess.h"



class RunAll {
public:
	RunAll(vector<MRICommon *> * Imagesets, MRIOpenCVSettings * config,vector<LabeledResults *> * results);
	virtual ~RunAll();
	vector<MRICommon *> * Imagesets;

	void  RunFemur();
	void  RunTibia();
	void  RunPatella();
	void RunCartilage();
	vector<LabeledResults *> * results;
	MRIOpenCVSettings * config;
};

#endif /* RUNALL_H_ */
