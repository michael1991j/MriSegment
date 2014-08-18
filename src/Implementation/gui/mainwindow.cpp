#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomescreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->tabWidget = new QTabWidget;

    this->tabWidget->setMinimumHeight(4000);
    this->tabWidget->setMinimumWidth(4000);

    ui->formLayout->addWidget(this->tabWidget);
controller = new wizardController();
this->viewer = new tissueviewer(controller);
this->controllerlayerslider = new Layerslide(controller);
this->tabWidget->addTab(viewer,tr("Feature View"));
this->tabWidget->addTab(this->controllerlayerslider,tr("Ladder View"));
connect(controller,SIGNAL(Done(int)), this, SLOT(wizardone(int)));

}
void MainWindow:: wizardone(int Nextstate)
{
    std::cout << "got here !!";

this->viewer->run();
this->controllerlayerslider->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
