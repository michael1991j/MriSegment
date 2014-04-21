/*
 * LabeledResults.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef LABELEDRESULTS_H_
#define LABELEDRESULTS_H_
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace cv;
class LabeledResults {
public:
	LabeledResults(Vector<Mat * > Result );
	virtual ~LabeledResults();
	Vector<Mat *> Result;
};

#endif /* LABELEDRESULTS_H_ */
