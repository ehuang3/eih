#include <iostream>
#include <gtest/gtest.h>
#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/* ********************************************************************************************* */
std::string convertCVTypeToString(int type) {
	std::string r;
	uchar depth = type & CV_MAT_DEPTH_MASK;
	uchar chans = 1 + (type >> CV_CN_SHIFT);
	switch ( depth ) {
	case CV_8U:  r = "8U"; break;
	case CV_8S:  r = "8S"; break;
	case CV_16U: r = "16U"; break;
	case CV_16S: r = "16S"; break;
	case CV_32S: r = "32S"; break;
	case CV_32F: r = "32F"; break;
	case CV_64F: r = "64F"; break;
	default:     r = "User"; break;
	}
	r += "C";
	r += (chans+'0');
	return r;
}
/* ********************************************************************************************* */
TEST(OPTICAL_FLOW, YOSEMITE_FARNEBACK) {
	// Load images
	std::string path = "/hd/vision/middlebury/optical_flow/eval-data/Yosemite/";
	std::vector<std::string> files = {"frame07.png",
	                                  "frame08.png",
	                                  "frame09.png",
	                                  "frame10.png",
	                                  "frame11.png",
	                                  "frame12.png", 
	                                  "frame13.png",
	                                  "frame14.png"};
	std::vector<cv::Mat> yosemite_seq;
	for(int i=0; i < files.size(); i++) {
		yosemite_seq.push_back(cv::imread(path+files[i], CV_LOAD_IMAGE_COLOR));
		if(yosemite_seq[i].data == NULL) {
			std::cerr << "Did not load image" << std::endl;
		} else {
			std::cout << "Load cv::Mat with type: " << convertCVTypeToString(yosemite_seq[i].type()) << std::endl;
		}
	}

	// Display sequence
	cv::namedWindow("Yosemite Sequence", cv::WINDOW_AUTOSIZE);
	for(int i=0; i < yosemite_seq.size(); i++) {
		cv::imshow("Yosemite Sequence", yosemite_seq[i]);
		cv::waitKey(0);
	}

	// Compute flow
	cv::Mat prev, next, flow;
	cv::cvtColor(yosemite_seq[0], prev, cv::COLOR_BGR2GRAY);
	for(int i=1; i < yosemite_seq.size(); i++) {
		cv::cvtColor(yosemite_seq[i], next, cv::COLOR_BGR2GRAY);
		// cv::calcOpticalFlowFarneback(prev, next, flow, 
	}
}

/* ********************************************************************************************* */
TEST(LKFLOW, SECOND_TEST) {

}

/* ********************************************************************************************* */
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/* ********************************************************************************************* */
