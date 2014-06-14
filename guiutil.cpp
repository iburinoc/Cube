#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <string>

#include "guiutil.h"

static void cb(int e, int x, int y, int d, void* dat) {
	if(e != cv::EVENT_LBUTTONDOWN) {
		return;
	}
	bool* b = (bool*) dat;
	*b = true;
}

void waitForClick(std::string winname, cv::VideoCapture cap) {
	volatile bool b = false;
	cv::setMouseCallback(winname, cb, (void*) &b);
	while(!b) {
		cv::Mat frame;
		cap >> frame;
		imshow(winname, frame);
		cv::waitKey(3);
	}
}

void waitForClick(std::string winname, cv::Mat frame) {
	volatile bool b = false;
	cv::setMouseCallback(winname, cb, (void*) &b);
	cv::imshow(winname, frame);
	while(!b) {
		cv::waitKey(3);
	}
}

void drawDots(cv::Mat& img, std::vector<cv::Point> points) {
	for(int i = 0; i < points.size(); i++) {
		circle(img, points[i], 5, cv::Scalar(0, 0, 0), -1);
	}
}

cv::Scalar getScalar(cv::Vec3b c) {
	return cv::Scalar(c[2], c[1], c[0]);
}
