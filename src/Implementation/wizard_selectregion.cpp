#include "wizard_selectregion.h"
#include "ui_wizard_selectregion.h"

wizard_selectregion::wizard_selectregion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wizard_selectregion)
{
    ui->setupUi(this);
}

wizard_selectregion::~wizard_selectregion()
{
    delete ui;
}
