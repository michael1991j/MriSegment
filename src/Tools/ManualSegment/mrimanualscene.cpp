#include "MRICommon.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <QMessageBox>
#include <QtAlgorithms>
#include "mrimanualscene.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
MriManuelScene::MriManuelScene(QWidget *parent) :
    QGraphicsScene( (QObject *)parent)
{
    this->path =0;
    firstmouseloc=0;
}
void  MriManuelScene::settagetimage(cv::Mat src,Record * r)
{
    this->path =0;

    this->selectedRecord = r;

    QList<QGraphicsItem*> all = items();
    for (int i = 0; i < all.size(); i++)
    {
        QGraphicsItem *gi = all[i];
        if(gi->parentItem()==NULL) {
            delete gi;
        }
    }
    src.convertTo(src, CV_8UC1, 0.09);
    this->update();
    this->addPixmap(QPixmap::fromImage(Mat2QImage(src)));
     if(!r->path.isEmpty())
     {
      path =  this->addPath( this->selectedRecord->path,QPen(Qt::green),QBrush(Qt::green));

     }
     this->update();

}



void MriManuelScene::clearpath()
{

    this->selectedRecord->path = QPainterPath();
    this->removeItem(path);
    this->update();

}

QImage MriManuelScene::Mat2QImage(cv::Mat inMat)
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
                qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
                break;
          }

          return QImage();
}


void MriManuelScene::mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{


        QPointF mouseloc = mouseEvent->scenePos();
        this->selectedRecord->path.addEllipse(mouseloc,1,1);
        if(path == 0)
        {
        path =  this->addPath( this->selectedRecord->path,QPen(Qt::green),QBrush(Qt::green));
        }
        else
        {
         this->removeItem(path);
         path =  this->addPath( this->selectedRecord->path,QPen(Qt::green),QBrush(Qt::green));


        }
  this->update();
   //this->removeItem();

   //this->removeItem();
}

void MriManuelScene::outputregion()
{



}
