#ifndef POLYGONSDETECTOR_H
#define POLYGONSDETECTOR_H

#include "../image/image.h"
#include "../polygon/polygon.h"
#include "../polygon/rectangle.h"
#include "../polygon/triangle.h"
#include "../polygon_factory/polygonfactory.h"
#include "../../../include/colors.h"

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <memory>
#include <map>

using namespace std;
using namespace cv;

class PolygonsDetector
{
public:
    explicit PolygonsDetector(unique_ptr<Image> image);
    ~PolygonsDetector();

    enum Mode {
        DEFAULT = 0,
        AREA = 1,
        PERIMETER = 2,
        CONTOURS = 3,
        DETAILS = 4,
    };

    void detectPolygons();
    void drawPolygonsOnImage(PolygonsDetector::Mode mode);

    // Getters
    const Image& getImage() const;
    const vector<shared_ptr<Polygon>> getPolygons() const;
    const cv::Mat& getResultImage() const;

    // Setters
    void setPolygons(const vector<shared_ptr<Polygon>>& polygons);
    void setResultImage(const cv::Mat& newResultImage);

private:
    unique_ptr<Image> image;
    vector<shared_ptr<Polygon>> polygons;
    cv::Mat resultImage;
    // map<string, string> colorMap;

    void transformImage();
    const vector<vector<cv::Point>>& findContoursInImage();
    void drawTextOnImage(const cv::Point &centroide, const string text,
                         const cv::Scalar textColor, const cv::Scalar rectColor);
    cv::Scalar QColorToScalar(const QColor &color);
};

#endif // POLYGONSDETECTOR_H
