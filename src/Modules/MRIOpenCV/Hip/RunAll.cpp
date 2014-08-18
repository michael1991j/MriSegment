/*
 * RunAll.cpp
 *
 *  Created on: May 11, 2014
 *      Author: mri
 */

#include <vector>
#include "RunAll.h"
#include "MRICommon.h"


RunAll::RunAll(vector<MRICommon *> * Imagesets, MRIOpenCVSettings * config , vector<LabeledResults *> * results) {
	// TODO Auto-generated constructor stub
	this->Imagesets = Imagesets;
    this-> results = results;
	this->config = config;
}

RunAll::~RunAll() {
	// TODO Auto-generated destructor stub
}

void RunAll::RunFemur(){

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
}


void RunAll::RunTibia(){

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
			process->Label();

			process->PostProcess();
		}
}

void RunAll::RunPatella(){

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
			process->Label();
			process->PostProcess();
		}
}

void RunAll::RunCartilage(){


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
			process->Label();

			process->PostProcess();
		}

}
