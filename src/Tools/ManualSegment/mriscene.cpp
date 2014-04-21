#include "mriscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <QMessageBox>
using namespace std;
MriScene::MriScene(QWidget *parent) :
    QGraphicsScene( (QObject *)parent)
{
    boxes =0;
    firstmouseloc=0;
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
