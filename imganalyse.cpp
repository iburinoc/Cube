#include <opencv2/core/core.hpp>

#include <vector>

#include "imganalyse.h"

static inline cv::Point average(cv::Point a, cv::Point b) {
	return cv::Point((a.x+b.x)/2, (a.y+b.y)/2);
}

std::vector<cv::Point> locatepoints(std::vector<cv::Point> corners) {
	std::vector<cv::Point> v(9);
	v[0] = corners[0];
	v[2] = corners[1];
	v[6] = corners[2];
	v[8] = corners[3];

	v[1] = average(v[0], v[2]);
	v[7] = average(v[6], v[8]);

	v[3] = average(v[0], v[6]);
	v[4] = average(v[1], v[7]);
	v[5] = average(v[2], v[8]);

	return v;
}

std::vector<cv::Scalar> colours = {
	cv::Scalar(58, 78, 90),
	cv::Scalar(34, 46, 64),
	cv::Scalar(27, 34, 55),
	cv::Scalar(40, 60, 89),
	cv::Scalar(53, 71, 96),
	cv::Scalar(50, 41, 62),
};

static inline int diffa(cv::Scalar a, cv::Scalar b) {
	return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2]);
}

#define abs(x) ((x) < 0 ? -(x) : (x))
static inline int diff(cv::Scalar a, cv::Scalar b) {
	return abs(a[0]-b[0])*abs(a[1]-b[1])*abs(a[2]-b[2]);
}

int closestColour(cv::Scalar colour) {
	int min = diff(colours[0], colour);
	int mini = 0;
	for(int i = 1; i < colours.size(); i++) {
		int d = diff(colours[i], colour);
		if(d < min) {
			min = d;
			mini = i;
		}
	}
	return mini;
}

static bool compair(std::pair<int, int> a, std::pair<int, int> b) {
	return a[0] < b[0];
}

Cube readcube(std::vector<cv::Mat> imgs, std::vector<cv::Point> points) {
	Cube c;
	bool used[54];
	memset(used, 0, sizeof(used));

	for(int i = 0; i < 6; i++) {
		int s = 0;
		while(!used[s]) { s++; }
		cv::Scalar base = getScalar(imgs[s/6].at<Vec3b>(points[s%9]));
		std::vector<std::pair<int, int>> dists;
		for(int j = s + 1; j < 54; j++) {
			dists.push_back(std::make_pair(
				diff(getScalar(imgs[j/6].at<Vec3b>(points[j%9])), base),
				j));
		}
		std::sort(dists.begin(), dists.end(), compair);
	}
}
