#include "layerslidewidget.h"
#include "MRISlice.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <QMessageBox>
#include <MRIOpenCVSettings.h>
using namespace std;

LayerSlideWidget::LayerSlideWidget(vector<MRISlice *> *Imageset, int reference, vector<layerslidemarker *>  * results, QWidget *parent)
 :
    QGraphicsScene(  (QObject *)parent)
{
    this->reference = reference;
    this->results = results;
    this->Imageset = Imageset;
    cv::Mat img = Imageset->at(0)->Slice;
    img.convertTo(img, CV_8U,0.06);
    this->addPixmap(QPixmap::fromImage(Mat2QImage(img)));

}

QImage LayerSlideWidget::Mat2QImage(cv::Mat inMat)
{
    switch ( inMat.type() )
          {
             // 8-bit, 4 channel
             case CV_8UC4:
             {
                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

                return image;
             }

             // 8-bit, 3 channel
             case CV_8UC3:
             {
                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

                return image.rgbSwapped();
             }

             // 8-bit, 1 channel
             case CV_8UC1:
             {
                static QVector<QRgb>  sColorTable;

                // only create our color table once
                if ( sColorTable.isEmpty() )
                {
                   for ( int i = 0; i < 256; ++i )
                      sColorTable.push_back( qRgb( i, i, i ) );
                }

                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

                image.setColorTable( sColorTable );

                return image;
             }

             default:
              //  qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
                break;
          }

          return QImage();
}



void LayerSlideWidget::drawRegion(double i)
{
this->clear();


    cv::Mat img = Imageset->at(floor(i))->Slice;
    img.convertTo(img, CV_8U,0.06);
    this->addPixmap(QPixmap::fromImage(Mat2QImage(img)));
    pcl::PointCloud<pcl::PointXYZ>::iterator b1;
    for(int u =0; u < this->results->size(); u++)
    {
   pcl::PointCloud<pcl::PointXYZ> * cloudPCL =  this->results->at(u)->results;
   for (b1 = cloudPCL->points.begin(); b1 < cloudPCL->points.end(); b1++)
       {
        double mult = 1;
        if(this->reference == 0)
        {
           if( (((i*mult)-1*mult) < b1->z*mult) && (((i*mult)+1*mult) > b1->z*mult) )
           {
           this->addEllipse(b1->x,b1->y



                            ,1,1,QPen(QColor(this->results->at(u)->r,this->results->at(u)->g,this->results->at(u)->b)));
             //  cout  << "input "<< i << "  x "<< b1->x << "y  "<< b1->y << "z  " << b1->z<< "\n";
           }
       }
    if(this->reference == 0)
    {
       if( (((i*mult)-1*mult) < b1->z*mult) && (((i*mult)+1*mult) > b1->z*mult) )
       {
       this->addEllipse(b1->x,b1->y



                        ,1,1,QPen(QColor(this->results->at(u)->r,this->results->at(u)->g,this->results->at(u)->b)));
         //  cout  << "input "<< i << "  x "<< b1->x << "y  "<< b1->y << "z  " << b1->z<< "\n";
       }

   }
    if(this->reference == 1)
    {
       if( (((i*mult)-1*mult) < b1->y*mult) && (((i*mult)+1*mult) > b1->y*mult) )
       {
       this->addEllipse(b1->x,b1->z



                        ,1,1,QPen(QColor(this->results->at(u)->r,this->results->at(u)->g,this->results->at(u)->b)));
         //  cout  << "input "<< i << "  x "<< b1->x << "y  "<< b1->y << "z  " << b1->z<< "\n";
       }
   }
    if(this->reference == 2)
    {
       if( (((i*mult)-1*mult) < b1->x*mult) && (((i*mult)+1*mult) > b1->x*mult) )
       {
       this->addEllipse(b1->z,b1->y



                        ,1,1,QPen(QColor(this->results->at(u)->r,this->results->at(u)->g,this->results->at(u)->b)));
         //  cout  << "input "<< i << "  x "<< b1->x << "y  "<< b1->y << "z  " << b1->z<< "\n";
       }
   }

    }
}
}
