#include "wizard_loadimages.h"
#include "ui_wizard_loadimages.h"
#include <QFileDialog>
#include "wizardcontroller.h"

Wizard_Loadimages::Wizard_Loadimages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_Loadimages)
{
    ui->setupUi(this);
}

Wizard_Loadimages::~Wizard_Loadimages()
{
    delete ui;
}

void Wizard_Loadimages::on_Load_SPGR_button_clicked()
{
    ui->lineEdit_spgr->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks));
}

void Wizard_Loadimages::on_Load_wcube_button_clicked()
{
    ui->lineEdit_cubew->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks));
}

void Wizard_Loadimages::on_Load_fcube_button_clicked()
{
    ui->lineEdit_cubef->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks));
}

void Wizard_Loadimages::on_pushButton_clicked()
{
    emit nextwindow(SELECTREGION);
    this->close();
}
