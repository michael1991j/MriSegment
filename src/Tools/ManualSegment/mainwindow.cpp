#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "mriscene.h"
#include <sstream>
#include <QGraphicsPixmapItem>

#include <spawn.h>
#include <QFileDialog>

#include <memory>
#include <list>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      this->scene = new MriScene(this);
    this->Manualscene = new  MriManuelScene(this);
    QGraphicsPixmapItem * p = scene->addPixmap(QPixmap("/home/michael/Dropbox/MRI Segmentation/Image Dump/Sagittal/Image_31.jpg"));

    ui->myGraphicsView->setScene(scene);

    ui->myGraphicsView->fitInView(p, Qt::KeepAspectRatio);
    ui->myGraphicsView->scale(25,25);

    ui->ManualGraphicView->setScene(this->Manualscene);
 ui->ManualGraphicView->fitInView(this->Manualscene->sceneRect(), Qt::KeepAspectRatio );



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    this->scene->outputregion();
}
void MainWindow::On_tree_itemclicked()
{
    int rownum  = ui->treeWidget->currentIndex().row();
    this->Manualscene->settagetimage(this->MRIData->Data->Sagittal->at(rownum)->Slice,(Record *)&(this->Datahandel->Records->at(rownum)));

qDebug() << rownum;

}

void MainWindow::on_LoadDirforManual_clicked()
{
QStringList files = QFileDialog::getOpenFileNames(
                           0,
                           "Select one or more files to open",
                           "/home",
                           "Images (*.png *.dcm *.jpg)");
this->MRIData = new MRICommon();
this->Datahandel = new RecordHandel();

this->MRIData->LoadImages(&files);
this->MRIData->Data->ToTransversal();


ui->treeWidget->setColumnCount(1);
QList<QTreeWidgetItem *> items;
for (int i = 0; i < this->MRIData->Data->Sagittal->size(); ++i)
{
      Record r;
      r.Filename =  QString::number(i);
      r.Z =i;
      r.index= i;
      this->Datahandel->Records->append(r);
      QFileInfo fi( QString::number(i));

      items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList( QString::number(i))));
}

ui->treeWidget->insertTopLevelItems(0, items);
ui->treeWidget->setCurrentIndex(ui->treeWidget->model()->index(0,0));
this->Manualscene->settagetimage(this->MRIData->Data->Sagittal->at(0)->Slice,(Record *)&(this->Datahandel->Records->at(0)));
connect(ui->treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(On_tree_itemclicked()));
}

void MainWindow::on_zoomin_clicked()
{
ui->ManualGraphicView->scale(2,2);
}

void MainWindow::on_zoomout_clicked()
{
    ui->ManualGraphicView->scale(0.5,0.5);

}

void MainWindow::on_Clear_clicked()
{
   this->Manualscene->clearpath();
}

void MainWindow::on_outputpcd_clicked()
{
    qDebug() << this->Datahandel->OutputFinalPCDFile();
    ui->textBrowser->setText(this->Datahandel->OutputFinalPCDFile());
}
