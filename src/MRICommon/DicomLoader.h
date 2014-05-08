/*
 * DicomLoader.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef DICOMLOADER_H_
#define DICOMLOADER_H_
#include "MRISliceInfo.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <string>
#include <iostream>
#include "gdcmImageReader.h"
#include <vector>
#include <QImageWriter>
#include "MRISlice.h"
#include <QRunnable>

using  namespace std;


class DicomLoader : public QRunnable
{
public:
  DicomLoader(string Loc , int Index , std::vector<MRISlice *> * Targetlist);
  virtual ~DicomLoader();
  int Index;
  std::vector<MRISlice *> * Targetlist;
  string File;
  void run();
};

#endif /* DICOMLOADER_H_ */
