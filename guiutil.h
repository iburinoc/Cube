#ifndef GUIUTIL_H
#define GUIUTIL_H

#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

void waitForClick(std::string winname, cv::VideoCapture cap);

void waitForClick(std::string winname, cv::Mat frame);

void drawDots(cv::Mat& img, std::vector<cv::Point> points);

cv::Scalar getScalar(cv::Vec3b c);

#endif
