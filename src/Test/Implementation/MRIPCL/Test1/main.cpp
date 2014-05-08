#include <iostream>
#include <MRICommon.h>
#include "/home/mri/Build/MriSegment/src/MRIOpenCV/MRIOpenCVSettings.h"
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>
#include <MRIProcess.h>
#include <FindBoneFemer.h>
#include <FindBoneFemurTrans.h>
#include <LabeledResults.h>
#include <sstream>      // std::istringstream
#include <MRIOpenCV.h>
#include <MRIProcess.h>
#include <FemerOperation.h>
#include <MRIPCLProcess.h>
#include <vector>



using namespace std;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

int main(int argc, char **argv) {

	MRIOpenCV * OpencvProcessor = new MRIOpenCV();

	MRIOpenCVSettings * config = new MRIOpenCVSettings();
		config->LoadSettings(
				"/home/mri/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");

        QApplication app (argc, argv);
        QStringList nameFilter("*.dcm");
               QDir directory("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/");
               QStringList files = directory.entryList(nameFilter);
               for(int i = 0; i <  files.count(); i++)
                   files[i]=QString("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")+files[i];


                          QDir dir("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/003-SagittalCube-FatSat/");
                          QStringList filesfat = dir.entryList(nameFilter);
                          for(int i = 0; i <  filesfat.count(); i++)
                        	  filesfat[i]=QString("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/003-SagittalCube-FatSat/")+filesfat[i];


    	MRICommon * fat = new MRICommon();
    	fat->LoadImages(&files);
    	fat->Data->ToTransversal();
    	//fat->Data->ToCorronial();




    	MRICommon * water = new MRICommon();
       	water->LoadImages(&filesfat);
       	water->Data->ToTransversal();

    	vector<MRICommon *> Imagesets(2);
    	Imagesets.at(FATCUBE)= fat;
    	Imagesets.at(WATERCUBE)= water;
     	vector<LabeledResults *> results(400);

     	results.at(BONE) = new LabeledResults();
    	///blur( img, img, Size(3,3) );
 	  QThreadPool *threadPool = QThreadPool::globalInstance();

    	for(int i  =0; i < fat->Data->Transversal->size(); i++) {
    		cout << "processing image: " << i<<"\n";
    		FindBoneFemurTrans * process = new FindBoneFemurTrans(&Imagesets,&results,i,config);
    		process->Setup();
    		process->Preprocess();
    		process->Segment();
    		process->PostSegmentProcess();
   		//process->PostProcess();

    	}
    	vector<LabeledResults *> pointcloudoutput(400);
    	pointcloudoutput.at(FEMER) = new LabeledResults();

    	FemerOperation handel(&results,&pointcloudoutput);
    	handel.Preprocess();

        //CloudViewer viewer(&results);
        //viewer.DisplayCloud();

    	cout << "done" << endl;

    	return 0;
}

