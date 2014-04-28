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
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <string>
#include <iostream>
using namespace std;
using namespace cv;
using namespace pcl;
class LabeledResults {
public:
	LabeledResults( );
	virtual ~LabeledResults();
	Vector<Mat *> Result;
	pcl::PointCloud<pcl::PointXYZ> * cloud ;
};

#endif /* LABELEDRESULTS_H_ */
