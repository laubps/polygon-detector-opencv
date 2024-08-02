#include "rectangle.h"

Rectangle::Rectangle(const vector<cv::Point>& vertices, const vector<double>& sides,
                     const vector<double>& angles)
    : Polygon("Rectangulo", "Cuadrilatero", vertices, sides, angles){}
