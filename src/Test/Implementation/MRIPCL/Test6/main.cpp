/*
 * main.cpp
 *
 *  Created on: May 12, 2014
 *      Author: mri
 */
#include <JustPlotPlease.h>
#include <MRIPCLProcess.h>
#include <FindCartilage.h>
#include <CartilageOperation.h>
#include <LabeledResults.h>
#include <vector>
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>
#include <MRIProcess.h>
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
	               QDir directory("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/005-IdealSPGR-Water-1P5MM/");
	               QStringList files = directory.entryList(nameFilter);
	               for(int i = 0; i <  files.count(); i++)
	                   files[i]=QString("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/005-IdealSPGR-Water-1P5MM/")+files[i];


	               QDir dir("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/500-IdealSPGR-Fat-1P5MM/");
	               QStringList filesfat = dir.entryList(nameFilter);
	               for(int i = 0; i <  filesfat.count(); i++)
	                   filesfat[i]=QString("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/500-IdealSPGR-Fat-1P5MM/")+filesfat[i];

	    	MRICommon * fat = new MRICommon();
	    	fat->LoadImages(&filesfat);
	    	//fat->Data->ToTransversal();
	    	fat->Data->ToCorronial();




	    	MRICommon * water = new MRICommon();
	       	water->LoadImages(&files);
	       	//water->Data->ToTransversal();
	       	water->Data->ToCorronial();

	    	vector<MRICommon *> Imagesets(500);
	    	Imagesets.at(FATSPGR)= fat;
	    	Imagesets.at(WATERSPGR)= water;
	     	vector<LabeledResults *> results(400);
	     	vector<LabeledResults *> qresults(400);

	     	results.at(CARTILAGE_COR) = new LabeledResults();
	    	///blur( img, img, Size(3,3) );
	 	  QThreadPool *threadPool = QThreadPool::globalInstance();

	    	for(int i  =0; i < fat->Data->Coronial->size(); i++) {
	    		cout << "processing image: " << i<<"\n";
	    		FindCartilage * process = new FindCartilage(&Imagesets,&results,i,config);
	    		process->Setup();
	    		process->Preprocess();
	    		process->Segment();
	    		process->PostSegmentProcess();
	    		process->Label();

	    	}

	    	results.at(CARTILAGE) = new LabeledResults();

	    	CartilageOperation filter(&results, &results, 5, 25, 120);
		filter.Preprocess();
		filter.Tomesh();

	    		    	cout << "I hate bugs\n";
	    		    	return 0;
}


