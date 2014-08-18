/*
 * FindCartilage.cpp
 *
 *  Created on: Apr 27, 2014
 *      Author: mri
 */

#include "FindCartilage.h"
#include "MRICommon.h"

//! Constructor for MRI Cartilage detection algorithm.
/*!
 \param ImageStacks Pointer to all the images in the stack.
 \param LabeledOutput Output results of the algorithm (will return in point cloud format).
 \param id Layer of image in stack.
 \param config Configuration file for algorithm settings.
 */
FindCartilage::FindCartilage(std::vector<MRICommon *> * ImageStacks,
		std::vector<LabeledResults *> * LabeledOutput, int id,
		MRIOpenCVSettings * config) {
	// TODO Auto-generated constructor stub
	this->ImageStacks = ImageStacks;
	this->LabeledOutput = LabeledOutput;
	this->id = id;
	this->config = config;
}

//! Deconstructor for MRI Cartilage detection algorithm.
FindCartilage::~FindCartilage() {
	// TODO Auto-generated destructor stub
}

//! Helper function to find blobs after image segmentation.
/*!
 \param binary Input binary matrix.
 \param blobs Output list of connected blobs.
 */
void FindCartilage::FindBlobs(const cv::Mat &binary,
		std::vector<std::vector<cv::Point2i> > &blobs) {
	blobs.clear();

	// Fill the label_image with the blobs
	// 0  - background
	// 1  - unlabelled foreground
	// 2+ - labelled foreground

	cv::Mat label_image;
	binary.convertTo(label_image, CV_32SC1);

	int label_count = 2; // starts at 2 because 0,1 are used already

	for (int y = 0; y < label_image.rows; y++) {
		int *row = (int*) label_image.ptr(y);
		for (int x = 0; x < label_image.cols; x++) {
			if (row[x] != 1) {
				continue;
			}

			cv::Rect rect;
			cv::floodFill(label_image, cv::Point(x, y), label_count, &rect, 0,
					0, 4);

			std::vector<cv::Point2i> blob;

			for (int i = rect.y; i < (rect.y + rect.height); i++) {
				int *row2 = (int*) label_image.ptr(i);
				for (int j = rect.x; j < (rect.x + rect.width); j++) {
					if (row2[j] != label_count) {
						continue;
					}

					blob.push_back(cv::Point2i(j, i));
				}
			}

			blobs.push_back(blob);

			label_count++;
		}
	}
}

//! Helper function to prepare image for segmentation.
void FindCartilage::Setup() {
	MRICommon * fat = this->ImageStacks->at(FATSPGR); // Wait for a keystroke in the window    waitKey(0);
	MRICommon * water = this->ImageStacks->at(WATERSPGR); // Wait for a keystroke in the window    waitKey(0);
	img = water->Data->Coronial->at(this->id)->Slice
			- fat->Data->Coronial->at(this->id)->Slice;
	img.convertTo(img, CV_8UC1, config->GetSettings("FindCartilage", "conversion_ratio", 0.09));
}

//! Helper function to determine if a blob is within the area of interest.
/*!
 \param points Input coordinates of blob of interest.
 \return bool True/False boolean that states whether the point is in the specified range.
 */
bool FindCartilage::inrange(std::vector<cv::Point2i> * points) {
	int x1 = config->GetSettings("FindCartilage", "bounding_box_x1", 40);
	int x2 = config->GetSettings("FindCartilage", "bounding_box_x2", 90);
	int y1 = config->GetSettings("FindCartilage", "bounding_box_y1", 270);
	int y2 = config->GetSettings("FindCartilage", "bounding_box_y2", 360);
	for (int i = 0; i < points->size(); i++) {

		if ((points->at(i).x > x1) && (points->at(i).x < x2)
				&& (points->at(i).y > y1) && (points->at(i).y < y2))
			return true;
	}
	return false;

}

//! Helper function to process image prior to segmentation.
void FindCartilage::Preprocess() {
	int Median_size = config->GetSettings("FindCartilage", "Median_size", 3);
	int Gaussian_size = config->GetSettings("FindCartilage", "Gaussian_size", 7);
	if(Gaussian_size>0)
		cv::GaussianBlur(img, img, cv::Size(Gaussian_size, Gaussian_size), 0, 0);
	if(Median_size>0)
		cv::medianBlur(img, img, Median_size);

}

