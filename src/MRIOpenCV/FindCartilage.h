/*
 * FindCartilage.h
 *
 *  Created on: Apr 27, 2014
 *      Author: mri
 */

#ifndef FINDCARTILAGE_H_
#define FINDCARTILAGE_H_
#include "MRIProcess.h"
#include "MRIOpenCVSettings.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
class FindCartilage : public MRIProcess {
public:
	FindCartilage(std::vector< MRICommon *> * ImageStacks , 	std::vector<LabeledResults *> * LabeledOutput, int id, MRIOpenCVSettings * config  );
	virtual ~FindCartilage();
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
};

#endif /* FINDCARTILAGE_H_ */
