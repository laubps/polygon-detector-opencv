#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"

#include <vector>
#include <numeric>
#include <opencv2/core.hpp>

class Rectangle : public Polygon
{
public:
    Rectangle(const vector<cv::Point>& vertices, const vector<double>& sides,
              const vector<double>& angles);
};

#endif // RECTANGLE_H
