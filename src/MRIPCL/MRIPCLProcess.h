/*
 * MRIPCLProcess.h
 *
 *  Created on: Apr 30, 2014
 *      Author: mri
 */

#ifndef MRIPCLPROCESS_H_
#define MRIPCLPROCESS_H_

class MRIPCLProcess {
public:
	MRIPCLProcess();
	virtual ~MRIPCLProcess();
	virtual void Preprocess(pcl::PointCloud<pcl::PointXYZ> *cloud, float radius, int minimumHits);
	virtual void Fuse();
	virtual void Postprocess();
};

#endif /* MRIPCLPROCESS_H_ */
