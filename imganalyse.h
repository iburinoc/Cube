#ifndef IMGANALYSE_H
#define IMGANALYSE_H

#include <opencv2/core/core.hpp>

#include <vector>

std::vector<cv::Point> locatepoints(std::vector<cv::Point> corners);

int closestColour(cv::Scalar colour);

#endif
