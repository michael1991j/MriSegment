/*
 * FindBonePatella.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef FINDBONEPatella_H_
#define FINDBONEPatella_H_
#include "MRIProcess.h"
#include "MRIOpenCVSettings.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
class FindBonePatella : public MRIProcess  {
public:
	FindBonePatella(std::vector< MRICommon *> * ImageStacks , 	std::vector<LabeledResults *> * LabeledOutput, int id, MRIOpenCVSettings * config   );
	virtual ~FindBonePatella();
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
		 MRIOpenCVSettings *   config;

};

#endif /* FINDBONEPatella_H_ */
