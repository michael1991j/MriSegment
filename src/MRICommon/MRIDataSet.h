/*
 * MRIDataSet.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRIDATASET_H_
#define MRIDATASET_H_
#include <vector>
#include <string>
#include <iostream>
#include "MRISlice.h"
#include <QThreadPool>
#include <QStringList>
#include "DicomLoader.h"
#include "MRISlice.h"
#include "MRITransformation.h"

using namespace std;
enum InputType {DICOMFILELIST, PRELOADEDFORMAT};

class MRIDataSet {
public:
	MRIDataSet(QStringList * FileList , InputType Types);
	virtual ~MRIDataSet();

	vector<MRISlice *>  * Transversal;
	vector<MRISlice *>  * Sagittal;
	vector<MRISlice *>  * Coronial;

	double DistanceAppart;

	void ToTransversal();
	void ToCorronial();
	void ToSagittal();
        void FreeSagittal();


};

#endif /* MRIDATASET_H_ */
