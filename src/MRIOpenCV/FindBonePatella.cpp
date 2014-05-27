/*
 * FindBonePatella.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

//! Constructor for MRI Patella Bone detection algorithm.
/*!
 \param ImageStacks Pointer to all the images in the stack.
 \param LabeledOutput Output results of the algorithm (will return in point cloud format).
 \param id Layer of image in stack.
 \param config Configuration file for algorithm settings.
 */
#include "FindBonePatella.h"
#include "MRICommon.h"
FindBonePatella::FindBonePatella(std::vector<MRICommon *> * ImageStacks,
		std::vector<LabeledResults *> * LabeledOutput, int id,
		MRIOpenCVSettings * config) {
	// TODO Auto-generated constructor stub
	this->ImageStacks = ImageStacks;
	this->LabeledOutput = LabeledOutput;
	this->id = id;
	this->config = config;
}

//! Deconstructor for MRI Patella Bone detection algorithm.
FindBonePatella::~FindBonePatella() {
	// TODO Auto-generated destructor stub
}

//! Helper function to find blobs after image segmentation.
/*!
 \param binary Input binary matrix.
 \param blobs Output list of connected blobs.
 */
void FindBonePatella::FindBlobs(const cv::Mat &binary,
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
void FindBonePatella::Setup() {
	MRICommon * fat = this->ImageStacks->at(FATCUBE); // Wait for a keystroke in the window    waitKey(0);
	MRICommon * water = this->ImageStacks->at(WATERCUBE);
	img = fat->Data->Transversal->at(this->id)->Slice
			- water->Data->Transversal->at(this->id)->Slice;
	img.convertTo(img, CV_8UC1, config->GetSettings("FindBonePatella", "conversion_ratio", 0.06));

}

//! Helper function to determine if a blob is within the area of interest.
/*!
 \param points Input coordinates of blob of interest.
 \return bool True/False boolean that states whether the point is in the specified range.
 */
bool FindBonePatella::inrange(std::vector<cv::Point2i> * points) {
	int x1 = config->GetSettings("FindBonePatella", "bounding_box_x1", 120);
	int x2 = config->GetSettings("FindBonePatella", "bounding_box_x2", 130);
	int y1 = config->GetSettings("FindBonePatella", "bounding_box_y1", 147);
	int y2 = config->GetSettings("FindBonePatella", "bounding_box_y2", 157);
	for (int i = 0; i < points->size(); i++) {

		if ((points->at(i).x > x1) && (points->at(i).x < x2)
				&& (points->at(i).y > y1) && (points->at(i).y < y2))
			return true;
	}
	return false;

}

//! Helper function to process image prior to segmentation.
void FindBonePatella::Preprocess() {
	//cv::imshow("original",img);
	cv::threshold(img, img, config->GetSettings("FindBonePatella", "noise_cutoff", 15), 255, 3);
	Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	clahe->apply(img, img);
	cv::threshold(img, img, config->GetSettings("FindBonePatella", "noise_cutoff2", 42), 255, 3);

}

//! Helper function to segment image.
void FindBonePatella::Segment() {

	int size = config->GetSettings("FindBonePatella", "dilation_size", 1);
	int type = MORPH_ELLIPSE;
	cv::Mat element = getStructuringElement(type, cv::Size(2 * size, 2 * size),
			cv::Point(size, size));
	cv::Mat imagewithblack = img;
	cv::Mat imageblack;
	cv::threshold(img, imagewithblack, config->GetSettings("FindBonePatella", "noise_cutoff2", 42), 255, 1);
	cv::dilate(imagewithblack, imagewithblack, element);
	cv::threshold(imagewithblack, imageblack, 1, 255, 0);
	img.copyTo(img, imagewithblack);

}

//! Helper function process image after segmentation.
void FindBonePatella::PostSegmentProcess() {
	int Median_size = config->GetSettings("FindBonePatella", "Median_size", 5);
	if(Median_size>0)
		cv::medianBlur(img, img, 5);

}

//! Helper function to label image.
void FindBonePatella::Label() {
	cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector < std::vector<cv::Point2i> > blobs;
	cv::adaptiveThreshold(img, binary, 1.0, CV_ADAPTIVE_THRESH_GAUSSIAN_C,
			THRESH_BINARY, 21, -0.8);
	binary = 1 - binary;

	FindBlobs(binary, blobs);

	if (blobs.size() == 0) {
		cout << "\nthe blob size was zero \n";
		return;
	}
	int Max = 0;
	int Maxcount = 0;
	int i = 0;
	int x1 = config->GetSettings("FindBonePatella", "bounding_box_x1", 120);
	int x2 = config->GetSettings("FindBonePatella", "bounding_box_x2", 130);
	int y1 = config->GetSettings("FindBonePatella", "bounding_box_y1", 147);
	int y2 = config->GetSettings("FindBonePatella", "bounding_box_y2", 157);
	int blobsize = config->GetSettings("FindBonePatella", "min_blob_size", 200);
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
	int size = config->GetSettings("FindBonePatella", "dilation_size", 1);
	int type = MORPH_ELLIPSE;
	Mat element = getStructuringElement(type, Size(2 * size, 2 * size),
			Point(size, size));
	if(size>0)
		cv::dilate(output, output, element);
	cv::Canny(output, output, config->GetSettings("FindBonePatella", "Canny_low_thresh", 5), config->GetSettings("FindBonePatella", "Canny_high_thresh", 10), config->GetSettings("FindBonePatella", "Canny_kernel", 3));
	int x_mult = config->GetSettings("FindBonePatella", "X_axis_multiplier", 1);
	int y_mult = config->GetSettings("FindBonePatella", "Y_axis_multiplier", 2);
	int z_mult = config->GetSettings("FindBonePatella", "Z_axis_multiplier", 1);
	int plane_low = config->GetSettings("FindBonePatella", "Image_plane_low", 50);
	int plane_high = config->GetSettings("FindBonePatella","Image_plane_high", 185);
	for (int x = 0; x < img.cols; x++) {
		for (int y = 0; y < img.rows; y++) {
			//cout << "x:" << x <<" y: " << y<<"\n";
			if (output.at<uchar>(y, x) == 255) {
				pcl::PointXYZ point(x * x_mult, id * z_mult, y * y_mult);
				if (id > plane_low && id < plane_high)
					this->LabeledOutput->at(PATELLA_TRAN)->cloud->push_back(point);

			}
		}

	}
}

//! Helper function process image after labeling.
void FindBonePatella::PostProcess() {

}

