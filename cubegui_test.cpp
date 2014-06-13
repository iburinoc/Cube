#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include "cubegui.h"
#include "guiutil.h"
#include "imganalyse.h"

int main(int argc, char** argv) {
	cv::VideoCapture cap(argc >= 2 ? atoi(argv[1]) : 0);
	if(!cap.isOpened()) {
		std::cout << ":C" << std::endl;
		return EXIT_FAILURE;
	}
	cv::namedWindow("cube", 1);
	std::cout << "Click to take picture" << std::endl;
	waitForClick("cube", cap);
	cv::Mat frame;
	cap >> frame;
	std::vector<cv::Point> corners = getcorners("cube", frame);
	std::vector<cv::Point> stickers = locatepoints(corners);
	cv::Mat dots = frame.clone();
	drawDots(dots, stickers);
	waitForClick("cube", dots);
	showclosest("cube", frame);
	/*
	Click c;
	cv::namedWindow("cam", 1);
	cv::setMouseCallback("cam", cubeclick, &c);
	while(1) {
		cv::Mat frame;
		cap >> frame;
		cv::imshow("cam", frame);
		if(c.clicked) {
			c.clicked = false;
			std::cout << "Mouse click at " << c.x << "," << c.y << std::endl;
			cv::Vec3b px = frame.at<cv::Vec3b>(c.x, c.y);
			std::cout << "Colors: " << (int) px[2] << "," << (int) px[1] << "," << (int) px[0] << std::endl;
		}
		if(cv::waitKey(3) >= 0) break;
	}
	*/
}
