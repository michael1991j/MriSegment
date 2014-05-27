/*
 * RunAllPCL.cpp
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#include "RunAllPCLscripts.h"

RunAllPCLscripts::RunAllPCLscripts(MRIOpenCVSettings *config) {
	// TODO Auto-generated constructor stub
	this->config = config;
}

RunAllPCLscripts::~RunAllPCLscripts() {
	// TODO Auto-generated destructor stub
}

void RunAllPCLscripts::Femer(vector<LabeledResults *> * input, const char *loc){
	FemerOperation filter(input, input, 6, 25, 100, loc, config);
	filter.Preprocess();
	filter.Tomesh();
}

void RunAllPCLscripts::Patella(vector<LabeledResults *> * input, const char *loc){
	PatellaOperation filter(input, input, 3, 18, 220, loc, config);
	filter.Preprocess();
	filter.Tomesh();
}

void RunAllPCLscripts::Tibia(vector<LabeledResults *> * input, const char *loc){
	TibiaOperation filter(input, input, 5, 10, 1, loc, config);
	filter.Preprocess();
	filter.Tomesh();
}

void RunAllPCLscripts::Cartilage(vector<LabeledResults *> * input, const char *loc){
    	CartilageOperation filter(input, input, 5, 25, 120, loc, config);
    	filter.Preprocess();
    	filter.Tomesh();
}

