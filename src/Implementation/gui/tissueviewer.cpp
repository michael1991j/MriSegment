#include "tissueviewer.h"
#include "ui_tissueviewer.h"

tissueviewer::tissueviewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tissueviewer)
{
    ui->setupUi(this);
}

tissueviewer::~tissueviewer()
{
    delete ui;
}
