/*
 * RunAllPCL.cpp
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#include "RunAllPCL.h"

RunAllPCL::RunAllPCL() {
	// TODO Auto-generated constructor stub

}

RunAllPCL::~RunAllPCL() {
	// TODO Auto-generated destructor stub
}

vector<LabeledResults *> * RunAllPCL::Femer(vector<LabeledResults *> * input){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(500);
	results->at(FEMER) = new LabeledResults();
	FemerOperation filter(input, results, 6, 25, 100);
	filter.Megaprocess();
	return results;
}

vector<LabeledResults *> * RunAllPCL::Patella(vector<LabeledResults *> * input){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(500);
	results->at(PATELLA) = new LabeledResults();
	PatellaOperation filter(input, results, 3, 18, 220);
	filter.Megaprocess();
	return results;
}

vector<LabeledResults *> * RunAllPCL::Tibia(vector<LabeledResults *> * input){
	vector<LabeledResults *> * results = new vector<LabeledResults *>(500);
	results->at(TIBIA) = new LabeledResults();
	TibiaOperation filter(input, results, 5, 10, 1);
	filter.Megaprocess();
	return results;
}

