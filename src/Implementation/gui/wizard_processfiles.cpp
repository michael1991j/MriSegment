#include "wizard_processfiles.h"
#include "ui_wizard_processfiles.h"
#include "processworkerthread.h"


Wizard_processfiles::Wizard_processfiles( MRIOpenCVSettings * settings, vector<MRICommon *> * Imagesets,vector<LabeledResults *> * results,Dataset * Configuration,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wizard_processfiles)
{


    this->results = results;
    this->Imagesets = Imagesets;
    this->settings = settings;
    this->toggle = 0;
    this->Configuration = Configuration;
    ui->setupUi(this);


    this->Imagesets->at(FATSPGR)->Data->FreeSagittal();
     this->Imagesets->at(WATERSPGR)->Data->FreeSagittal();


    Processworkerthread * A =  new Processworkerthread(FEMER_SAG,settings,Imagesets,results);
    connect(A,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
    A->start();

      Processworkerthread * B =  new Processworkerthread(FEMER_TRAN,settings,Imagesets,results);
      connect(B,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
       //B->start();

        Processworkerthread * C =  new Processworkerthread(CARTILAGE_COR,settings,Imagesets,results);
       connect(C,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
       C->start();


          Processworkerthread * D =  new Processworkerthread(PATELLA_TRAN,settings,Imagesets,results);
          connect(D,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
           D->start();

            Processworkerthread * E =  new Processworkerthread(TIBA_TRAN,settings,Imagesets,results);
            connect(E,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
             E->start();


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


    if((this->toggle == 0)&&ui->progressBar_femers->value() == 100  &&  ui->progressBar_petellat->value() == 100 && ui->progressBar_tibiat->value() == 100)
    {

std:cout << "this is true\n";
        Config_Labeledcartilage *  P  = new Config_Labeledcartilage();
        P->id = PATELLA;
        P->PCLpath= "Patella.pcd";
        P->VTK= "Patella.vtk";
        this->Configuration->Labels->push_back(P);
        Processworkerthread * D =  new Processworkerthread(PATELLA,settings,Imagesets,results);
        connect(D,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
         D->start();

         Config_Labeledcartilage *  PT  = new Config_Labeledcartilage();
         PT->id = TIBIA;
         PT->PCLpath= "TIBIA.pcl";
         PT->VTK= "TIBIA.vtk";
         this->Configuration->Labels->push_back(PT);

          Processworkerthread * E =  new Processworkerthread(TIBIA,settings,Imagesets,results);
          connect(E,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
          E->start();

          Config_Labeledcartilage *  CE  = new Config_Labeledcartilage();
          CE->id = CARTILAGE;
          CE->PCLpath= "CARTILAGE.pcl";
          CE->VTK= "CARTILAGE.vtk";
          this->Configuration->Labels->push_back(CE);

            Processworkerthread * F =  new Processworkerthread(CARTILAGE,settings,Imagesets,results);
            connect(F,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));

            F->start();
             Config_Labeledcartilage *  Fe  = new Config_Labeledcartilage();
             Fe->id = FEMER;
             Fe->PCLpath= "FEMER.pcd";
             Fe->VTK= "FEMER.vtk";
             this->Configuration->Labels->push_back(Fe);

             Processworkerthread * G =  new Processworkerthread(FEMER,settings,Imagesets,results);
             connect(G,SIGNAL(updatestatusid(int,int)),this,SLOT(UpdateProgress(int,int)));
              G->start();
     this->toggle =1;

        
    }
    if(ui->progressBar_cartilage->value() == 100  && ui->progressBar_tibia->value() == 100 && ui->progressBar_patella->value() == 100 && ui->progressBar_femur->value() == 100)
    {
    emit nextwindow(100);
            this->close();

    }

}

Wizard_processfiles::~Wizard_processfiles()
{
    delete ui;
}
