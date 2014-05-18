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

    std::cout << "got here !!\n";
  // this->handel->PlusCloud( this->controller->results->at(FEMER_SAG)->cloud,FEMER_SAG,244,23,0);
   // this->handel->PlusCloud( this->controller->results->at(PATELLA_TRAN)->cloud,PATELLA_TRAN,0,255,0);
    this->handel->PlusCloud( this->controller->results->at(TIBA_TRAN)->cloud,CARTILAGE_COR,0,0,255);


    this->handel->ShowCloud(CARTILAGE_COR , "name");
    //this->handel->ShowCloud(PATELLA_TRAN, "name3");
    //this->handel->ShowCloud(TIBA_TRAN, "name2");

    //this->handel->ShowViewer();
    // Sphere
    vtkSmartPointer<vtkSphereSource> sphereSource =
        vtkSmartPointer<vtkSphereSource>::New();
    sphereSource->Update();
    vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
        vtkSmartPointer<vtkPolyDataMapper>::New();
    sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
    vtkSmartPointer<vtkActor> sphereActor =
        vtkSmartPointer<vtkActor>::New();
    sphereActor->SetMapper(sphereMapper);

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
    vtkSmartPointer<vtkRenderer> leftRenderer =
        vtkSmartPointer<vtkRenderer>::New();
    leftRenderer->AddActor(sphereActor);

    vtkSmartPointer<vtkRenderer> rightRenderer =
        vtkSmartPointer<vtkRenderer>::New();

    // Add Actor to renderer
    rightRenderer->AddActor(cubeActor);
    ui->qvtkWidget->SetRenderWindow( this->handel->viewer->getRenderWindow());
}


tissueviewer::~tissueviewer()
{
    delete ui;
}
