/*
 * MRICommon.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRICOMMON_H_
#define MRICOMMON_H_
#include <vector>
#include <string>
#include <iostream>
#include <QImage>
#include <QThreadPool>
#include "MRIDataSet.h"
#include <QString>


using namespace std;

class MRICommon {
public:
	MRICommon();
	virtual ~MRICommon();
	void SaveProcessedData();
	void LoadImages(QStringList * FileList);
	MRIDataSet * Data;

};

#endif /* MRICOMMON_H_ */
