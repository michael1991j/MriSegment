#include "wizard_loadimages.h"
#include "ui_wizard_loadimages.h"
#include <QFileDialog>
#include "wizardcontroller.h"
#include <MRICommon.h>
#include <MRIProcess.h>



Wizard_Loadimages::Wizard_Loadimages(MRIOpenCVSettings *settings,vector<MRICommon *> * Imagesets,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_Loadimages)
{
    this->Imagesets = Imagesets;
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
void Wizard_Loadimages::UpdateProgress(int id, int value)
{
    if(id == 10)
    {
    ui->progressBar_cubef->setValue(value);
    }
    else if(id ==11)
    {
        ui->progressBar_spgrf->setValue(value);

    }
    else if(id == 12)
    {
        ui->progressBar_cubew->setValue(value);

    }
    else if(id == 13)
    {
        ui->progressBar_SPGRW->setValue(value);

    }

    if(ui->progressBar_SPGRW->value() == 100 &&  ui->progressBar_cubew->value() == 100 &&   ui->progressBar_spgrf->value() == 100 && ui->progressBar_cubef->value() == 100 )
    {
        emit nextwindow(SELECTREGION);
        this->close();

    }
}

void Wizard_Loadimages::on_pushButton_clicked()
{
    ui->progressBar_cubef->setValue(0);
    ui->progressBar_spgrf->setValue(100);
    ui->progressBar_cubew->setValue(0);
    ui->progressBar_SPGRW->setValue(100);

    LoadWorkerthread * t =  new LoadWorkerthread(Imagesets->at(FATCUBE), ui->lineEdit_cubef->text(), 10,true,false);
    connect(t,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
      t->start();

      LoadWorkerthread * b =  new LoadWorkerthread(Imagesets->at(FATSPGR), ui->lineEdit_spgrf->text(), 11,false ,true);
      connect(b,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
       //b->start();

        LoadWorkerthread * c =  new LoadWorkerthread(Imagesets->at(WATERCUBE), ui->lineEdit_cubew->text(), 12, true,false);
        connect(c,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
        c->start();

          LoadWorkerthread * d =  new LoadWorkerthread(Imagesets->at(WATERSPGR), ui->lineEdit_spgrw->text(), 13 ,false , true);
          connect(d,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
          //d->start();
      std::cout << "hello \n";


//
}

void Wizard_Loadimages::on_Load_SPGR_button_SPGRW_clicked()
{
    ui->lineEdit_spgrw->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks));
}

void Wizard_Loadimages::on_pushButton_spgrf_clicked()
{
    ui->lineEdit_spgrf->setText(  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks));
}
