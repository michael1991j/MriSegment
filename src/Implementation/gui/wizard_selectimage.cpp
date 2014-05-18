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

    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"Femer",0.5,1), tr("Select Femer"));
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"patillia",0.5,3),tr("Select Patillia"));
    this->tabWidget->addTab(new Selectregionwidget(settings, Imagesets->at(FATSPGR),"TIBA_TRAN",0.8,3),tr("Select Tiba"));

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
