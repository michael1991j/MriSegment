/*
 * RunAllPCL.h
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#ifndef RUNALLPCL_H_
#define RUNALLPCL_H_

#include "JustPlotPlease.h"
#include "MRIPCLProcess.h"
#include "FemerOperation.h"
#include "TibiaOperation.h"
#include "PatellaOperation.h"
#include "CartilageOperation.h"
#include <LabeledResults.h>
#include <vector>
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>
#include <MRIProcess.h>
#include <FindBoneFemer.h>
#include <FindBonePatella.h>
#include <FindBoneTibia.h>
#include <FindCartilage.h>
#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
#include <sstream>
#include <MRIOpenCV.h>

class RunAllPCLscripts {
public:
	RunAllPCLscripts(MRIOpenCVSettings *config);
	virtual ~RunAllPCLscripts();
	void  Femer(vector<LabeledResults *> * input, const char *loc);
	void  Tibia(vector<LabeledResults *> * input, const char *loc);
	void  Patella(vector<LabeledResults *> * input, const char *loc);
	void  Cartilage(vector<LabeledResults *> * input, const char *loc);
	MRIOpenCVSettings *config;
};

#endif /* RunAllPCL_H_ */
