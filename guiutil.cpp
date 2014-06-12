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

