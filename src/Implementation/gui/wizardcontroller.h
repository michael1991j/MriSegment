#ifndef WIZARDCONTROLLER_H
#define WIZARDCONTROLLER_H
#include "wizarddataconfig.h"
#include "welcomescreen.h"
#include "wizard_loadimages.h"
#include "wizard_selectimage.h"
#include "wizard_processfiles.h"
#include <MRICommon.h>
#include <MRICommonSettings.h>
#include <MRIOpenCVSettings.h>
#include <MRIProcess.h>
#include <LabeledResults.h>

enum state{LOADHEADER, SELECTIMAGES, SELECTREGION, PROCESS};
class wizardController: public QObject
{
       Q_OBJECT
public:
    wizardController();
    WizarddataConfig data;
    MRIOpenCVSettings  CVConfig;
    vector<MRICommon *>  * Imagesets;
    vector<LabeledResults *> * results;

public slots:
    void ProcessState(int Nextstate);


};

#endif // WIZARDCONTROLLER_H
