#include "mricommon.h"
#include <iostream>

using namespace std;
MriCommon::MriCommon()
{
    cout << "this is a test";
}

void MriCommon::Loadmodel()
{

}
void MriCommon::Savemodel()
{

}


void MriCommon::LoadImages(QStringList * list)
{


        QThreadPool *threadPool = QThreadPool::globalInstance();

    this->sagtical = new vector<Mat>(list->size());
    for(int i=0; i < list->size(); i++)
    {
        DicomtoMat * instance = new DicomtoMat(i,list->at(i).toStdString(),this->sagtical);
        threadPool->start(instance);

    }
    threadPool->waitForDone();


}

void MriCommon::ToTransversal()
{

    int  xmax= this->sagtical->at(0).cols;
    int  ymax=this->sagtical->at(0).rows;

this->transversal = new vector<Mat>(ymax);
    for(int i = 0; i < ymax; i++)
    {

        this->transversal->at(i) = Mat(this->sagtical->at(0).cols,this->sagtical->size(),this->sagtical->at(0).type());
    }
    for(int y = 0; y < ymax; y++)
    {
    for(int i = 0; i < this->sagtical->size(); i++)
    {

        for(int x = 0; x < xmax; x++)
        {
            this->transversal->at(y).at<unsigned char>(x,i) = this->sagtical->at(i).at<unsigned char>(y,x);
        // printf("measurement:%d\n",  this->transversal->at(y).at<int>(x,i)  );
        fflush(stdout);

        }
      }

    }


}


void MriCommon::processDicom(char * path)
{



}
