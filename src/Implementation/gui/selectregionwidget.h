#ifndef SELECTREGIONWIDGET_H
#define SELECTREGIONWIDGET_H
#include <MRIOpenCVSettings.h>
#include <MRICommon.h>
#include "mriscene.h"
#include <MRISlice.h>
#include <QWidget>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
namespace Ui {
class Selectregionwidget;
}

class Selectregionwidget : public QWidget
{
    Q_OBJECT

public:
     Selectregionwidget( MRIOpenCVSettings * settings ,MRICommon * Imagesets, string region , double ratio,int plane, QWidget *parent = 0);
    ~Selectregionwidget();
     MriScene * scene;
    MRIOpenCVSettings * settings ;
    MRICommon * Imagesets;
    vector<MRISlice * > * dataset;

    QImage Mat2QImage(cv::Mat inMat);
    string region;
    int plane;


public slots:
    void On_tree_itemclicked();

private:
    Ui::Selectregionwidget *ui;
};

#endif // SELECTREGIONWIDGET_H
