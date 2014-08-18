#ifndef WIZARD_LOADIMAGES_H
#define WIZARD_LOADIMAGES_H

#include <QDialog>
#include <MRIOpenCVSettings.h>
#include <MRICommon.h>
#include "loadworkerthread.h"
#include <wizardcontroller.h>
#include "dataset.h"
namespace Ui {
class Wizard_Loadimages;
}

class Wizard_Loadimages : public QDialog
{
    Q_OBJECT

public:
     Wizard_Loadimages(MRIOpenCVSettings * settings, vector<MRICommon *> * Imagesets, Dataset * Configuration, int next,QWidget *parent = 0);
    ~Wizard_Loadimages();
     vector<MRICommon *> * Imagesets;
     Dataset * Configuration;
     int next;
signals:
    void nextwindow(int newValue);

private slots:

    void on_Load_wcube_button_clicked();

    void on_Load_fcube_button_clicked();

    void on_pushButton_clicked();

    void on_Load_SPGR_button_SPGRW_clicked();
    void UpdateProgress(int id , int value);



    void on_pushButton_spgrf_clicked();

private:
    Ui::Wizard_Loadimages *ui;
    MRIOpenCVSettings * settings;
};

#endif // WIZARD_LOADIMAGES_H
