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
using namespace cv;
using namespace std;
class FindBoneFemer : public MRIProcess  {
public:
	FindBoneFemer(std::vector<MRICommon *>  ImageStacks );
	virtual ~FindBoneFemer();
	 void Setup();
	 void Preprocess();
	 void Segment();
	 void PostSegmentProcess();
	 void Label();
	 void PostProcess();

};

#endif /* FINDBONEFEMER_H_ */
