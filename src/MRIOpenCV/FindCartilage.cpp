/*
 * FindCartilage.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: mri
 */


#include "FindCartilage.h"
#include "MRICommon.h"
FindCartilage::FindCartilage(std::vector< MRICommon *> * ImageStacks , std::vector<LabeledResults *> * LabeledOutput, int id  )  {
	// TODO Auto-generated constructor stub
this->ImageStacks = ImageStacks;
this->LabeledOutput = LabeledOutput;
this->id = id;
}

FindCartilage::~FindCartilage() {
	// TODO Auto-generated destructor stub
}

void FindCartilage::FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs)
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

void FindCartilage::Setup()
{
 MRICommon *  fat = this->ImageStacks->at(FATSPGR);                                    // Wait for a keystroke in the window    waitKey(0);
 MRICommon *  water = this->ImageStacks->at(WATERSPGR);                                    // Wait for a keystroke in the window    waitKey(0);

 img = water->Data->Coronial->at(this->id)->Slice - fat->Data->Coronial->at(this->id)->Slice ;
img.convertTo(img, CV_8UC1, 0.09);

imshow("w",img);

}
bool FindCartilage::inrange( std::vector<cv::Point2i >  * points)
{

    for(int i =0; i< points->size(); i++)
    {

        if( (points->at(i).x >40)&& (points->at(i).x <90) &&  (points->at(i).y >270) && (points->at(i).y<360))
           return true;
    }
    return false;

}

void FindCartilage::Preprocess()
{
	GaussianBlur ( img, img, Size(7,7),0,0 );
	medianBlur ( img, img, 3 );

}

void FindCartilage::Segment()
{
	  cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

		    cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);

		    cv::Mat binary;
		    std::vector < std::vector<cv::Point2i > > blobs;
		   // equalizeHist( img, img );

		    //medianBlur ( img, img, 7 );

		    //cv::blur( img, img, Size( 6, 6), Point(-1,-1) );

		    cv::adaptiveThreshold(img,binary,  1.0,CV_ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,21,-0.8 );
		    cv::Mat element(2,2,CV_8U,cv::Scalar(1));
		   cv::dilate(binary,binary,element);
		    FindBlobs(binary, blobs);
		    int Maxcount =0;
		   	int Max=0;
		   	int i=0;
		    for(i=0; i < blobs.size(); i++) {
		  									  if(blobs[i].size() > 200)
		  										{
		  										  if(inrange(&blobs[i]))
		  													  {
		  											int pointsintherange  = 0;
		  											  for(size_t j=0; j < blobs[i].size(); j++) {
		  													if(( blobs[i][j].x >40)&& (blobs[i][j].x <90) &&  (blobs[i][j].y >270) && (blobs[i][j].y<360))
		  													pointsintherange++;
		  												   }

		  											if(Maxcount<pointsintherange)
		  											{
		  												Max = i;
		  													Maxcount = pointsintherange;
		  													  }
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


		    imshow("a",output);
		 //   waitKey(0);
		    int edgeThresh = 1;
		       	 	int lowThreshold;
		       	 	int const max_lowThreshold = 500;
		       	 	int ratio = 3;
		       	 	int kernel_size = 3;
		       	 	char* window_name = "Edge Map";

		       	 	Canny( output, binary, lowThreshold, lowThreshold*ratio, kernel_size );
		    	  	   cv::imshow("binary", binary);

		    	  	    //imshow("this is ma",output);
		    	  	    cout << "Hello World!" << endl;
		    	  	    waitKey(0);


		     for(int x = 0; x < 512; x++)
		    	    {
		    	    	for(int y = 0; y <512; y++)
		    	    	{
		    	    		  if(binary.at<uchar>(x,y) == 255)
		    	    		  {
		    	    			  PointXYZ point( x, y*7, id);
		    	    	this->LabeledOutput->at(CARTILAGE)->cloud->push_back(point);

		    	    		  }
		    	    	}

		    	    }
}


void FindCartilage::PostSegmentProcess()
{
    cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);
    cv::Mat binary ;
    cv::adaptiveThreshold(img,binary,  1.0,CV_ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,21,-0.8 );
	    cv::imshow("b", binary);
	    int size= 1;
	    int type = MORPH_ELLIPSE;
	    Mat element = getStructuringElement( type,
	                                         Size( 2*size, 2*size ),
	                                         Point( size, size ) );
	cv::dilate(binary,binary,element);

    std::vector < std::vector<cv::Point2i > > blobs;
	FindBlobs(binary, blobs);
    cout << "get out of your mind : "<< blobs.size() << "lets fucking lose it \n";
	if (blobs.size() == 0)
	{
	cout << "\nthe blob size was zero \n";
		return;
	}
		int Max =0;
	int Maxcount =0;
	int i =0;
	for(i=0; i < blobs.size(); i++) {

	      if(blobs[i].size() > 200)
	        {
	    	  if(inrange(&blobs[i]))
	    	 	          {
	    	 	int pointsintherange  = 0;
	    	 	  for(size_t j=0; j < blobs[i].size(); j++) {
	    	 	        if(( blobs[i][j].x >40)&& (blobs[i][j].x <90) &&  (blobs[i][j].y >270) && (blobs[i][j].y<360))
	    	 			pointsintherange++;
	    	 	       }

	    	 	if(Maxcount<pointsintherange)
	    	 		    Max = i;
	    	 		    Maxcount = pointsintherange;
	    	 	          }
	    	 	        }
	    		  }
	i=Max;

	unsigned char r = 255 * (rand()/(1.0 + RAND_MAX));
			unsigned char g = 255 * (rand()/(1.0 + RAND_MAX));
			unsigned char b = 255 * (rand()/(1.0 + RAND_MAX));
		for(size_t j=0; j < blobs[i].size(); j++) {


			int x = blobs[i][j].x;
			int y = blobs[i][j].y;

			output.at<cv::Vec3b>(y,x)[0] = b;
			output.at<cv::Vec3b>(y,x)[1] = g;
			output.at<cv::Vec3b>(y,x)[2] = r;
			  PointXYZ point( x, y, id*2);
			   	    	this->LabeledOutput->at(BONE)->cloud->push_back(point);
	}


 	    cv::imshow("binary", output);
	    waitKey(0);

   	 	int edgeThresh = 1;
   	 	int lowThreshold;
   	 	int const max_lowThreshold = 500;
   	 	int ratio = 3;
   	 	int kernel_size = 3;
   	 	char* window_name = "Edge Map";

   	 	// cv::imshow("binary", img);

	   	  	    //imshow("this is ma",output);
	   	  	    cout << "Hello World!" << endl;




}

void FindCartilage::Label()
{

}


void FindCartilage::PostProcess()
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

