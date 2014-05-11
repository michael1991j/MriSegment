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
#include "FindBoneFemurTrans.h"
#include "FindBonePatella.h"
#include "FindBoneTibia.h"
#include "LabeledResults.h"
#include "FindCartilage.h"

#include "MRIProcess.h"



class RunAll {
public:
	RunAll(MRICommon *  fat_cube, MRICommon *  water_cube, MRICommon *  fat_SPGR, MRICommon *  water_SPGR, MRIOpenCVSettings * config);
	virtual ~RunAll();
	vector<MRICommon *> * Imagesets;

	vector<LabeledResults *> *  RunFemur();
	vector<LabeledResults *> *  RunFemurTrans();
	vector<LabeledResults *> *  RunTibia();
	vector<LabeledResults *> *  RunPatella();
	vector<LabeledResults *> *  RunCartilage();
	MRIOpenCVSettings * config;
};

#endif /* RUNALL_H_ */
