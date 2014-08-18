#include "processworkerthread.h"

Processworkerthread::Processworkerthread(int id, MRIOpenCVSettings *settings, vector<MRICommon *> *Imagesets, vector<LabeledResults *> *results)
{
    this->id = id;
    this->settings = settings;
    this->Imagesets = Imagesets;
    this->results = results;
}

void Processworkerthread::run()
{
    RunAll CVrunner(this->Imagesets, this->settings,this->results) ;

    if(id ==FEMER_SAG)
    {
     CVrunner.RunFemur();
    }
    else if(id ==FEMER_TRAN)
    {
     CVrunner.RunFemur();
    }
    else if(id ==CARTILAGE_COR)
    {
    CVrunner.RunCartilage();
    }
    else if(id ==PATELLA_TRAN)
    {
    CVrunner.RunPatella();
    }
    else if(id ==TIBA_TRAN)
    {
     CVrunner.RunTibia();
    }
    RunAllPCLscripts * as  =new RunAllPCLscripts(settings);
    if(id==FEMER)
    {
        cout << this->results->at(FEMER_SAG)->cloud->size() << "hi \n";
    as->Femer(this->results);
    }
    else if(id == CARTILAGE)
    {
    as->Cartilage(this->results);

    }
    else if(id == TIBIA)
    {
    as->Tibia(this->results);
    }
    else if(id == PATELLA)
    {
    as->Patella(this->results);
    }




    emit updatestatusid(id, 100);


}
