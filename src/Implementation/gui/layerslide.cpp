#include "layerslide.h"
#include<wizardcontroller.h>
#include "ui_layerslide.h"
#include<JustPlotPlease.h>

Layerslide::Layerslide(wizardController *controller, QWidget *parent):    QWidget(parent),
    ui(new Ui::Layerslide)
{
    ui->setupUi(this);
    this->controller = controller;



}

void  Layerslide::managecloud()
{
    handel = new JustPlotPlease();
     QTreeWidgetItemIterator it(ui->treeWidget);
 int i = 0;
     while (*it) {
    int rownum  = i++;
    if((*it)->checkState(0))
    {
    if(rownum == 0)
    {
     this->handel->PlusCloud( this->controller->results->at(TIBIA)->cloud,TIBIA,255,0,0);
        this->handel->ShowCloud(TIBIA, "name");

    }
    else if(rownum == 1)
    {
    this->handel->PlusCloud( this->controller->results->at(PATELLA)->cloud,PATELLA,0,255,0);
        this->handel->ShowCloud(PATELLA, "name3");

    }
    else if(rownum == 2)
    {
        this->handel->PlusCloud( this->controller->results->at(CARTILAGE)->cloud,CARTILAGE,0,0,255);
        this->handel->ShowCloud(CARTILAGE, "name2");

    }
    else if(rownum == 3)
    {
        this->handel->PlusCloud( this->controller->results->at(FEMER)->cloud,FEMER,250,0,210);

        this->handel->ShowCloud(FEMER, "name4");

    }
    else if(rownum == 4)
    {
       this->handel->viewer->addPolygonMesh(  this->controller->results->at(TIBIA)->Mesh, "dsf");
        this->handel->viewer->     setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 255, 0, 0 , "dsf");

    }
    else if(rownum == 5)
    {
       this->handel->viewer->addPolygonMesh(  this->controller->results->at(PATELLA)->Mesh, "dsDDf");
        this->handel->viewer->     setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0,255, 0 , "dsDDf");

    }
    else if(rownum == 6)
    {
       this->handel->viewer->addPolygonMesh(  this->controller->results->at(CARTILAGE)->Mesh, "dsD");
        this->handel->viewer->     setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0, 0, 255 , "dsD");



    }
    else if(rownum == 7)
    {
       this->handel->viewer->addPolygonMesh(  this->controller->results->at(FEMER)->Mesh, "dsSDf");
        this->handel->viewer->     setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 255,0,210 , "dsSDf");



    }
    }

    ++it;


}
     this->handel->viewer->setRepresentationToWireframeForAllActors( 	);
     ui->qvtkWidget->SetRenderWindow( this->handel->viewer->getRenderWindow());

}
void Layerslide::run()
{
    vector<layerslidemarker * >  *  markers = new vector<layerslidemarker * > ();

    layerslidemarker * marker = new layerslidemarker() ;
marker->r = 255;
marker->g = 0;
marker->b = 0;
marker->results = this->controller->results->at(CARTILAGE)->cloud;
markers->push_back(marker);
marker = new layerslidemarker() ;
marker->r = 0;
marker->g = 255;
marker->b = 0;
marker->results = this->controller->results->at(FEMER)->cloud;
markers->push_back(marker);
marker = new layerslidemarker() ;
marker->r = 128;
marker->g = 129;
marker->b = 0;
marker->results = this->controller->results->at(PATELLA)->cloud;
markers->push_back(marker);
marker = new layerslidemarker() ;
marker->r = 0;
marker->g = 0;
marker->b = 255;
marker->results = this->controller->results->at(TIBIA)->cloud;
markers->push_back(marker);


    this->cor_scene = new LayerSlideWidget(controller->Imagesets->at(WATERSPGR)->Data->Coronial,2,markers,this);
    this->sat_scene = new LayerSlideWidget(controller->Imagesets->at(FATCUBE)->Data->Sagittal,0, markers,this);
    this->tran_scene= new LayerSlideWidget(controller->Imagesets->at(FATCUBE)->Data->Transversal,1,markers,this);

    ui->graphicsView->setScene(this->cor_scene);
    ui->graphicsView_2->setScene(this->sat_scene);
    ui->graphicsView_3->setScene(this->tran_scene);
    ui->graphicsView->scale(3,3);

    QList<QString> list;
    list.append("Tibia");
    list.append("Patella");
    list.append("Cartilage");
    list.append("Femer");
    list.append("Tibia mesh");
    list.append("Patella mesh");
    list.append("Cartilage mesh");
    list.append("Femer mesh");

    int index = list.size();
    QList<QTreeWidgetItem *> items;

    for (int i = 0; i < list.size(); ++i)
    {
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList( list.at(i))));

          items.at(i)->setFlags(items.at(i)->flags() | Qt::ItemIsUserCheckable);
          items.at(i)->setCheckState(0,Qt::Checked);

    }
    ui->treeWidget->insertTopLevelItems(0, items);
    ui->treeWidget->setCurrentIndex(ui->treeWidget->model()->index(0,index));

managecloud();
}

Layerslide::~Layerslide()
{
    delete ui;
}

void Layerslide::on_treeWidget_clicked(const QModelIndex &index)
{
    managecloud();

}

void Layerslide::on_horizontalSlider_valueChanged(int value)
{
    double cindex =  (((double)value)/1000)*((double)controller->Imagesets->at(WATERSPGR)->Data->Coronial->size());

    double sindex =  (((double)value)/1000)*((double)controller->Imagesets->at(FATCUBE)->Data->Sagittal->size());
    double tindex =   (((double)value)/1000)*((double)controller->Imagesets->at(FATCUBE)->Data->Transversal->size());

    cor_scene->drawRegion(cindex);
    sat_scene->drawRegion(sindex);
    tran_scene->drawRegion(tindex);



}
