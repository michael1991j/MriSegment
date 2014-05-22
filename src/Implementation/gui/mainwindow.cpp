#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomescreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->tabWidget = new QTabWidget;

    this->tabWidget->setMinimumHeight(1500);
    ui->formLayout->addWidget(this->tabWidget);
controller = new wizardController();
this->viewer = new tissueviewer(controller);
this->tabWidget->addTab(viewer,tr("Feature View"));
this->tabWidget->addTab(new Layerslide(),tr("Ladder View"));
connect(controller,SIGNAL(Done(int)), this, SLOT(wizardone(int)));
}
void MainWindow:: wizardone(int Nextstate)
{
    std::cout << "got here !!";

this->viewer->run();
}

MainWindow::~MainWindow()
{
    delete ui;
}
