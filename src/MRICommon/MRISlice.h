/*
 * MRISlice.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRISLICE_H_
#define MRISLICE_H_
#include "MRISliceInfo.h"
#include <opencv2/opencv.hpp>

#include <QImage>
#include <string>
#include <iostream>
using namespace std;

class MRISlice {
public:
	MRISlice(cv::Mat  Slice , int Id );
	virtual ~MRISlice( );
	int Id;
	MRISliceInfo MetaData;
	cv::Mat Slice;
	void  SaveImage(string Location , string  Filename , int Type);
	QImage * ToQImage();
};

#endif /* MRISLICE_H_ */
