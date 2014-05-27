/*
 * RunAllPCL.cpp
 *
 *  Created on: May 13, 2014
 *      Author: mri
 */

#include "RunAllPCLscripts.h"

RunAllPCLscripts::RunAllPCLscripts() {
	// TODO Auto-generated constructor stub
	this->loc = loc;
}

RunAllPCLscripts::~RunAllPCLscripts() {
	// TODO Auto-generated destructor stub
}

void RunAllPCLscripts::Femer(vector<LabeledResults *> * input){
	FemerOperation filter(input, input, 6, 25, 100, loc);
	filter.Megaprocess();

}

void RunAllPCLscripts::Patella(vector<LabeledResults *> * input){
	PatellaOperation filter(input, input, 3, 18, 220, loc);
	filter.Megaprocess();

}

void RunAllPCLscripts::Tibia(vector<LabeledResults *> * input){
	TibiaOperation filter(input, input, 5, 10, 1, loc);
	filter.Megaprocess();

}

void RunAllPCLscripts::Cartilage(vector<LabeledResults *> * input){
    CartilageOperation filter(input, input, 5, 25, 120, loc);
	filter.Megaprocess();

}

