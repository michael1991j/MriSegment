/*
 * RunAllPCL.cpp
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#include "RunAllPCLscripts.h"

RunAllPCLscripts::RunAllPCLscripts() {
	// TODO Auto-generated constructor stub

}

RunAllPCLscripts::~RunAllPCLscripts() {
	// TODO Auto-generated destructor stub
}

void RunAllPCLscripts::Femer(vector<LabeledResults *> * input){
	FemerOperation filter(input, input, 6, 25, 100);
	filter.Megaprocess();
}

void RunAllPCLscripts::Patella(vector<LabeledResults *> * input){
	PatellaOperation filter(input, input, 3, 18, 220);
	filter.Megaprocess();
}

void RunAllPCLscripts::Tibia(vector<LabeledResults *> * input){
	TibiaOperation filter(input, input, 5, 10, 1);
	filter.Megaprocess();
}

