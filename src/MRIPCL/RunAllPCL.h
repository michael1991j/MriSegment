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
#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
#include <sstream>
#include <MRIOpenCV.h>

class RunAllPCL {
public:
	RunAllPCL();
	virtual ~RunAllPCL();
	vector<LabeledResults *> * Femer(vector<LabeledResults *> * input);
	vector<LabeledResults *> * Tibia(vector<LabeledResults *> * input);
	vector<LabeledResults *> * Patella(vector<LabeledResults *> * input);
};

#endif /* RunAllPCL_H_ */
