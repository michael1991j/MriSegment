#include "wizardcontroller.h"

wizardController::wizardController()
{
    WelcomeScreen * window = new WelcomeScreen();
    connect(window,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
    window->show();
}
void wizardController::ProcessState(int Nextstate)
{
 if(Nextstate == LOADHEADER)
 {
     Imagesets  = new  vector<MRICommon *> (4);
     Imagesets->at(FATCUBE) = new MRICommon();
     Imagesets->at(WATERCUBE) =new MRICommon();
     Imagesets->at(FATSPGR) =new MRICommon();
     Imagesets->at(WATERSPGR) =new MRICommon();

     this->CVConfig.LoadSettings("/home/michaelroberts/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");
   Wizard_Loadimages *   imagewindow =  new  Wizard_Loadimages(&this->CVConfig,Imagesets);
   connect(imagewindow,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));

   imagewindow->show();
 }
 else if(Nextstate == SELECTREGION)
 {
    wizard_selectimage *  ImageSelect = new wizard_selectimage(&this->CVConfig,Imagesets);
    connect(ImageSelect,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
    ImageSelect->show();
 }
 else if(Nextstate == PROCESS)
 {

     this->results = new vector<LabeledResults *>(100);
     this->results->at(CARTILAGE) = new LabeledResults();
     this->results->at(FEMER) = new LabeledResults();
     this->results->at(FEMER_SAG) = new LabeledResults();
     this->results->at(FEMER_TRAN) = new LabeledResults();
     this->results->at(CARTILAGE_COR) = new LabeledResults();
     this->results->at(PATELLA_TRAN) = new LabeledResults();
     this->results->at(PATELLA) = new LabeledResults();
     this->results->at(TIBIA) = new LabeledResults();
     this->results->at(TIBA_TRAN) = new LabeledResults();



     Wizard_processfiles *  Process = new Wizard_processfiles(&this->CVConfig,this->Imagesets,this->results );
     connect(Process,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
     Process->show();

 }
 else if(Nextstate == 100)
 {
 emit  Done(100);
 }

}
