#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomescreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->tabWidget = new QTabWidget;

    this->tabWidget->addTab(new tissueviewer(),tr("Feature View"));
    this->tabWidget->addTab(new Layerslide(),tr("Ladder View"));


    this->tabWidget->setMinimumHeight(500);
    ui->formLayout->addWidget(this->tabWidget);

    wizardController * controller = new wizardController();

}

MainWindow::~MainWindow()
{
    delete ui;
}
