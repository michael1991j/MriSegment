#include <iostream>
#include <JustPlotPlease.h>
#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
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
				"/home/michaelroberts/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");
        QApplication app (argc, argv);
        QStringList nameFilter("*.dcm");
               QDir directory(QString::fromAscii(config->GetSettings("Imagesets","tdcubefat","/hoagittalCube-NoFatSat/")));
               QStringList files = directory.entryList(nameFilter);
               for(int i = 0; i <  files.count(); i++)
                   files[i]=QString::fromAscii(config->GetSettings("Imagesets","tdcubefat","/hoagittalCube-NoFatSat/"))+files[i];


                          QDir dir(QString::fromAscii(config->GetSettings("Imagesets","tdcubewater","/hoagittalCube-NoFatSat/")));
                          QStringList filesfat = dir.entryList(nameFilter);
                          for(int i = 0; i <  filesfat.count(); i++)
                        	  filesfat[i]=QString::fromAscii(config->GetSettings("Imagesets","tdcubewater","/hoagittalCube-NoFatSat/"))+filesfat[i];


    	MRICommon * fat = new MRICommon();
    	fat->LoadImages(&files);
    //	fat->Data->ToTransversal();
    	//fat->Data->ToCorronial();




    	MRICommon * water = new MRICommon();
       	water->LoadImages(&filesfat);
     //  	water->Data->ToTransversal();

    	vector<MRICommon *> Imagesets(2);
    	Imagesets.at(FATCUBE)= fat;
    	Imagesets.at(WATERCUBE)= water;
     	vector<LabeledResults *> results(400);

     	results.at(FEMER_SAG) = new LabeledResults();
    	///blur( img, img, Size(3,3) );
 	  QThreadPool *threadPool = QThreadPool::globalInstance();

    	for(int i  =0; i < fat->Data->Sagittal->size(); i++) {
    		cout << "processing image: " << i<<"\n";
    		FindBoneFemer * process = new FindBoneFemer(&Imagesets,&results,i,config);
    		process->Setup();
    		process->Preprocess();
    		process->Segment();
    		process->PostSegmentProcess();
   		    process->PostProcess();

    	}
    	results.at(FEMER) = new LabeledResults();

    	FemerOperation filter(&results, &results, 5,40,100,"test.");
    	filter.Preprocess();

    	cout << "Preprocess finished, displaying point cloud.\n";

    	JustPlotPlease shit;


    	shit.PlusCloud(results.at(FEMER)->cloud, 1, 0xFF, 0, 0);
    	shit.ShowCloud(1,"test");
    	shit.ShowViewer();
           while(1);
    	cout << "done" << endl;

    	return 0;
}

