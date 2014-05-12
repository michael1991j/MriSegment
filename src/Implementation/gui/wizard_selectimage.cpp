#include "wizard_selectimage.h"
#include "ui_wizard_selectimage.h"
#include "wizardcontroller.h"
#include "selectregionwidget.h"
wizard_selectimage::wizard_selectimage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wizard_selectimage)
{
    ui->setupUi(this);
    this->tabWidget = new QTabWidget;

    this->tabWidget->addTab(new Selectregionwidget(),tr("Dosomething"));
    this->tabWidget->addTab(new Selectregionwidget(),tr("b"));
    this->tabWidget->addTab(new Selectregionwidget(),tr("c"));
    this->tabWidget->addTab(new Selectregionwidget(),tr("d"));

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
