/*
 * JustPlotPlease.cpp
 *
 *  Created on: May 12, 2014
 *      Author: mri
 */

#include "JustPlotPlease.h"

JustPlotPlease::JustPlotPlease() {
	// TODO Auto-generated constructor stub
	this->viewer = new pcl::visualization::PCLVisualizer ("Point Cloud Viewrzz ;) Hi Chris");
    this->clouds = new std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>(500);

}

JustPlotPlease::~JustPlotPlease() {
	// TODO Auto-generated destructor stub
}

void JustPlotPlease::PlusCloud(pcl::PointCloud<pcl::PointXYZ> * cloudnine, int id, unsigned char r, unsigned char g, unsigned char b) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in(cloudnine);
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzrgb (new pcl::PointCloud<pcl::PointXYZRGB>);
	pcl::copyPointCloud(*cloud_in, *cloud_xyzrgb);
	for (size_t i = 0; i < cloud_xyzrgb->points.size(); ++i) {
			cloud_xyzrgb->points[i].r = r;
			cloud_xyzrgb->points[i].g = g;
			cloud_xyzrgb->points[i].b = b;
	}
	this->clouds->at(id) = cloud_xyzrgb;
}

void JustPlotPlease::ShowCloud(int id, int id2) {
	viewer->setBackgroundColor(0, 0, 0);
	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(this->clouds->at(id));
	viewer->addPointCloud<pcl::PointXYZRGB>((this->clouds->at(id)), rgb, "image");
	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb2(this->clouds->at(id2));
	viewer->addPointCloud<pcl::PointXYZRGB>((this->clouds->at(id2)), rgb2, "image2");

	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "image");
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "image2");

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
	}
}
