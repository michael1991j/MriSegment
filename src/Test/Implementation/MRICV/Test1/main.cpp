#include <iostream>
#include "MRICommon.h"
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <opencv2/opencv.hpp>

#include <sstream>      // std::istringstream
#include <MRIOpenCV.h>
#include <MRIProcess.h>
#include "FindBoneFemer.h"
#include <vector>

using namespace cv;
using namespace std;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

int main(int argc, char **argv)
{

       MRIOpenCV * OpencvProcessor = new MRIOpenCV();


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
      //  water->LoadImages(&filesfat);

    vector<MRICommon *> Imagesets(2);
    Imagesets.at(0)= fat;
    Imagesets.at(1)= fat;


    ///blur( img, img, Size(3,3) );
    FindBoneFemer * process = new FindBoneFemer(Imagesets);
    //OpencvProcessor->Processes.push(process);
    //OpencvProcessor->RunProcess();





    cout << "done" << endl;


    return 0;
}

