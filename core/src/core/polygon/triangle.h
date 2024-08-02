#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include <vector>
#include <opencv2/core.hpp>

class Triangle: public Polygon
{
public:
    Triangle(const vector<cv::Point> & vertices, const vector<double> & sides,
             const vector<double> & angles);

protected:

};

#endif // TRIANGLE_H
