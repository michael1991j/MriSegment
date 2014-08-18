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
#include <dataset.h>
enum state{LOADHEADER, SELECTIMAGES, SELECTREGION, PROCESS , LOADOLD ,LOADOLDB};
class wizardController: public QObject
{
       Q_OBJECT
public:
    wizardController();
    Dataset Configuration;
    WizarddataConfig data;
    MRIOpenCVSettings  CVConfig;
    vector<MRICommon *>  * Imagesets;
    vector<LabeledResults *> * results;

public slots:
    void ProcessState(int Nextstate);
signals:
    void Done(int newValue);

};

#endif // WIZARDCONTROLLER_H
