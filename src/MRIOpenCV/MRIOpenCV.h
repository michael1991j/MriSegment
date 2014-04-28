/*
 * MRIOpenCV.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRIOPENCV_H_
#define MRIOPENCV_H_
#include <queue>
#include "MRIProcess.h"
#include "FindBoneFemer.h"
using namespace std;
class MRIOpenCV {
public:
	MRIOpenCV();
	virtual ~MRIOpenCV();
	queue<MRIProcess *> * Processes;
	void RunProcess();
};

#endif /* MRIOPENCV_H_ */
