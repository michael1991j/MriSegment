/*
 * FindBoneFemer.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef FINDBONEFEMER_H_
#define FINDBONEFEMER_H_
#include "MRIProcess.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
class FindBoneFemer : public MRIProcess  {
public:
	FindBoneFemer(std::vector< MRICommon *> * ImageStacks , 	std::vector<LabeledResults *> * LabeledOutput, int id  );
	virtual ~FindBoneFemer();
	 void Setup();
	 void Preprocess();
	 void Segment();
	 void PostSegmentProcess();
	 void Label();
	 void PostProcess();
private :
	 	 Mat img;
	 	 Mat binary;
	     cv::Mat output;
		 bool inrange( std::vector<cv::Point2i >  * points);
		 void FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs);


};

#endif /* FINDBONEFEMER_H_ */
