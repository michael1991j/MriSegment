#ifndef MRISCENE_H
#define MRISCENE_H

#include <QGraphicsScene>

class MriScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MriScene(QWidget *parent = 0);
    QGraphicsRectItem* boxes;
     QPointF * firstmouseloc;
     void  outputregion();
signals:
    

protected:
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );

};

#endif // MRISCENE_H
