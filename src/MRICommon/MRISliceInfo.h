/*
 * MRISliceInfo.h
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#ifndef MRISLICEINFO_H_
#define MRISLICEINFO_H_
#include <vector>
#include <iostream>
using namespace std;
class MRISliceInfo {
public:
	MRISliceInfo();
	vector<string> Dicoms;
	virtual ~MRISliceInfo();
};

#endif /* MRISLICEINFO_H_ */
