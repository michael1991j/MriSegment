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
#include "pcl/kdtree/kdtree_flann.h"
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/voxel_grid.h>
using namespace std;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

int main(int argc, char **argv) {
	MRIOpenCVSettings * config = new MRIOpenCVSettings();
	config->LoadSettings(
			"/home/mri/Build/MriSegment/src/Conf/MRIOpenCV/Default.conf");

	MRICommonSettings * fileconfig = new MRICommonSettings();
	fileconfig->LoadSettings(
			"/home/mri/Build/MriSegment/src/Conf/MRICommon/Default.conf");

	MRIOpenCV * OpencvProcessor = new MRIOpenCV();

	QApplication app(argc, argv);
	QStringList nameFilter("*.dcm");

	char* Fat_Path =
				fileconfig->GetSettings("FindCartilage", "Fat_Path",
						"/home/michaelroberts/Documents/SaikatKnee2012/500-IdealSPGR-Fat-1P5MM/");
	char* Water_Path =
				fileconfig->GetSettings("FindCartilage", "Water_Path",
						"/home/michaelroberts/Documents/SaikatKnee2012/005-IdealSPGR-Water-1P5MM/");
	QDir directory(Fat_Path);
	QStringList files = directory.entryList(nameFilter);
	for (int i = 0; i < files.count(); i++)
		files[i] =
				QString(Fat_Path)+ files[i];

	QDir dir(Water_Path);
	QStringList filesfat = dir.entryList(nameFilter);
	for (int i = 0; i < filesfat.count(); i++)
		filesfat[i] =
				QString(Water_Path)+ filesfat[i];

	MRICommon * fat = new MRICommon();
	fat->LoadImages(&files);
	//fat->Data->ToTransversal();
	fat->Data->ToCorronial();

	MRICommon * water = new MRICommon();
	water->LoadImages(&filesfat);
	water->Data->ToCorronial();

	vector<MRICommon *> Imagesets(500);
	Imagesets.at(WATERSPGR) = water;
	Imagesets.at(FATSPGR) = fat;
	vector<LabeledResults *> results(400);

	results.at(CARTILAGE_COR) = new LabeledResults();
	///blur( img, img, Size(3,3) );
	QThreadPool *threadPool = QThreadPool::globalInstance();

	for (int i = 0; i < water->Data->Coronial->size(); i++) {
		cout << "processing image: " << i << "\n";
		FindCartilage * process = new FindCartilage(&Imagesets, &results, i,
				config);
		process->Setup();
		process->Preprocess();
		process->Segment();
		process->PostSegmentProcess();
		process->PostProcess();

	}
	threadPool->waitForDone();

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudin(results.at(CARTILAGE_COR)->cloud);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(
			new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(
			new pcl::PointCloud<pcl::PointXYZ>);
	// Create the filtering object
	pcl::VoxelGrid < pcl::PointXYZ > sor;
	sor.setInputCloud(cloudin);
	sor.setLeafSize(3, 3, 3);
	sor.filter(*cloud_filtered);

	std::cerr << "PointCloud after filtering: "
			<< cloud_filtered->width * cloud_filtered->height
			<< " data points (" << pcl::getFieldsList(*cloud_filtered) << ").";

	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzrgb(
			new pcl::PointCloud<pcl::PointXYZRGB>);

	copyPointCloud(*cloud_filtered, *cloud_xyzrgb);

	for (size_t i = 0; i < cloud_xyzrgb->points.size(); ++i) {
		cloud_xyzrgb->points[i].r = 255;
	}
	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(
			new pcl::visualization::PCLVisualizer("3D Viewer"));
	viewer->setBackgroundColor(0, 0, 0);
	pcl::visualization::PointCloudColorHandlerRGBField < pcl::PointXYZRGB
			> rgb(cloud_xyzrgb);
	viewer->addPointCloud < pcl::PointXYZRGB
			> (cloud_xyzrgb, rgb, "sample cloud");

	viewer->setPointCloudRenderingProperties(
			pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");

	viewer->addCoordinateSystem(1, 0, 0, 100);

	viewer->initCameraParameters();

	viewer->spin();

	while (!viewer->wasStopped()) {
		double x, y, z, r, b, o;
		cout << "give x y  z \n";
		cin >> x;
		cin >> y;
		cin >> z;

		viewer->setCameraPosition(x, y, z, 0, 0, 0, 0);
		//updateCamera ();

	}

	cout << "done" << endl;

	return 0;
}

