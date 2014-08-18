/*
 * FindBoneFemer.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef FINDBONEFEMER_H_
#define FINDBONEFEMER_H_
#include "MRIProcess.h"
#include "MRIOpenCVSettings.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <Logger.h>

using namespace std;
class FindBoneFemer : public MRIProcess  {
public:
	FindBoneFemer(std::vector< MRICommon *> * ImageStacks , 	std::vector<LabeledResults *> * LabeledOutput, int id, MRIOpenCVSettings *   config);
	virtual ~FindBoneFemer();
	 void Setup();
	 void Preprocess();
	 void Segment();
	 void PostSegmentProcess();
	 void Label();
	 void PostProcess();
private :
	 	 cv::Mat img;
	 	 cv::Mat binary;
	     cv::Mat output;
		 bool inrange( std::vector<cv::Point2i >  * points);
		 void FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs);
		 MRIOpenCVSettings *   config;
		 Logger * handel;

};

#endif /* FINDBONEFEMER_H_ */
