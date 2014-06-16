#ifndef IMGANALYSE_H
#define IMGANALYSE_H

#include <opencv2/core/core.hpp>

#include <vector>

#include "cube.h"

std::vector<cv::Point> locatepoints(std::vector<cv::Point> corners);

int closestColour(cv::Scalar colour);

Cube analysecube(std::vector<cv::Mat> imgs, std::vector<cv::Point> points);

#endif
