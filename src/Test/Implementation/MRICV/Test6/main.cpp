#include <iostream>
#include "MRICommon.h"
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include <QRunnable>
#include <QThreadPool>
#include <opencv2/opencv.hpp>
#include <MRIProcess.h>
#include <FindCartilage.h>
#include <LabeledResults.h>
#include <sstream>      // std::istringstream
#include <MRIOpenCV.h>
#include <MRIProcess.h>
#include <MRIOpenCVSettings.h>
#include <MRICommonSettings.h>

#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/voxel_grid.h>
using namespace cv;
using namespace std;
using namespace pcl;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

int main(int argc, char **argv)
{

       MRIOpenCV * OpencvProcessor = new MRIOpenCV();


       MRIOpenCVSettings *   config = new MRIOpenCVSettings();
       config->LoadSettings( "/home/mri/build/MriSegment/src/Conf/MRIOpenCV/Default.conf");

       cout << config->GetSettings("global","debugmode",10);

    cout << "done" << endl;


    return 0;
}

