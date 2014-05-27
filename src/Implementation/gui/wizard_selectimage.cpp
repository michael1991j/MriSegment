#include "wizard_selectimage.h"
#include "ui_wizard_selectimage.h"
#include "wizardcontroller.h"
#include "selectregionwidget.h"
wizard_selectimage::wizard_selectimage(MRIOpenCVSettings *settings,vector<MRICommon *> * Imagesets, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wizard_selectimage)
{
    ui->setupUi(this);
    this->tabWidget = new QTabWidget;
// findbone femer
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATCUBE),"Femer",0.5,1), tr("Select Femur"));

    //findbonepatella

    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"patillia",0.5,3),tr("Select Patella"));
   //FindBoneTibia
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"TIBA_TRAN",0.8,3),tr("Select Tibia"));
    //findCartilage
     this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"TIBA_TRAN",0.8,3),tr("Select Tibia"));

    //
    this->tabWidget->setMinimumHeight(500);
    ui->formLayout->addWidget(this->tabWidget);


}

wizard_selectimage::~wizard_selectimage()
{
    delete ui;
}

void wizard_selectimage::on_pushButton_clicked()
{
if(this->tabWidget->count()-1 == this->tabWidget->currentIndex())
{
 emit nextwindow(PROCESS);
 this->close();
}
else
{
    this->tabWidget->setCurrentIndex(this->tabWidget->currentIndex()+1);
}


}
