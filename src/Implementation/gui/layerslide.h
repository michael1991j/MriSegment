#ifndef LAYERSLIDE_H
#define LAYERSLIDE_H
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
#include <layerslidewidget.h>

namespace Ui {
class Layerslide;
}

class Layerslide : public QWidget
{
    Q_OBJECT

public:
    Layerslide( wizardController * controller ,QWidget *parent = 0);
   ~Layerslide();
   wizardController * controller;
   JustPlotPlease * handel;
   LayerSlideWidget * sat_scene;
   LayerSlideWidget * cor_scene;
   LayerSlideWidget * tran_scene;
   void run();
private slots:
    void on_treeWidget_clicked(const QModelIndex &index);
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Layerslide *ui;
    void  managecloud();



};

#endif // LAYERSLIDE_H
