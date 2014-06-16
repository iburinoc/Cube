#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <unistd.h>
#include <fcntl.h>

#include "imganalyse.h"
#include "cubegui.h"
#include "guiutil.h"

struct Click {
	int x, y;
	bool clicked;

	Click() : x(0), y(0), clicked(false) {}
};

static void cubeclick(int e, int x, int y, int d, void* userdata) {
	if(e != cv::EVENT_LBUTTONDOWN) {
		return;
	}

	Click* c = (Click*) userdata;
	c->x = x;
	c->y = y;
	c->clicked = true;
	std::cout << "click: (" << x << "," << y << ")" << std::endl;
}

/* returns a vector of size 4 with the 4 corners */
std::vector<cv::Point> getcorners(std::string winname, cv::Mat cubeimg) {
	cv::imshow(winname, cubeimg);
	std::vector<cv::Point> v;
	volatile Click c;
	cv::setMouseCallback(winname, cubeclick, (void*) &c);
	std::cout << "Click in the middle of the \ntop left\ntop right\nbottom left\nbottom right\nstickers in that order" << std::endl;
	for(int i = 0; i < 4; i++) {
		while(!c.clicked) {
			cv::waitKey(3);
		}
		v.push_back(cv::Point((const int) c.x, (const int) c.y));
		c.clicked = false;
	}
	return v;
}

void showclosest(std::string winname, cv::Mat frame) {
	cv::imshow(winname, frame);
	volatile Click c;
	cv::setMouseCallback(winname, cubeclick, (void*) &c);
	while(1) {
		while(!c.clicked) {
			cv::waitKey(3);
		}
		cv::Vec3b px = frame.at<cv::Vec3b>(c.x, c.y);
		std::cout << "Colors: " << (int) px[2] << "," << (int) px[1] << "," << (int) px[0] << std::endl;
		cv::Scalar colour(px[2], px[1], px[0]);
		std::cout << "Closest: " << closestColour(colour) << std::endl;
		c.clicked = false;
	}
}

std::string picops = "pfpfpfpfrfpffpfl";

Cube scancube(int fd, cv::VideoCapture cap, std::string winname) {
	std::vector<cv::Mat> frames;
	for(int i = 0; i < picops.size(); i++) {
		char c = picops[i];
		if(c == 'p') {
			cv::Mat frame;
			cap >> frame;
			frames.push_back(frame);
		} else {
			write(fd, &c, 1);
			while(read(fd, &c, 1) == 0) {
				cv::Mat frame;
				cap >> frame;
				imshow(winname, frame);
			}
		}
		usleep(500 * 1000);
	}
	std::vector<cv::Point> points = locatepoints(getcorners(winname, frames[0]));

	return analysecube(frames, points);
}
