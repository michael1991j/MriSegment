/*
 * MRISlice.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRISLICE_H_
#define MRISLICE_H_
#include "MRISliceInfo.h"
#include <cv.h>
#include <QImage>
#include <string>
#include <iostream>
using namespace std;
using namespace cv;

class MRISlice {
public:
	MRISlice(Mat  Slice , int Id );
	virtual ~MRISlice( );
	int Id;
	MRISliceInfo MetaData;
	Mat Slice;
	void  SaveImage(string Location , string  Filename , int Type);
	QImage * ToQImage();
};

#endif /* MRISLICE_H_ */