//! Helper function to segment image.
void FindCartilage::Segment() {

}

//! Helper function process image after segmentation.
void FindCartilage::PostSegmentProcess() {
	cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);

	cv::Mat binary;
	std::vector < std::vector<cv::Point2i> > blobs;

	cv::adaptiveThreshold(img, binary, 1.0, CV_ADAPTIVE_THRESH_GAUSSIAN_C,
			cv::THRESH_BINARY, 21, -0.8);
	int dilation_size = config->GetSettings("FindCartilage", "dilation_size", 2);
	cv::Mat element(dilation_size, dilation_size, CV_8U, cv::Scalar(1));
	if(dilation_size>0)
		cv::dilate(binary, binary, element);
	FindBlobs(binary, blobs);
	int Maxcount = 0;
	int Max = 0;
	int i = 0;
	int x1 = config->GetSettings("FindCartilage", "bounding_box_x1", 40);
	int x2 = config->GetSettings("FindCartilage", "bounding_box_x2", 90);
	int y1 = config->GetSettings("FindCartilage", "bounding_box_y1", 270);
	int y2 = config->GetSettings("FindCartilage", "bounding_box_y2", 360);
	int blobsize = config->GetSettings("FindCartilage", "min_blob_size", 200);
	for (i = 0; i < blobs.size(); i++) {
		if (blobs[i].size() > blobsize) {
			if (inrange (&blobs[i])) {
				int pointsintherange = 0;
				for (size_t j = 0; j < blobs[i].size(); j++) {
					if ((blobs[i][j].x > x1) && (blobs[i][j].x < x2)
							&& (blobs[i][j].y > y1) && (blobs[i][j].y < y2))
						pointsintherange++;
				}

				if (Maxcount < pointsintherange) {
					Max = i;
					Maxcount = pointsintherange;
				}
			}
		}
	}
	i = Max;
	unsigned char r = 255 * (rand() / (1.0 + RAND_MAX));
	unsigned char g = 255 * (rand() / (1.0 + RAND_MAX));
	unsigned char b = 255 * (rand() / (1.0 + RAND_MAX));
	for (size_t j = 0; j < blobs[i].size(); j++) {
		int x = blobs[i][j].x;
		int y = blobs[i][j].y;

		output.at<cv::Vec3b>(y, x)[0] = b;
		output.at<cv::Vec3b>(y, x)[1] = g;
		output.at<cv::Vec3b>(y, x)[2] = r;
	}
	  cv::Mat delement = cv::getStructuringElement( cv::MORPH_ELLIPSE,
	                                      cv::Size( 2*5 + 1, 2*5+1 ),
	                                      cv::Point( 5, 5 ) );

	  /// Apply the dialation operation
	 // cv::dilate( output, output, delement );
	Canny(output, output,
			config->GetSettings("FindCartilage", "Canny_low_thresh", 5),
			config->GetSettings("FindCartilage", "Canny_high_thresh", 10),
			config->GetSettings("FindCartilage", "Canny_kernel", 3));
	double x_mult = config->GetSettings("FindCartilage", "X_axis_multiplier", 512/116);
	int y_mult = config->GetSettings("FindCartilage", "Y_axis_multiplier", 1);
	int z_mult = config->GetSettings("FindCartilage", "Z_axis_multiplier", 1);
	int plane_low = config->GetSettings("FindCartilage", "Image_plane_low", 150);
	int plane_high = config->GetSettings("FindCartilage","Image_plane_high", 295);
	for (int x = 0; x < output.cols; x++) {
		for (int y = 0; y < output.rows; y++) {
			if (output.at<uchar>(y, x) == 255) {
				pcl::PointXYZ point(id * z_mult, y * y_mult, (double)x * x_mult);
				if (id > plane_low && id < plane_high)
					this->LabeledOutput->at(CARTILAGE_COR)->cloud->push_back(point);

			}
		}

	}

}

//! Helper function to label image.
void FindCartilage::Label() {

}

//! Helper function process image after labeling.
void FindCartilage::PostProcess() {

}

