/*
 * MRIDataSet.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "MRIDataSet.h"
#include <QThreadPool>

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

void MRIDataSet::FreeSagittal()
{
  for(int i= 0; i < this->Sagittal->size(); i++)
    {
      this->Sagittal->at(i)->~MRISlice();

    }


}


MRIDataSet::~MRIDataSet() {
	// TODO Auto-generated destructor stub
}


void MRIDataSet::ToTransversal()
{

  int  xmax= this->Sagittal->at(0)->Slice.cols;
  int  ymax=this->Sagittal->at(0)->Slice.rows;
  QThreadPool *threadPool = QThreadPool::globalInstance();

this->Transversal = new vector<MRISlice *>(ymax);
  for(int i = 0; i < ymax; i++)
  {

      this->Transversal->at(i) = new MRISlice( cv::Mat(this->Sagittal->size(),xmax,this->Sagittal->at(0)->Slice.type()), i);
      SagitaltoTransversal   *  instance = new   SagitaltoTransversal(this->Sagittal,this->Transversal ,i );
     threadPool->start(instance);

  }
  threadPool->waitForDone();




	}

void MRIDataSet::ToCorronial()
{

  int  xmax= this->Sagittal->at(0)->Slice.cols;
  int  ymax=this->Sagittal->at(0)->Slice.rows;

this->Coronial = new vector<MRISlice *>(ymax);
QThreadPool *threadPool = QThreadPool::globalInstance();

  for(int i = 0; i < ymax; i++)
  {

      this->Coronial->at(i) = new MRISlice(cv::Mat(xmax,ymax,this->Sagittal->at(0)->Slice.type()), i);
      SagitaltoCorronal   *  instance = new   SagitaltoCorronal(this->Sagittal,this->Coronial ,i );

      threadPool->start(instance);

  }
  threadPool->waitForDone();

  for(int i = 0; i < ymax; i++)
  {
      cv::Rect myROI(0, 10, 100, 100);
      cv::Mat croppedImage =  this->Coronial->at(i)->Slice(myROI);
      this->Coronial->at(i)->Slice.copyTo(croppedImage);
  }

	}
void MRIDataSet::ToSagittal()
{
	}


