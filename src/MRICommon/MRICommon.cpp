/*
 * MRICommon.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRICommon.h"

MRICommon::MRICommon() {
	// TODO Auto-generated constructor stub


}

MRICommon::~MRICommon() {
	// TODO Auto-generated destructor stub
}

void MRICommon::SaveProcessedData()
{
//not implemented yet
}
/*
 * Loads Data into the MRIDataSet
 */
void MRICommon:: LoadImages(QStringList *  FileList)
{
  this->Data = new MRIDataSet(FileList, DICOMFILELIST);

}
