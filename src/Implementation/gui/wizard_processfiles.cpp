#include "wizard_processfiles.h"
#include "ui_wizard_processfiles.h"

Wizard_processfiles::Wizard_processfiles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_processfiles)
{
    ui->setupUi(this);
}

Wizard_processfiles::~Wizard_processfiles()
{
    delete ui;
}
