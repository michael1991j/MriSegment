#ifndef WIZARD_PROCESSFILES_H
#define WIZARD_PROCESSFILES_H

#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
#include <LabeledResults.h>
#include <QDialog>
#include "processworkerthread.h"
#include "dataset.h"
namespace Ui {
class Wizard_processfiles;
}

class Wizard_processfiles : public QDialog
{
    Q_OBJECT

public:
     Wizard_processfiles(MRIOpenCVSettings * settings, vector<MRICommon *> * Imagesets,vector<LabeledResults *> * results,Dataset * Configuration, QWidget *parent = 0);
    ~Wizard_processfiles();
     MRIOpenCVSettings * settings;
     vector<MRICommon *> * Imagesets;
     vector<LabeledResults *> * results;
     Dataset * Configuration;

     int toggle;
private slots:

    void UpdateProgress(int id , int value);
signals:
    void nextwindow(int newValue);

private:
    Ui::Wizard_processfiles *ui;
};

#endif // WIZARD_PROCESSFILES_H
