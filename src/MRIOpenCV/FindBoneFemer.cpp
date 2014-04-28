/*
 * FindBoneFemer.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "FindBoneFemer.h"
#include "MRICommon.h"
FindBoneFemer::FindBoneFemer(std::vector< MRICommon *> * ImageStacks , std::vector<LabeledResults *> * LabeledOutput, int id  )  {
	// TODO Auto-generated constructor stub
this->ImageStacks = ImageStacks;
this->LabeledOutput = LabeledOutput;
this->id = id;
}

FindBoneFemer::~FindBoneFemer() {
	// TODO Auto-generated destructor stub
}

void FindBoneFemer::FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs)
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

void FindBoneFemer::Setup()
{
 MRICommon *  fat = this->ImageStacks->at(FATCUBE);                                    // Wait for a keystroke in the window    waitKey(0);
img = fat->Data->Sagittal->at(this->id)->Slice;
img.convertTo(img, CV_8UC1, 0.06);

}
bool FindBoneFemer::inrange( std::vector<cv::Point2i >  * points)
{

    for(int i =0; i< points->size(); i++)
    {

        if( (points->at(i).x >190)&& (points->at(i).x <305) &&  (points->at(i).y >209) && (points->at(i).y<340))
           return true;
    }
    return false;

}

void FindBoneFemer::Preprocess()
{




}

void FindBoneFemer::Segment()
{

}

void FindBoneFemer::PostSegmentProcess()
{




}

void FindBoneFemer::Label()
{

}


void FindBoneFemer::PostProcess()
{
	int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";

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
	 //   cv::imshow("binary", img);
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
	   // cv::imshow("binary", img);

	    //imshow("this is ma",output);
	    cout << "Hello World!" << endl;
	    //waitKey(0);
	    for(int x = 0; x < 512; x++)
	    {
	    	for(int y = 0; y <512; y++)
	    	{
	    		  if(output.at<uchar>(x,y) == 255)
	    		  {
	    			  PointXYZ point( x, y, id*2);
	    	this->LabeledOutput->at(BONE)->cloud->push_back(point);

	    		  }
	    	}

	    }


}

