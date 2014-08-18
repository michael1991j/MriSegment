#ifndef MRISCENE_H
#define MRISCENE_H

#include <QGraphicsScene>
#include <MRIOpenCVSettings.h>
class MriScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MriScene(string region, MRIOpenCVSettings * setting,QWidget *parent = 0);
    QGraphicsRectItem* boxes;
     QPointF * firstmouseloc;
     void  outputregion();
     MRIOpenCVSettings * setting;
     string region;
signals:


protected:
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );

};

#endif // MRISCENE_H
