#include "polygonsdetector.h"

PolygonsDetector::PolygonsDetector(unique_ptr<Image> image) : image(move(image)) {}
PolygonsDetector::~PolygonsDetector() {}

void PolygonsDetector::transformImage(){
    if (!this->image) {
        return; // Verificar que la imagen original existe
    }

    cv::Mat processedImage = this->image->getPixels(); // Crear una copia de la imagen original

    cv::cvtColor(processedImage, processedImage, cv::COLOR_BGR2GRAY); // Convertir la imagen a escala de grises

    cv::GaussianBlur(processedImage, processedImage, cv::Size(5, 5), 1.5);

    cv::threshold(processedImage, processedImage, 240 , 255, cv::CHAIN_APPROX_NONE);

    this->resultImage = processedImage;
}

const vector<vector<cv::Point>>& PolygonsDetector::findContoursInImage(){
    if (resultImage.empty()) {
        throw std::runtime_error("resultImage está vacia.");
    }

    static vector<vector<cv::Point>> contours;
    cv::findContours(this->resultImage, contours, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

    return contours;
}

void PolygonsDetector::detectPolygons(){
    this->transformImage();
    const auto& contours = this->findContoursInImage();

    // Itera sobre los contornos detectados
    for (const auto& contour : contours) {
        vector<cv::Point> approx;

        double epsilon = 0.01 * cv::arcLength(contour, true);
        cv::approxPolyDP(contour, approx, epsilon, true);

        PolygonFactory pf(approx);
        auto polygon = pf.createPolygon();

        if (polygon){
            this->polygons.push_back(polygon);
        }
    }
}

void PolygonsDetector::drawTextOnImage(const cv::Point &centroide, const string text,
                                       const cv::Scalar textColor, const cv::Scalar rectColor){
    int fontFace = cv::FONT_HERSHEY_SIMPLEX;
    double fontScale = 0.5;
    int thickness = 2;
    int baseline = 0;

    cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);

    int cx = centroide.x;
    int cy = centroide.y;

    // Para dibujar el rectángulo de fondo
    cv::rectangle(this->resultImage,
                  cv::Point(cx - textSize.width / 2, cy - textSize.height / 2 - baseline),
                  cv::Point(cx + textSize.width / 2, cy + textSize.height / 2 + baseline),
                  rectColor, cv::FILLED);

    // Para escribir el nombre de la figura
    cv::putText(this->resultImage, text,
                cv::Point(cx - textSize.width / 2, cy + textSize.height / 2),
                fontFace, fontScale, textColor, thickness, cv::LINE_AA);
}

void PolygonsDetector::drawPolygonsOnImage(PolygonsDetector::Mode mode){
    // Para convertir a imagen de tres canales y poder pintar con colores.
    if (this->resultImage.channels() == 1)
        cv::cvtColor(this->resultImage, this->resultImage, cv::COLOR_GRAY2BGR);

    Scalar primaryColor;
    Scalar secondaryColor;

    for (const auto& polygon : this->polygons) {
        const vector<cv::Point> &vertices = polygon->getVertices();

        string polygonText = polygon->getName();

        switch(mode){
        case CONTOURS:
            primaryColor = QColorToScalar(QColor(Colors::primaryPink));
            secondaryColor =  QColorToScalar(QColor(Colors::secondaryPink));
            cv::polylines(this->resultImage, vertices, true, primaryColor, 2, cv::LINE_AA);
            break;
        case AREA:
            primaryColor = QColorToScalar(QColor(Colors::primaryPurple));
            secondaryColor = QColorToScalar(QColor(Colors::secondaryPurple));
            polygonText += "-" + std::to_string(static_cast<int>(polygon->area()));
            cv::fillPoly(this->resultImage, vertices, primaryColor, cv::LINE_AA);
            break;
        case PERIMETER:
            primaryColor = QColorToScalar(QColor(Colors::primaryOrange));
            secondaryColor = QColorToScalar(QColor(Colors::secondaryOrange));
            polygonText += "-" + std::to_string(static_cast<int>(polygon->perimeter()));
            cv::polylines(this->resultImage, vertices, true, primaryColor, 2, cv::LINE_AA);
            break;
        }
        this->drawTextOnImage(polygon->centroide(), polygonText, primaryColor, secondaryColor);
    }
}

cv::Scalar PolygonsDetector::QColorToScalar(const QColor &color) {
    return cv::Scalar(color.blue(), color.green(), color.red());  // OpenCV usa BGR
}


// Getters
const Image& PolygonsDetector::getImage() const {
    return *image;
}

const vector<shared_ptr<Polygon>> PolygonsDetector::getPolygons() const {
    return polygons;
}

const cv::Mat& PolygonsDetector::getResultImage() const {
    return resultImage;
}


// Setters
void PolygonsDetector::setPolygons(const vector<shared_ptr<Polygon>>& newPolygons) {
    polygons = newPolygons;
}

void PolygonsDetector::setResultImage(const cv::Mat& newResultImage) {
    resultImage = newResultImage;
}
