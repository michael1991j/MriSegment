#include "tissueviewer.h"
#include "ui_tissueviewer.h"
#include <JustPlotPlease.h>
tissueviewer::tissueviewer(wizardController * controller, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tissueviewer)
{

    handel = new JustPlotPlease();

    ui->setupUi(this);
    this->controller = controller;
}
void tissueviewer::run()
{
    QList<QString> list;
    list.append("Tibia");
    this->handel->PlusCloud( this->controller->results->at(TIBIA)->cloud,TIBIA,244,23,0);

    list.append("Patella");
    this->handel->PlusCloud( this->controller->results->at(PATELLA)->cloud,PATELLA,0,255,0);

    list.append("Cartilage");
    this->handel->PlusCloud( this->controller->results->at(CARTILAGE)->cloud,CARTILAGE,0,0,255);

    list.append("Femer");
    this->handel->PlusCloud( this->controller->results->at(FEMER)->cloud,FEMER,250,250,210);

    int index = list.size();
    QList<QTreeWidgetItem *> items;

    for (int i = 0; i < list.size(); ++i)
    {
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList( list.at(i))));

          items.at(i)->setFlags(items.at(i)->flags() | Qt::ItemIsUserCheckable);
          items.at(i)->setCheckState(0,Qt::Checked);

    }
    ui->treeWidget->insertTopLevelItems(0, items);
    ui->treeWidget->setCurrentIndex(ui->treeWidget->model()->index(0,index));
    connect(ui->treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(On_tree_itemclicked()));
    vtkSmartPointer< vtkPolyData >  body;
//    pcl::VTKUtils::mesh2vtk(this->controller->results->at(FEMER)->mesh,body);
    this->handel->ShowCloud(CARTILAGE, "name");
    this->handel->ShowCloud(PATELLA, "name3");
    this->handel->ShowCloud(TIBIA, "name2");
    this->handel->ShowCloud(FEMER, "name4");

    //this->handel->ShowViewer();
    // Sphere

    // Cube
    vtkSmartPointer<vtkCubeSource> cubeSource =
        vtkSmartPointer<vtkCubeSource>::New();
    cubeSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    cubeMapper->SetInputConnection(cubeSource->GetOutputPort());
    vtkSmartPointer<vtkActor> cubeActor =
        vtkSmartPointer<vtkActor>::New();
    cubeActor->SetMapper(cubeMapper);

    // VTK Renderer

    vtkSmartPointer<vtkRenderer> rightRenderer =
        vtkSmartPointer<vtkRenderer>::New();

    // Add Actor to renderer
    rightRenderer->AddActor(cubeActor);


    ui->qvtkWidget->SetRenderWindow( this->handel->viewer->getRenderWindow());
}

void tissueviewer::On_tree_itemclicked()
{
    int rownum  = ui->treeWidget->currentIndex().row();
    QTreeWidgetItem  * item =    ui->treeWidget->itemAt(0,rownum);
    if(rownum == 0)
        rownum = TIBIA;
    else if(rownum == 1)
        rownum = PATELLA;
    else if(rownum == 2)
        rownum = CARTILAGE;
    else if(rownum == 3)
        rownum = FEMER;

  if(item->checkState(0) == Qt::Checked)
      this->handel->ShowCloud(rownum,"a");
  else
      this->handel->RemoveCloud(rownum);
//    qDebug() << rownum;

}
tissueviewer::~tissueviewer()
{
    delete ui;
}
