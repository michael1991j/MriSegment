#include "selectregionwidget.h"
#include "ui_selectregionwidget.h"
#include <MRISlice.h>
#include <MRIDataSet.h>
#include <QImage>
#include <QPixmap>
#include <QGraphicsRectItem>
Selectregionwidget::Selectregionwidget( MRIOpenCVSettings * settings ,MRICommon * Imageset,string region, double ratio, int plane, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Selectregionwidget)
{
    this->region = region;
    this->settings = settings;
    this->Imagesets = Imageset;
    ui->setupUi(this);
    QList<QTreeWidgetItem *> items;
    if(plane == 1)
       this->dataset  = this->Imagesets->Data->Sagittal;
    else if(plane == 2)
        this->dataset  = this->Imagesets->Data->Coronial;
    else if(plane == 3)
       this->dataset  =this->Imagesets->Data->Transversal;

    int x1 = settings->GetSettings(region, "bounding_box_x1", 230);
    int x2 = settings->GetSettings(region, "bounding_box_x2", 270);
    int y1 = settings->GetSettings(region, "bounding_box_y1", 130);
    int y2 = settings->GetSettings(region, "bounding_box_y2", 150);


    for (int i = 0; i < dataset->size(); ++i)
    {
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList( QString::number(i))));
    }
    int index = ratio*dataset->size();
    ui->treeWidget->insertTopLevelItems(0, items);
    ui->treeWidget->setCurrentIndex(ui->treeWidget->model()->index(0,index));
    connect(ui->treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(On_tree_itemclicked()));
    this->scene = new MriScene(region,settings,this);

    cv::Mat a = dataset->at((int ) (index))->Slice;
    a.convertTo(a, CV_8U,0.06);
    QGraphicsPixmapItem * p = scene->addPixmap(QPixmap::fromImage(Mat2QImage(a)));
    ui->graphicsView->setScene(scene);
    this->scene->boxes = new QGraphicsRectItem(x1,y1,x2-x1,y2 -y1);
    this->scene->boxes->setPen(QPen(Qt::red));
    this->scene->addItem( this->scene->boxes);
    ui->graphicsView->scale(1,1);


}
void Selectregionwidget::On_tree_itemclicked()
{
    int rownum  = ui->treeWidget->currentIndex().row();
    scene->clear();//

    cv::Mat a = this->dataset->at(rownum)->Slice;



    a.convertTo(a, CV_8U,0.06);
    QGraphicsPixmapItem * p = scene->addPixmap(QPixmap::fromImage(Mat2QImage(a)));

//    qDebug() << rownum;

}

QImage Selectregionwidget::Mat2QImage(cv::Mat inMat)
{
    switch ( inMat.type() )
          {
             // 8-bit, 4 channel
             case CV_8UC4:
             {
                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

                return image;
             }

             // 8-bit, 3 channel
             case CV_8UC3:
             {
                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

                return image.rgbSwapped();
             }

             // 8-bit, 1 channel
             case CV_8UC1:
             {
                static QVector<QRgb>  sColorTable;

                // only create our color table once
                if ( sColorTable.isEmpty() )
                {
                   for ( int i = 0; i < 256; ++i )
                      sColorTable.push_back( qRgb( i, i, i ) );
                }

                QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

                image.setColorTable( sColorTable );

                return image;
             }

             default:
              //  qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
                break;
          }

          return QImage();
}


Selectregionwidget::~Selectregionwidget()
{
    delete ui;
}
