#include "mriscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <QMessageBox>
#include <MRIOpenCVSettings.h>
using namespace std;
MriScene::MriScene(string region, MRIOpenCVSettings * setting,QWidget *parent) :
    QGraphicsScene(  (QObject *)parent)
{
    boxes =0;
    firstmouseloc=0;
    this->region = region;
    this->setting = setting;
}



void MriScene::mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent )
{

    if(firstmouseloc == 0)
    {
        firstmouseloc = (QPointF *) malloc(sizeof(QPointF));
         QPointF a = (mouseEvent->scenePos());
        memcpy(firstmouseloc, &a,sizeof(QPointF));
    }
     else
    {
        QPointF mouseloc = mouseEvent->scenePos();

        if(boxes == 0)
        {
    boxes = new QGraphicsRectItem(firstmouseloc->x(),firstmouseloc->y(),mouseloc.x()-firstmouseloc->x(), mouseloc.y()-firstmouseloc->y());
       boxes->setPen(QPen(Qt::red));
        this->addItem(boxes);
        }
        else
        {

        boxes->setRect(firstmouseloc->x(),firstmouseloc->y(),mouseloc.x()-firstmouseloc->x(), mouseloc.y()-firstmouseloc->y());


        int x1 = setting->GetSettings(region, "bounding_box_x1", 230);
        int x2 = setting->GetSettings(region, "bounding_box_x2", 270);
        int y1 = setting->GetSettings(region, "bounding_box_y1", 130);
        int y2 = setting->GetSettings(region, "bounding_box_y2", 150);
        cout << x1  <<" x2 " <<  x2 << "y1 "<< y1 << "y2 " << y2<<"\n";

                cout << firstmouseloc->x()  <<" x2 " <<   mouseloc.x() << "y1 "<<firstmouseloc->y() << "y2 " << mouseloc.y()<<"\n";
             this->setting->table->at(region)->at("bounding_box_x1")= QString::number(firstmouseloc->x()).toStdString();
            this->setting->table->at(region)->at("bounding_box_x2")=  QString::number(mouseloc.x()).toStdString();
            this->setting->table->at(region)->at("bounding_box_y1")=  QString::number(firstmouseloc->y()).toStdString();
            this->setting->table->at(region)->at("bounding_box_y2")=   QString::number(mouseloc.y()).toStdString();


        this->update();

        }

       }

  this->update();
   //this->removeItem();

   //this->removeItem();
}

void MriScene::outputregion()
{

    qreal      W, H , x,y;

    boxes->rect().getRect(&x,&y,&W,&H);
    QMessageBox msgBox;
    msgBox.setText(" hey this is the box at  x:" + QString::number(x) +  " y: "+  QString::number(y)+ " width: "+  QString::number(W)+ "  hieght:"+  QString::number(H) );
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
      case QMessageBox::Save:
          // Save was clicked
          break;
      case QMessageBox::Discard:
          // Don't Save was clicked
          break;
      case QMessageBox::Cancel:
          // Cancel was clicked
          break;
      default:
          // should never be reached
          break;
    }

}
