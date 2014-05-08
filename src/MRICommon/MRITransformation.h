/*
 * Transformation.h
 *
 *  Created on: May 4, 2014
 *      Author: mri
 */

#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_
#include "MRISliceInfo.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <string>
#include <iostream>
#include <vector>
#include <QImageWriter>
#include "MRISlice.h"
#include <QRunnable>

using  namespace std;


class SagitaltoCorronal: public QRunnable
{
public:
  vector<MRISlice *>  * input ;
  vector<MRISlice *>  * output;
  int id;
  SagitaltoCorronal( vector<MRISlice *>  * input , vector<MRISlice *>  * output, int id);

  void run();
};

class SagitaltoTransversal: public QRunnable
{
public:
  vector<MRISlice *>  * input ;
    vector<MRISlice *>  * output;
    int id;
  SagitaltoTransversal( vector<MRISlice *>  * input , vector<MRISlice *>  * output, int id);

  void run();
};
#endif /* TRANSFORMATION_H_ */
