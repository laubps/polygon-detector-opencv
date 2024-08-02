#ifndef POLYGONVALIDATOR_H
#define POLYGONVALIDATOR_H

#include "../polygon/polygon.h"
#include "../polygon/rectangle.h"
#include "../polygon/triangle.h"

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <cmath>
#include <numeric>

using namespace std;

class PolygonFactory
{
public:
    PolygonFactory(const vector<cv::Point> vertices);

    shared_ptr<Polygon> createPolygon();
    shared_ptr<Polygon> handleIsQuadrilateral() const;
    shared_ptr<Triangle> handleIsTriangle();

    // Getters
    const std::vector<cv::Point>& getVertices() const {
        return vertices;
    }
    const std::vector<double>& getSides() const {
        return sides;
    }
    const std::vector<double>& getAngles() const {
        return angles;
    }

private:
    static constexpr double TOLERANCE = 0.1;

    const vector<cv::Point> vertices;
    vector<double> sides;
    vector<double> angles;

    void setAnglesFromVertices();
    void setSidesFromVertices();

    bool areSidesEqual() const;
    bool areAnglesEqualTo(const int targetAngle) const;
    bool areSidesSymetrical() const;
    bool areAnglesSymetrical() const;
    vector<pair<double, int>> groupValuesByProximity(const vector<double>& values, double tolerance);
    bool isNumSidesValid(const int targetNumSides) const;
    bool isSumOfAnglesValid(const int targetSum) const;
    bool isEqualSidesCountValid(const int numSides);
    bool isEqualAnglesCountValid(const int numAngles);
    bool areSidesDifferent();
    bool areAnglesDifferent();

    bool isCuadrilateral() const;
    bool isSquare() const;
    bool isRectangle() const;
    bool isRhombus() const;
    bool isTriangle() const;
    bool isEquilateralTriangle() const;
    bool isIsoscelesTriangle();
    bool isEscalenoTriangle() ;
    bool isCircle() const;
};

#endif // POLYGONVALIDATOR_H
