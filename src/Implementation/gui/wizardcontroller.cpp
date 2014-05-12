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
   Wizard_Loadimages *   imagewindow =  new  Wizard_Loadimages();
   connect(imagewindow,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));

   imagewindow->show();
 }
 else if(Nextstate == SELECTREGION)
 {
    wizard_selectimage *  ImageSelect = new wizard_selectimage();
    connect(ImageSelect,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
    ImageSelect->show();
 }
 else if(Nextstate = PROCESS)
 {
     Wizard_processfiles *  Process = new Wizard_processfiles();
     connect(Process,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
     Process->show();

 }

}
