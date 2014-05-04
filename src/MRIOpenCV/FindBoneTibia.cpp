/*
 * FindBoneTibia.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "FindBoneTibia.h"
#include "MRICommon.h"
FindBoneTibia::FindBoneTibia(std::vector< MRICommon *> * ImageStacks , std::vector<LabeledResults *> * LabeledOutput, int id  )  {
	// TODO Auto-generated constructor stub
this->ImageStacks = ImageStacks;
this->LabeledOutput = LabeledOutput;
this->id = id;
}

FindBoneTibia::~FindBoneTibia() {
	// TODO Auto-generated destructor stub
}

void FindBoneTibia::FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs)
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

void FindBoneTibia::Setup()
{
 MRICommon *  fat = this->ImageStacks->at(FATCUBE);                                    // Wait for a keystroke in the window    waitKey(0);
 MRICommon *  water = this->ImageStacks->at(WATERCUBE);
img = fat->Data->Transversal->at(this->id)->Slice - water->Data->Transversal->at(this->id)->Slice;
img.convertTo(img, CV_8UC1, 0.06);

}
bool FindBoneTibia::inrange( std::vector<cv::Point2i >  * points)
{

    for(int i =0; i< points->size(); i++)
    {

        if( (points->at(i).x >230)&& (points->at(i).x <270) &&  (points->at(i).y >130) && (points->at(i).y<150))
           return true;
    }
    return false;

}

void FindBoneTibia::Preprocess()
{
	cv::threshold(img,img,15,255,3);
	Ptr<CLAHE> clahe = cv::createCLAHE();
	clahe->apply(img,img);


}

void FindBoneTibia::Segment()
{

	medianBlur ( img, img, 7 );
	blur( img, img, Size( 3, 3 ) );
	cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

}

void FindBoneTibia::PostSegmentProcess()
{


}

void FindBoneTibia::Label()
{
	cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector < std::vector<cv::Point2i > > blobs;
	cv::adaptiveThreshold(img,binary,  1.0,CV_ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,21,-0.8 );
	//binary = 1-binary;

	FindBlobs(binary, blobs);


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
					if(( blobs[i][j].x >230)&& (blobs[i][j].x <270) &&  (blobs[i][j].y >130) && (blobs[i][j].y<150))
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
	  int size= 1;
	  int type = MORPH_ELLIPSE;
	  Mat element = getStructuringElement( type, Size( 2*size, 2*size ), Point( size, size ) );
	  cv::dilate(output,output,element);
	  Canny( output, output, 5, 10, 3 );
	  waitKey(0);
	  for(int x = 0; x < img.cols; x++)
	 	    {
	 	    	for(int y = 0; y <img.rows; y++)
	 	    	{
	 	    		//cout << "x:" << x <<" y: " << y<<"\n";
	 	    		  if(output.at<uchar>(y,x) == 255)
	 	    		  {
	                       PointXYZ point( x, y*2, id);
	 	    	this->LabeledOutput->at(BONE)->cloud->push_back(point);

	 	    		  }
	 	    	}

	 	    }
}


void FindBoneTibia::PostProcess()
{


}

