#include "wizardcontroller.h"
 #include <QDirIterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <pcl/common/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/vtk_lib_io.h>

wizardController::wizardController()
{
    this->Configuration.Imagesets = new  vector<Config_MriCommon *>();
     this->Configuration.Labels = new vector<Config_Labeledcartilage *>();
    WelcomeScreen * window = new WelcomeScreen(&this->Configuration);
    connect(window,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
    window->show();
    Imagesets  = new  vector<MRICommon *> (4);

}
void wizardController::ProcessState(int Nextstate)
{
 if(Nextstate == LOADHEADER)
 {
     Imagesets->at(FATCUBE) = new MRICommon();
     Imagesets->at(WATERCUBE) =new MRICommon();
     Imagesets->at(FATSPGR) =new MRICommon();
     Imagesets->at(WATERSPGR) =new MRICommon();

     this->CVConfig.LoadSettings("/home/michaelroberts/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");
   Wizard_Loadimages *   imagewindow =  new  Wizard_Loadimages(&this->CVConfig,Imagesets, &this->Configuration,SELECTREGION);
   connect(imagewindow,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));

   imagewindow->show();
 }
 else if(Nextstate == SELECTREGION)
 {
    wizard_selectimage *  ImageSelect = new wizard_selectimage(&this->CVConfig,Imagesets);
    connect(ImageSelect,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
    ImageSelect->show();
 }
 else if(Nextstate == PROCESS)
 {

     this->results = new vector<LabeledResults *>(100);
     this->results->at(CARTILAGE) = new LabeledResults();
     this->results->at(FEMER) = new LabeledResults();
     this->results->at(FEMER_SAG) = new LabeledResults();
     this->results->at(FEMER_TRAN) = new LabeledResults();
     this->results->at(CARTILAGE_COR) = new LabeledResults();
     this->results->at(PATELLA_TRAN) = new LabeledResults();
     this->results->at(PATELLA) = new LabeledResults();
     this->results->at(TIBIA) = new LabeledResults();
     this->results->at(TIBA_TRAN) = new LabeledResults();



     Wizard_processfiles *  Process = new Wizard_processfiles(&this->CVConfig,this->Imagesets,this->results,&this->Configuration );
     connect(Process,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));
     Process->show();

 }
 else if(Nextstate == LOADOLD)
 {
     Imagesets->at(FATCUBE) = new MRICommon();
     Imagesets->at(WATERCUBE) =new MRICommon();
     Imagesets->at(FATSPGR) =new MRICommon();
     Imagesets->at(WATERSPGR) =new MRICommon();

     this->CVConfig.LoadSettings("/home/michaelroberts/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");
   Wizard_Loadimages *   imagewindow =  new  Wizard_Loadimages(&this->CVConfig,Imagesets, &this->Configuration,LOADOLDB);
   connect(imagewindow,SIGNAL(nextwindow(int)),this, SLOT(ProcessState(int)));

   imagewindow->show();
 }
   else if(Nextstate == LOADOLDB)
   {
     this->results = new vector<LabeledResults *>(100);
     this->results->at(CARTILAGE) = new LabeledResults();
     this->results->at(FEMER) = new LabeledResults();
     this->results->at(FEMER_SAG) = new LabeledResults();
     this->results->at(FEMER_TRAN) = new LabeledResults();
     this->results->at(CARTILAGE_COR) = new LabeledResults();
     this->results->at(PATELLA_TRAN) = new LabeledResults();
     this->results->at(PATELLA) = new LabeledResults();
     this->results->at(TIBIA) = new LabeledResults();
     this->results->at(TIBA_TRAN) = new LabeledResults();

     for(int i = 0; i< this->Configuration.Labels->size(); i++)
     {
         string path = this->Configuration.destinationpath.toStdString() + "/" +this->Configuration.Labels->at(i)->PCLpath.toStdString();

                 if (pcl::io::loadPCDFile<pcl::PointXYZ> (path , * this->results->at(this->Configuration.Labels->at(i)->id)->cloud) == -1) //* load the file
                 {
                   PCL_ERROR ("Couldn't read the file\n");
                  // return (-1);
                 }
         string path2 = this->Configuration.destinationpath.toStdString() + "/" +this->Configuration.Labels->at(i)->VTK.toStdString();

                 pcl::io::loadPolygonFileVTK 	( path2,  this->results->at(this->Configuration.Labels->at(i)->id)->Mesh);

     }

     emit  Done(100);


 }
 else if(Nextstate == 100)
 {
 this->Configuration.Savetofile(this->Configuration.destinationpath+"/test.xml");

 QDir path = QDir("./tmp");
 QDirIterator iterator(   path , QDirIterator::Subdirectories);
 while (iterator.hasNext()) {
    iterator.next();
    if (!iterator.fileInfo().isDir()) {
       QString filename = iterator.fileName();
       QFile::copy("./tmp/"+filename , this->Configuration.destinationpath + "/"+filename);
    }
 }
  emit  Done(100);
 }

}
