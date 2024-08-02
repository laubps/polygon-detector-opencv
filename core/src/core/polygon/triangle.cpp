#include "triangle.h"

Triangle::Triangle(const vector<cv::Point> & vertices, const vector<double> & sides,
                   const vector<double> & angles)
    : Polygon("Triangulo", "Poligono", vertices, sides, angles) {}



