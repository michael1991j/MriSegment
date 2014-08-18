#ifndef MRISCENE_H
#define MRISCENE_H
#include <MRICommon.h>
#include <MRICommonSettings.h>
#include <MRIOpenCVSettings.h>
#include <MRIProcess.h>
#include <LabeledResults.h>
#include <QWidget>
#include "wizardcontroller.h"
#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkQtTableView.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkSmartPointer.h>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <MRICommon.h>
#include <LabeledResults.h>

class layerslidemarker
{
 public:
  int r;
  int g;
  int b;
   pcl::PointCloud<pcl::PointXYZ>  * results;
};
class LayerSlideWidget : public QGraphicsScene
{
    Q_OBJECT
public:
   LayerSlideWidget(vector<MRISlice *> * Imageset, int reference,   vector<layerslidemarker *>  * results ,QWidget *parent = 0);
    int reference;
    QImage Mat2QImage(cv::Mat inMat);
    vector<layerslidemarker *> * results;
    vector<MRISlice *> * Imageset;

    void  drawRegion(double  i   );


signals:




};

#endif // MRISCENE_H
