/*
 * FindBoneFemer.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef FINDBONEFEMER_H_
#define FINDBONEFEMER_H_
#include "MRIProcess.h"
class FindBoneFemer : public MRIProcess  {
public:
	FindBoneFemer(std::vector<std::vector<MRICommon *> * >  ImageStacks );
	virtual ~FindBoneFemer();
	virtual void Setup();
	virtual void Preprocess();
	virtual void Segment();
	virtual void PostSegmentProcess();
	virtual void Label();
	virtual void PostProcess();

};

#endif /* FINDBONEFEMER_H_ */
