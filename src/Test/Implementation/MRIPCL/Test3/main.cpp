/*
 * main.cpp
 *
 *  Created on: May 12, 2014
 *      Author: mri
 */
#include <JustPlotPlease.h>
#include <MRIPCLProcess.h>
#include <FemerOperation.h>
#include <LabeledResults.h>
#include <vector>
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>
#include <MRIProcess.h>
#include <FindBonePatella.h>
#include <PatellaOperation.h>
#include <MRICommon.h>
#include <MRIOpenCVSettings.h>
#include <sstream>
#include <MRIOpenCV.h>

using namespace std;

int main(int argc, char **argv) {


	MRIOpenCV * OpencvProcessor = new MRIOpenCV();

		MRIOpenCVSettings * config = new MRIOpenCVSettings();
			config->LoadSettings(
					"/home/mri/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");

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
	    	fat->Data->ToTransversal();
	    	//fat->Data->ToCorronial();




	    	MRICommon * water = new MRICommon();
	       	water->LoadImages(&filesfat);
	       	water->Data->ToTransversal();

	    	vector<MRICommon *> Imagesets(2);
	    	Imagesets.at(FATCUBE)= fat;
	    	Imagesets.at(WATERCUBE)= water;
	     	vector<LabeledResults *> results(400);

	     	results.at(PATELLA_TRAN) = new LabeledResults();
	    	///blur( img, img, Size(3,3) );
	 	  QThreadPool *threadPool = QThreadPool::globalInstance();


	    	for(int i  =0; i < fat->Data->Transversal->size(); i++) {
	    		cout << "processing image: " << i<<"\n";
	    		FindBonePatella * process = new FindBonePatella(&Imagesets,&results,i,config);
	    		process->Setup();
	    		process->Preprocess();
	    		process->Segment();
	    		process->PostSegmentProcess();
	    		process->Label();

	    	}
	    	results.at(PATELLA) = new LabeledResults();

	    	PatellaOperation filter(&results, &results, 3, 18, 220);
	    	filter.Megaprocess();
	    	//filter.Fuse();
	    	//filter.Postprocess();

	    	cout << "I hate bugs\n";
	    	return 0;
}

