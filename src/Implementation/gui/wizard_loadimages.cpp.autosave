#include "wizard_loadimages.h"
#include "ui_wizard_loadimages.h"
#include <QFileDialog>
#include "wizardcontroller.h"
#include <MRICommon.h>
#include <MRIProcess.h>



Wizard_Loadimages::Wizard_Loadimages(MRIOpenCVSettings *settings,vector<MRICommon *> * Imagesets,Dataset * Configuration,  int next,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_Loadimages)
{
    this->Imagesets = Imagesets;
    ui->setupUi(this);
    this->Configuration = Configuration;

    ui->lineEdit_cubef->setText(  QString::fromAscii(settings->GetSettings("Imagesets","tdcubefat","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_cubew->setText(  QString::fromAscii(settings->GetSettings("Imagesets","tdcubewater","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_spgrf->setText(  QString::fromAscii(settings->GetSettings("Imagesets","spgrfat","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
    ui->lineEdit_spgrw->setText( QString::fromAscii(settings->GetSettings("Imagesets","spgrwater","/home/mri/Dropbox/School/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")));
 this->next = next;
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
        emit nextwindow(this->next);
        this->close();

    }
}

void Wizard_Loadimages::on_pushButton_clicked()
{
    ui->progressBar_cubef->setValue(100);
    ui->progressBar_spgrf->setValue(0);
    ui->progressBar_cubew->setValue(100);
    ui->progressBar_SPGRW->setValue(0);
    Config_MriCommon* fc = new Config_MriCommon();
   fc->id = FATCUBE;
   fc->totran= 1;
   fc->tosag= 1;
   fc->tocor= 1;
   fc->FilePath = ui->lineEdit_cubef->text();

    Configuration->Imagesets->push_back(fc);

    LoadWorkerthread * t =  new LoadWorkerthread(Imagesets->at(FATCUBE), ui->lineEdit_cubef->text(), 10,true,true);
    connect(t,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
     t->run();


     Config_MriCommon* fs = new Config_MriCommon();
    fs->id = FATSPGR;
    fs->totran= 1;
    fs->tosag= 1;
    fs->tocor= 1;
    fs->FilePath = ui->lineEdit_spgrf->text();

     Configuration->Imagesets->push_back(fs);

     LoadWorkerthread * b =  new LoadWorkerthread(Imagesets->at(FATSPGR), ui->lineEdit_spgrf->text(), 11,true ,true);
      connect(b,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
       b->run();
       Config_MriCommon*  wc = new Config_MriCommon();

       wc->id = WATERCUBE;
       wc->totran= 1;
       wc->tosag= 1;
       wc->tocor= 1;
       wc->FilePath = ui->lineEdit_cubew->text();
       Configuration->Imagesets->push_back(wc);

       LoadWorkerthread * c =  new LoadWorkerthread(Imagesets->at(WATERCUBE), ui->lineEdit_cubew->text(), 12, true,true);
        connect(c,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
        c->run();

       Config_MriCommon*  ws = new Config_MriCommon();
        ws->id = WATERSPGR;
        ws->totran= 1;
        ws->tosag= 1;
        ws->tocor= 1;
        ws->FilePath = ui->lineEdit_spgrw->text();
        Configuration->Imagesets->push_back(ws);

        LoadWorkerthread * d =  new LoadWorkerthread(Imagesets->at(WATERSPGR), ui->lineEdit_spgrw->text(), 13 ,true , true);
          connect(d,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
         d->run();
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
