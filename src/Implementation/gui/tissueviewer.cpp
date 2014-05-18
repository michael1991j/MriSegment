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
    this->handel->PlusCloud( this->controller->results->at(TIBIA)->cloud,TIBIA,244,23,0);
    this->handel->PlusCloud( this->controller->results->at(PATELLA)->cloud,PATELLA,0,255,0);
    this->handel->PlusCloud( this->controller->results->at(CARTILAGE)->cloud,CARTILAGE,0,0,255);
    this->handel->PlusCloud( this->controller->results->at(FEMER)->cloud,FEMER,127,127,127);



    this->handel->ShowCloud(CARTILAGE, "name");
    this->handel->ShowCloud(PATELLA, "name3");
    this->handel->ShowCloud(TIBIA, "name2");
    this->handel->ShowCloud(FEMER, "name4");

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
