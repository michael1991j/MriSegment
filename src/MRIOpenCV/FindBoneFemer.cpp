/*
 * FindBoneFemer.cpp
 *
 *  Created on: Apr 16, 2014
 *      Author: mri
 */

#include "FindBoneFemer.h"
#include "MRICommon.h"

//! Constructor for MRI Femur Bone detection algorithm in Sagittal plane.
/*!
 \param ImageStacks Pointer to all the images in the stack.
 \param LabeledOutput Output results of the algorithm (will return in point cloud format).
 \param id Layer of image in stack.
 \param config Configuration file for algorithm settings.
 */
FindBoneFemer::FindBoneFemer(std::vector<MRICommon *> * ImageStacks,
		std::vector<LabeledResults *> * LabeledOutput, int id,
		MRIOpenCVSettings * config) {
	// TODO Auto-generated constructor stub
	this->ImageStacks = ImageStacks;
	this->LabeledOutput = LabeledOutput;
	this->id = id;
	this->config = config;
}

//! Deconstructor for MRI Femur Bone detection algorithm in Sagittal plane.
FindBoneFemer::~FindBoneFemer() {
	// TODO Auto-generated destructor stub
}

//! Helper function to find blobs after image segmentation.
/*!
 \param binary Input binary matrix.
 \param blobs Output list of connected blobs.
 */
void FindBoneFemer::FindBlobs(const cv::Mat &binary,
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
void FindBoneFemer::Setup() {
	MRICommon * fat = this->ImageStacks->at(FATCUBE); // Wait for a keystroke in the window    waitKey(0);
	img = fat->Data->Sagittal->at(this->id)->Slice;
	img.convertTo(img, CV_8UC1, config->GetSettings("FindBoneFemer", "conversion_ratio", 0.06));

}

//! Helper function to determine if a blob is within the area of interest.
/*!
 \param points Input coordinates of blob of interest.
 */
bool FindBoneFemer::inrange(std::vector<cv::Point2i> * points) {

	for (int i = 0; i < points->size(); i++) {

		if ((points->at(i).x
				> config->GetSettings("FindBoneFemer", "bounding_box_x1", 190))
				&& (points->at(i).x
						< config->GetSettings("FindBoneFemer",
								"bounding_box_x2", 305))
				&& (points->at(i).y
						> config->GetSettings("FindBoneFemer",
								"bounding_box_y1", 250))
				&& (points->at(i).y
						< config->GetSettings("FindBoneFemer",
								"bounding_box_y2", 300)))
			return true;
	}
	return false;

}

//! Helper function to process image prior to segmentation.
void FindBoneFemer::Preprocess() {

	cv::threshold(img, img,
	config->GetSettings("FindBoneFemer", "noise_cutoff", 15), 255, 3);
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
	clahe->apply(img, img);

}

//! Helper function to segment image.
void FindBoneFemer::Segment() {

	cv::threshold(img, img, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	cv::imshow("a", img);

}

//! Helper function process image after segmentation.
void FindBoneFemer::PostSegmentProcess() {

}

//! Helper function to label image.
void FindBoneFemer::Label() {

}

//! Helper function process image after labeling.
void FindBoneFemer::PostProcess() {
	cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);
	cv::Mat binary;
	std::vector < std::vector<cv::Point2i> > blobs;
	cv::adaptiveThreshold(img, binary, 1.0, CV_ADAPTIVE_THRESH_GAUSSIAN_C,
			cv::THRESH_BINARY, 21, -0.8);
	int size = config->GetSettings("FindBoneFemer", "dilation_size", 2);
	cv::Mat element(size, size, CV_8U, cv::Scalar(1));
	if(size>0)
		cv::dilate(binary, binary, element);
	FindBlobs(binary, blobs);
	int Max = 0;
	int Maxcount = 0;
	int i = 0;
	for (i = 0; i < blobs.size(); i++) {

		if (blobs[i].size()
				> config->GetSettings("FindBoneFemer", "min_blob_size", 500)) {
			if (inrange (&blobs[i])) {
				int pointsintherange = 0;
				for (size_t j = 0; j < blobs[i].size(); j++) {
					if ((blobs[i][j].x
							> config->GetSettings("FindBoneFemer",
									"bounding_box_x1", 190))
							&& (blobs[i][j].x
									< config->GetSettings("FindBoneFemer",
											"bounding_box_x2", 305))
							&& (blobs[i][j].y
									> config->GetSettings("FindBoneFemer",
											"bounding_box_y1", 250))
							&& (blobs[i][j].y
									< config->GetSettings("FindBoneFemer",
											"bounding_box_y2", 300)))
						pointsintherange++;
				}

				if (Maxcount < pointsintherange)
					Max = i;
				Maxcount = pointsintherange;
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

	cv::Canny(output, output,
			config->GetSettings("FindBoneFemer", "Canny_low_thresh", 10),
			config->GetSettings("FindBoneFemer", "Canny_low_thresh", 10)
					* config->GetSettings("FindBoneFemer", "Canny_ratio", 3),
			config->GetSettings("FindBoneFemer", "Canny_kernel", 3));

	for (int x = 0; x < output.cols; x++) {
		for (int y = 0; y < output.rows; y++) {
			if (output.at<uchar>(y, x) == 255) {
				pcl::PointXYZ point(
						x
								* config->GetSettings("FindBoneFemer",
										"X_axis_multiplier", 1),
						y
								* config->GetSettings("FindBoneFemer",
										"Y_axis_multiplier", 1),
						id
								* config->GetSettings("FindBoneFemer",
										"Z_axis_multiplier", 2));
				if (id > config->GetSettings("FindBoneFemer", "Image_plane_low", 50)
							&& id< config->GetSettings("FindBoneFemer","Image_plane_high", 185))
					this->LabeledOutput->at(BONE)->cloud->push_back(point);

			}
		}

	}

}

