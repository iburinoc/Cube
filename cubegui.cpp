#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

#include "cubegui.h"

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

/* returns a vector of size 8 with the 4 corners */
std::vector<int> getcorners(std::string winname, cv::Mat cubeimg) {
	cv::imshow(winname, cubeimg);
	std::vector<int> v;
	volatile Click c;
	cv::setMouseCallback("cube", cubeclick, (void*) &c);
	std::cout << "Click in the middle of the \ntop left\ntop right\nbottom left\nbottom right\nstickers in that order" << std::endl;
	for(int i = 0; i < 4; i++) {
		while(!c.clicked) {
			cv::waitKey(3);
		}
		v.push_back((const int) c.x);
		v.push_back((const int) c.y);
		c.clicked = false;
	}
	return v;
}

