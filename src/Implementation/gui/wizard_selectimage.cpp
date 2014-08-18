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
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATCUBE),"FindBoneFemer",0.5,1), tr("Select Femur"));

    //findbonepatella  transvers

    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATCUBE),"FindBonePatella",0.38,3),tr("Select Patella"));
   //FindBoneTibia    transvers
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATCUBE),"FindBoneTibia",0.75,3),tr("Select Tibia"));
    //findCartilage corrnial
     this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"FindCartilage",0.5,2),tr("Select Cartilage"));

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
