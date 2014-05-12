#include "selectregionwidget.h"
#include "ui_selectregionwidget.h"

Selectregionwidget::Selectregionwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selectregionwidget)
{
    ui->setupUi(this);
}

Selectregionwidget::~Selectregionwidget()
{
    delete ui;
}
