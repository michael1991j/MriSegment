/*
 * FindBoneTibia.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef FINDBONETibia_H_
#define FINDBONETibia_H_
#include "MRIProcess.h"
#include "MRIOpenCVSettings.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
class FindBoneTibia : public MRIProcess  {
public:
	FindBoneTibia(std::vector< MRICommon *> * ImageStacks , 	std::vector<LabeledResults *> * LabeledOutput, int id, MRIOpenCVSettings * config     );
	virtual ~FindBoneTibia();
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

#endif /* FINDBONETibia_H_ */
