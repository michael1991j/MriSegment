#include "wizard_loadimages.h"
#include "ui_wizard_loadimages.h"
#include <QFileDialog>
#include "wizardcontroller.h"
#include <MRICommon.h>
#include <MRIProcess.h>
class LoadWorkerthread : public QThread
{
    LoadWorkerthread(MRICommon * stack, QString path , int id )
    {
    }

private:
    QString path;
    MRICommon * stack;
    void run()
    {
        stack->LoadImages();
        emit updatestatusid(id, 40);
        stack->Data->ToCorronial();
        emit updatestatusid(id, 70);
        stack->Data->ToTransversal();
        emit updatestatusid(id, 100);

    }
};



Wizard_Loadimages::Wizard_Loadimages(MRIOpenCVSettings *settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_Loadimages)
{
    ui->setupUi(this);

    ui->lineEdit_cubef->setText(  QString::fromAscii(settings->GetSettings("Imagesets","tdcubefat","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_cubew->setText(  QString::fromAscii(settings->GetSettings("Imagesets","tdcubewater","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_spgrf->setText(  QString::fromAscii(settings->GetSettings("Imagesets","spgrfat","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_spgrw->setText( QString::fromAscii(settings->GetSettings("Imagesets","spgrwater","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));

}

Wizard_Loadimages::~Wizard_Loadimages()
{
    delete ui;
}

void Wizard_Loadimages::on_Load_SPGR_button_clicked()
{
   ui->lineEdit_spgrf->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
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
    LoadWorkerthread a(a, "", 10);
    a.start();



    emit nextwindow(SELECTREGION);
    this->close();
}

void Wizard_Loadimages::on_Load_SPGR_button_SPGRW_clicked()
{
    ui->lineEdit_spgrw->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks));
}
