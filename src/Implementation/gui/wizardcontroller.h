#ifndef WIZARDCONTROLLER_H
#define WIZARDCONTROLLER_H
#include "wizarddataconfig.h"
#include "welcomescreen.h"
#include "wizard_loadimages.h"
#include "wizard_selectimage.h"
#include "wizard_processfiles.h"
enum state{LOADHEADER, SELECTIMAGES, SELECTREGION, PROCESS};
class wizardController: public QObject
{
       Q_OBJECT
public:
    wizardController();
    WizarddataConfig data;

public slots:
    void ProcessState(int Nextstate);


};

#endif // WIZARDCONTROLLER_H
