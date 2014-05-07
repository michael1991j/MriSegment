/*
 * MRIPCLProcess.h
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#ifndef MRIPCLPROCESS_H_
#define MRIPCLPROCESS_H_

using namespace std;

class MRIPCLProcess {

public:
	MRIPCLProcess();
	virtual ~MRIPCLProcess();
	virtual void Preprocess();
	virtual void Fuse();
	virtual void Postprocess();
};

#endif /* MRIPCLPROCESS_H_ */
