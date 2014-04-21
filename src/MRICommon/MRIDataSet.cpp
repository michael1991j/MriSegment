/*
 * MRIDataSet.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIDataSet.h"

MRIDataSet::MRIDataSet(QStringList * FileList , InputType Types) {

  QThreadPool *threadPool = QThreadPool::globalInstance();
  this->Sagittal = new vector<MRISlice *>(FileList->size());

  for(int i=0; i < FileList->size(); i++)
  {
   DicomLoader * instance = new DicomLoader(FileList->at(i).toStdString(),i,Sagittal);
  threadPool->start(instance);

  }
  threadPool->waitForDone();

}

MRIDataSet::~MRIDataSet() {
	// TODO Auto-generated destructor stub
}


void MRIDataSet::ToTransversal()
{

  int  xmax= this->Sagittal->at(0)->Slice.cols;
  int  ymax=this->Sagittal->at(0)->Slice.rows;

this->Transversal = new vector<MRISlice *>(ymax);
  for(int i = 0; i < ymax; i++)
  {

      this->Transversal->at(i) = new MRISlice( Mat(this->Sagittal->size(),xmax,this->Sagittal->at(0)->Slice.type()), i);
  }
  for(int y = 0; y < ymax; y++)
  {
  for(int i = 0; i < this->Sagittal->size(); i++)
  {

      for(int x = 0; x < xmax; x++)
      {
          this->Transversal->at(y)->Slice.at<unsigned short>(i,x) = this->Sagittal->at(i)->Slice.at<unsigned short>(y,x);
      // printf("measurement:%d\n",  this->transversal->at(y).at<int>(x,i)  );
      fflush(stdout);

      }
    }

  }


	}

void MRIDataSet::ToCorronial()
{

  int  xmax= this->Sagittal->at(0)->Slice.cols;
  int  ymax=this->Sagittal->at(0)->Slice.rows;

this->Coronial = new vector<MRISlice *>(ymax);
  for(int i = 0; i < ymax; i++)
  {

      this->Coronial->at(i) = new MRISlice( Mat(xmax,ymax,this->Sagittal->at(0)->Slice.type()), i);
  }
  for(int x = 0; x < xmax; x++)
  {
  for(int i = 0; i < this->Sagittal->size(); i++)
  {

      for(int y = 0; y < ymax; y++)
      {
          this->Coronial->at(x)->Slice.at<unsigned short>(y,i) = this->Sagittal->at(i)->Slice.at<unsigned short>(y,x);
      // printf("measurement:%d\n",  this->transversal->at(y).at<int>(x,i)  );
      fflush(stdout);

      }
    }

  }

	}
void MRIDataSet::ToSagittal()
{
	}