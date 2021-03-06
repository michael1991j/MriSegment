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
#include <FindBoneFemer.h>
#include <FindBoneFemurTrans.h>
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
	    	//fat->Data->ToTransversal();
	    	//fat->Data->ToCorronial();




	    	MRICommon * water = new MRICommon();
	       	water->LoadImages(&filesfat);
	       	//water->Data->ToTransversal();

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
	   		//process->PostProcess();

	    	}
	    	results.at(FEMER) = new LabeledResults();
	    	FemerOperation filter(&results, &results, 6, 25, 100, "/home/mri/mesh1.vtk");
	    	filter.Preprocess();
	    	filter.Tomesh();
	    	cout << "I hate bugs\n";
	    	return 0;
}


