#ifndef TISSUEVIEWER_H
#define TISSUEVIEWER_H
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
namespace Ui {
class tissueviewer;
}

class tissueviewer : public QWidget
{
    Q_OBJECT

public:
     tissueviewer( wizardController * controller ,QWidget *parent = 0);
    ~tissueviewer();
    wizardController * controller;
    JustPlotPlease * handel;
    void run();
private slots:
    void on_treeWidget_clicked(const QModelIndex &index);

private:
    Ui::tissueviewer *ui;
    void  managecloud();

};

#endif // TISSUEVIEWER_H
