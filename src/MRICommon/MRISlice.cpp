/*
 * MRISlice.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRISlice.h"

MRISlice::MRISlice(Mat  Slice , int Id ) {
	// TODO Auto-generated constructor stub
 this->Id = Id;
 this->Slice =Slice;
}

MRISlice::~MRISlice() {
	// TODO Auto-generated destructor stub
}

void   MRISlice::SaveImage(string Location , string  Filename , int Type)
{

}

QImage * MRISlice::ToQImage()
{

return 0;
}
