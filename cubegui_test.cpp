#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#include "cubegui.h"
#include "guiutil.h"
#include "imganalyse.h"

#include "serial.h"

void usage(char** argv) {
	std::cout << argv[0] << " [serial port] [cam number]" << std::endl;
}

int main(int argc, char** argv) {
	if(argc < 2) {
		usage(argv);
		return EXIT_FAILURE;
	}
	int fd = getserialfd(argv[1]);
	cv::VideoCapture cap(atoi(argv[2]));
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
	scancube(fd, cap, "cube");
	close(fd);
}
