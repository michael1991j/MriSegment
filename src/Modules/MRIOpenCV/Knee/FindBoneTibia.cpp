/*
 * FindBoneTibia.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "FindBoneTibia.h"
#include "MRICommon.h"

//! Constructor for MRI Patella Bone detection algorithm.
/*!
 \param ImageStacks Pointer to all the images in the stack.
 \param LabeledOutput Output results of the algorithm (will return in point cloud format).
 \param id Layer of image in stack.
 \param config Configuration file for algorithm settings.
 */
FindBoneTibia::FindBoneTibia(std::vector<MRICommon *> * ImageStacks,
		std::vector<LabeledResults *> * LabeledOutput, int id,
		MRIOpenCVSettings * config) {
	// TODO Auto-generated constructor stub
	this->ImageStacks = ImageStacks;
	this->LabeledOutput = LabeledOutput;
	this->id = id;
	this->config = config;
}

//! Deconstructor for MRI Patella Bone detection algorithm.
FindBoneTibia::~FindBoneTibia() {
	// TODO Auto-generated destructor stub
}

//! Helper function to find blobs after image segmentation.
/*!
 \param binary Input binary matrix.
 \param blobs Output list of connected blobs.
 */
void FindBoneTibia::FindBlobs(const cv::Mat &binary,
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
void FindBoneTibia::Setup() {
	MRICommon * fat = this->ImageStacks->at(FATCUBE); // Wait for a keystroke in the window    waitKey(0);
	MRICommon * water = this->ImageStacks->at(WATERCUBE);
	img = fat->Data->Transversal->at(this->id)->Slice
			- water->Data->Transversal->at(this->id)->Slice;
	img.convertTo(img, CV_8UC1,
			config->GetSettings("FindBoneTibia", "conversion_ratio", 0.06));

}

//! Helper function to determine if a blob is within the area of interest.
/*!
 \param points Input coordinates of blob of interest.
 \return bool True/False boolean that states whether the point is in the specified range.
 */
bool FindBoneTibia::inrange(std::vector<cv::Point2i> * points) {

	int x1 = config->GetSettings("FindBoneTibia", "bounding_box_x1", 230);
	int x2 = config->GetSettings("FindBoneTibia", "bounding_box_x2", 270);
	int y1 = config->GetSettings("FindBoneTibia", "bounding_box_y1", 130);
	int y2 = config->GetSettings("FindBoneTibia", "bounding_box_y2", 150);
	for (int i = 0; i < points->size(); i++) {

		if ((points->at(i).x > x1) && (points->at(i).x < x2) && (points->at(i).y > y1) && (points->at(i).y< y2))
			return true;
	}
	return false;

}

//! Helper function to process image prior to segmentation.
void FindBoneTibia::Preprocess() {
	cv::threshold(img, img,
			config->GetSettings("FindBoneTibia", "noise_cutoff", 15), 255, 3);
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	clahe->apply(img, img);

}

//! Helper function to segment image.
void FindBoneTibia::Segment() {
	int Median_size = config->GetSettings("FindBoneTibia", "Median_size", 7);
	int Blur_size = config->GetSettings("FindBoneTibia", "Blur_size", 3);
	if (Median_size > 0)
		cv::medianBlur(img, img, Median_size);
	if (Blur_size > 0)
		cv::blur(img, img, cv::Size(Blur_size, Blur_size));
	cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

}

//! Helper function process image after segmentation.
void FindBoneTibia::PostSegmentProcess() {

}

//! Helper function to label image.
void FindBoneTibia::Label() {
	cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);
	std::vector < std::vector<cv::Point2i> > blobs;
	cv::adaptiveThreshold(img, binary, 1.0, CV_ADAPTIVE_THRESH_GAUSSIAN_C,
cv::THRESH_BINARY, 21, -0.8);
	//binary = 1-binary;

	FindBlobs(binary, blobs);

	if (blobs.size() == 0) {
		cout << "\nthe blob size was zero \n";
		return;
	}
	int Max = 0;
	int Maxcount = 0;
	int i = 0;
	int x1 = config->GetSettings("FindBoneTibia", "bounding_box_x1", 230);
	int x2 = config->GetSettings("FindBoneTibia", "bounding_box_x2", 270);
	int y1 = config->GetSettings("FindBoneTibia", "bounding_box_y1", 130);
	int y2 = config->GetSettings("FindBoneTibia", "bounding_box_y2", 150);
	int blobsize = config->GetSettings("FindBoneTibia", "min_blob_size", 200);
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
	int size = config->GetSettings("FindBoneTibia", "dilation_size", 1);
	;
	int type = cv::MORPH_ELLIPSE;
	cv::Mat element = cv::getStructuringElement(type, cv::Size(2 * size, 2 * size),
			cv::Point(size, size));
	if (size > 0)
		cv::dilate(output, output, element);
	cv::Canny(output, output,
			config->GetSettings("FindBoneTibia", "Canny_low_thresh", 5),
			config->GetSettings("FindBoneTibia", "Canny_high_thresh", 10),
			config->GetSettings("FindBoneTibia", "Canny_kernel", 3));
	int x_mult = config->GetSettings("FindBoneTibia", "X_axis_multiplier", 1);
	int y_mult = config->GetSettings("FindBoneTibia", "Y_axis_multiplier", 2);
	int z_mult = config->GetSettings("FindBoneTibia", "Z_axis_multiplier", 1);
	int plane_low = config->GetSettings("FindBoneTibia", "Image_plane_low", 326);
	int plane_high = config->GetSettings("FindBoneTibia","Image_plane_high", 445);
	for (int x = 0; x < img.cols; x++) {
		for (int y = 0; y < img.rows; y++) {
			if (output.at<uchar>(y, x) == 255) {
				pcl::PointXYZ point(x * x_mult, id * z_mult, y * y_mult);
				if (id > plane_low && id < plane_high)
					this->LabeledOutput->at(TIBA_TRAN)->cloud->push_back(point);
			}
		}

	}
}

//! Helper function process image after labeling.
void FindBoneTibia::PostProcess() {

}

