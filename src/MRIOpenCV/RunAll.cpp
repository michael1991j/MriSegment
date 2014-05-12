/*
 * RunAll.cpp
 *
 *  Created on: May 11, 2014
 *      Author: mri
 */

#include <vector>
#include "RunAll.h"
#include "MRICommon.h"


RunAll::RunAll(MRICommon *  fat_cube, MRICommon *  water_cube, MRICommon *  fat_SPGR, MRICommon *  water_SPGR, MRIOpenCVSettings * config) {
	// TODO Auto-generated constructor stub
	Imagesets = new vector<MRICommon *>(10);
	Imagesets->at(FATCUBE) = fat_cube;
	Imagesets->at(WATERCUBE) = water_cube;
	Imagesets->at(FATSPGR) = fat_SPGR;
	Imagesets->at(WATERSPGR) = water_SPGR;
	this->config = config;
}

RunAll::~RunAll() {
	// TODO Auto-generated destructor stub
}

vector<LabeledResults *> * RunAll::RunFemur(){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(400);

		results->at(BONE) = new LabeledResults();
		QThreadPool *threadPool = QThreadPool::globalInstance();
		MRICommon * fat = Imagesets->at(FATCUBE);

		for (int i = 0; i < fat->Data->Sagittal->size(); i++) {

			cout << "processing image: " << i << "\n";
			FindBoneFemer * process = new FindBoneFemer(Imagesets, results, i,
					config);
			process->Setup();
			process->Preprocess();
			process->Segment();
			process->PostSegmentProcess();
			process->PostProcess();
		}
	return results;
}


vector<LabeledResults *> * RunAll::RunTibia(){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(400);

		results->at(BONE) = new LabeledResults();
		QThreadPool *threadPool = QThreadPool::globalInstance();
		MRICommon * fat = Imagesets->at(FATCUBE);

		for (int i = 0; i < fat->Data->Transversal->size(); i++) {

			cout << "processing image: " << i << "\n";
			FindBoneTibia * process = new FindBoneTibia(Imagesets, results, i,
					config);
			process->Setup();
			process->Preprocess();
			process->Segment();
			process->PostSegmentProcess();
			process->PostProcess();
		}
	return results;
}

vector<LabeledResults *> * RunAll::RunPatella(){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(400);

		results->at(BONE) = new LabeledResults();
		QThreadPool *threadPool = QThreadPool::globalInstance();
		MRICommon * fat = Imagesets->at(FATCUBE);

		for (int i = 0; i < fat->Data->Transversal->size(); i++) {

			cout << "processing image: " << i << "\n";
			FindBonePatella * process = new FindBonePatella(Imagesets, results, i,
					config);
			process->Setup();
			process->Preprocess();
			process->Segment();
			process->PostSegmentProcess();
			process->PostProcess();
		}
	return results;
}

vector<LabeledResults *> * RunAll::RunCartilage(){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(400);

		results->at(CARTILAGE) = new LabeledResults();
		QThreadPool *threadPool = QThreadPool::globalInstance();
		MRICommon * fat = Imagesets->at(FATSPGR);

		for (int i = 0; i < fat->Data->Coronial->size(); i++) {

			cout << "processing image: " << i << "\n";
			FindCartilage * process = new FindCartilage(Imagesets, results, i,
					config);
			process->Setup();
			process->Preprocess();
			process->Segment();
			process->PostSegmentProcess();
			process->PostProcess();
		}
	return results;
}
