#include "layerslide.h"
#include "ui_layerslide.h"

Layerslide::Layerslide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Layerslide)
{
    ui->setupUi(this);
}

Layerslide::~Layerslide()
{
    delete ui;
}
