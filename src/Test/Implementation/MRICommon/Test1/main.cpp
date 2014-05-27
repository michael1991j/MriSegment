#include <iostream>
#include "MRICommon.h"
#include <qfile.h>
#include <qstringlist.h>
#include <qfiledialog.h>
#include <QApplication>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <boost/thread/thread.hpp>
#include <pcl/filters/voxel_grid.h>

#include <sstream>      // std::istringstream
using namespace cv;
using namespace std;
using namespace pcl;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";
void FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs)
{
    blobs.clear();

    // Fill the label_image with the blobs
    // 0  - background
    // 1  - unlabelled foreground
    // 2+ - labelled foreground

    cv::Mat label_image;
    binary.convertTo(label_image, CV_32SC1);

    int label_count = 2; // starts at 2 because 0,1 are used already

    for(int y=0; y < label_image.rows; y++) {
        int *row = (int*)label_image.ptr(y);
        for(int x=0; x < label_image.cols; x++) {
            if(row[x] != 1) {
                continue;
            }

            cv::Rect rect;
            cv::floodFill(label_image, cv::Point(x,y), label_count, &rect, 0, 0, 4);

            std::vector <cv::Point2i> blob;

            for(int i=rect.y; i < (rect.y+rect.height); i++) {
                int *row2 = (int*)label_image.ptr(i);
                for(int j=rect.x; j < (rect.x+rect.width); j++) {
                    if(row2[j] != label_count) {
                        continue;
                    }

                    blob.push_back(cv::Point2i(j,i));
                }
            }

            blobs.push_back(blob);

            label_count++;
        }
    }
}
bool inrange( std::vector<cv::Point2i >  * points)
{

    for(int i =0; i< points->size(); i++)
    {

        if( (points->at(i).x >190)&& (points->at(i).x <305) &&  (points->at(i).y >209) && (points->at(i).y<340))
           return true;
    }
    return false;

}
int main(int argc, char **argv)
{
        QApplication app (argc, argv);
        QStringList nameFilter("*.dcm");
               QDir directory("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat");
               QStringList files = directory.entryList(nameFilter);
               for(int i = 0; i <  files.count(); i++)
                   files[i]=QString("/home/mri/Dropbox/MRI Segmentation/SampleData/SaikatKnee2012/002-SagittalCube-NoFatSat/")+files[i];


    MRICommon * obj = new MRICommon();


    obj->LoadImages(&files);
    //obj->Data->ToTransversal();
    //obj->Data->ToCorronial();
 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    for(int z = 0 ; z < files.size(); z++)
    {
    Mat  img = obj->Data->Sagittal->at(z)->Slice;

    ///blur( img, img, Size(3,3) );





     /// Canny detector
     //Canny( img, img, lowThreshold, lowThreshold*ratio, kernel_size );
    img.convertTo(img, CV_8UC1, 0.06);
    cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

    cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);

    cv::Mat binary;
    std::vector < std::vector<cv::Point2i > > blobs;
   // equalizeHist( img, img );

    medianBlur ( img, img, 7 );

    cv::blur( img, img, Size( 6, 6), Point(-1,-1) );

    cv::adaptiveThreshold(img,binary,  1.0,CV_ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,21,-0.8 );
    cv::Mat element(2,2,CV_8U,cv::Scalar(1));
   cv::dilate(binary,binary,element);
    FindBlobs(binary, blobs);
    cv::imshow("binary", img);
    //waitKey(0); 
    // Randomy color the blobs
int Max =0; 
int Maxcount =0; 
int i =0;     
for(i=0; i < blobs.size(); i++) {
        
      if(blobs[i].size() > 500)
        {
          if(inrange(&blobs[i]))
          {
int pointsintherange  = 0; 
  for(size_t j=0; j < blobs[i].size(); j++) {
        if(( blobs[i][j].x >190)&& (blobs[i][j].x <305) &&  (blobs[i][j].y >250) && (blobs[i][j].y<300))
		pointsintherange++;
       }           

if(Maxcount<pointsintherange)
	    Max = i;
	    Maxcount = pointsintherange;
          }
        }

    }
   i = Max;
	unsigned char r = 255 * (rand()/(1.0 + RAND_MAX));
        unsigned char g = 255 * (rand()/(1.0 + RAND_MAX));
        unsigned char b = 255 * (rand()/(1.0 + RAND_MAX));
  for(size_t j=0; j < blobs[i].size(); j++) {
            int x = blobs[i][j].x;
            int y = blobs[i][j].y;

            output.at<cv::Vec3b>(y,x)[0] = b;
            output.at<cv::Vec3b>(y,x)[1] = g;
            output.at<cv::Vec3b>(y,x)[2] = r;
        }

    Canny( output, output, lowThreshold, lowThreshold*ratio, kernel_size );
    cv::imshow("binary", img);

    imshow("this is ma",output);
    cout << "Hello World!" << endl;
    //waitKey(0); 


  for(size_t j=0; j < blobs[i].size(); j++) {
	PointXYZ point( blobs[i][j].x, blobs[i][j].y, z);
	cloud->push_back(point);
}
    }

// Create the filtering object
  pcl::VoxelGrid<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setLeafSize (6, 6, 6);
  sor.filter (*cloud_filtered);

  std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height 
       << " data points (" << pcl::getFieldsList (*cloud_filtered) << ").";



    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzrgb (new pcl::PointCloud<pcl::PointXYZRGB>);

  copyPointCloud(*cloud_filtered, *cloud_xyzrgb );


 for (size_t i = 0; i < cloud_xyzrgb->points.size (); ++i)
{
cloud_xyzrgb->points[i].r = 255;
}
 boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud_xyzrgb);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud_xyzrgb, rgb, "sample cloud");

  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");



 viewer->addCoordinateSystem 	( 	1,0,0,100);

  viewer->initCameraParameters ();

  
    viewer->spin();

while (!viewer->wasStopped ())
  {
  double x , y , z , r , b,o;
  cout << "give x y  z \n";
  cin >> x ;
  cin >> y; 
  cin >> z;

 viewer->setCameraPosition 	( 	x,y,z,0,0,0,0);
 //updateCamera ();
 
  }  




    return 0;
}

