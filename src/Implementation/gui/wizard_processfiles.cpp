#include "wizard_processfiles.h"
#include "ui_wizard_processfiles.h"
#include "processworkerthread.h"


Wizard_processfiles::Wizard_processfiles( MRIOpenCVSettings * settings, vector<MRICommon *> * Imagesets,vector<LabeledResults *> * results,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_processfiles)
{


    this->results = results;
    this->Imagesets = Imagesets;
    this->settings = settings;
    this->toggle = 0;
    ui->setupUi(this);



    ui->progressBar_femers->setValue(0);


    Processworkerthread * A =  new Processworkerthread(FEMER_SAG,settings,Imagesets,results);
    connect(A,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
  //    A->start();

      //Processworkerthread * B =  new Processworkerthread(FEMER_TRAN,settings,Imagesets,results);
      //connect(B,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
      //  B->start();

        Processworkerthread * C =  new Processworkerthread(CARTILAGE_COR,settings,Imagesets,results);
       connect(C,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
       C->start();


          Processworkerthread * D =  new Processworkerthread(PATELLA_TRAN,settings,Imagesets,results);
          connect(D,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
    //        D->start();

            Processworkerthread * E =  new Processworkerthread(TIBA_TRAN,settings,Imagesets,results);
            connect(E,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
     //         E->start();


      std::cout << "hello \n";
}
void Wizard_processfiles::UpdateProgress(int id, int value)
{

    if(id ==FEMER_SAG)
    {
    ui->progressBar_femers->setValue(value);
    }
    else if(id ==FEMER_TRAN)
    {
        ui->progressBar_femert->setValue(value);

    }
    else if(id ==CARTILAGE_COR)
    {
        ui->progressBar_cartc->setValue(value);
    }
    else if(id ==PATELLA_TRAN)
    {
        ui->progressBar_petellat->setValue(value);
    }
    else if(id ==TIBA_TRAN)
    {
        ui->progressBar_tibiat->setValue(value);
    }

    if(id==FEMER)
    {
        ui->progressBar_femur->setValue(value);

    }
    else if(id == CARTILAGE)
    {
        ui->progressBar_cartilage->setValue(value);

    }
    else if(id == TIBIA)
    {
        ui->progressBar_tibia->setValue(value);
    }
    else if(id == PATELLA)
    {
        ui->progressBar_patella->setValue(value);
    }

    emit nextwindow(100);
    this->close();
    if((this->toggle == 0)&&ui->progressBar_femers->value() == 100  &&  ui->progressBar_petellat->value() == 100 && ui->progressBar_tibiat->value() == 100)
    {

std:cout << "this is true\n";
        Processworkerthread * D =  new Processworkerthread(PATELLA,settings,Imagesets,results);
        connect(D,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
        //  D->start();

          Processworkerthread * E =  new Processworkerthread(TIBIA,settings,Imagesets,results);
          connect(E,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
           // E->start();
            Processworkerthread * F =  new Processworkerthread(FEMER,settings,Imagesets,results);
            connect(F,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
           //   F->start();
    this->toggle =1;
            emit nextwindow(100);
            this->close();

    }
    if(ui->progressBar_femur->value() == 100  && ui->progressBar_tibia->value() == 100 && ui->progressBar_patella->value() == 100)
    {

    }

}

Wizard_processfiles::~Wizard_processfiles()
{
    delete ui;
}
