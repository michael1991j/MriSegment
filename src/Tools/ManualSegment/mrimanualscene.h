#ifndef MRIMANUALSCENE_H
#define MRIMANUALSCENE_H
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <cstring>
#include <QMessageBox>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;
#include <QGraphicsScene>
#include "record.h"
class MriManuelScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MriManuelScene(QWidget *parent = 0);
     QGraphicsPathItem * path;
     QPointF * firstmouseloc;
     void  outputregion();
     QImage Mat2QImage(cv::Mat src);
     Record * selectedRecord;
     void  settagetimage(cv::Mat src, Record * r);
     void  zoomout();
     void  zoomin();
     void  clearpath();

signals:


protected:
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );

};

#endif // MRISCENE_H
