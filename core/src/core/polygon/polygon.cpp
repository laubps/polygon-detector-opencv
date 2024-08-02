#include "polygon.h"

using namespace std;

Polygon::Polygon(const string &name, const string &family,
                 const vector<cv::Point>& vertices, const vector<double>& sides,
                 const vector<double>& angles)
    : name(name), family(family),
      vertices(vertices),
      sides(sides),
      angles(angles){
}

double Polygon::perimeter() const{
    // cv::arcLength calcula el perímetro de un contorno poligonal
    // El segundo argumento 'true' indica que el polígono está cerrado
    return cv::arcLength(this->vertices, true);
}
double Polygon::area() const{
    // cv::contourArea calcula el área de un contorno poligonal
    // Usando el argumento predeterminado que supone que el contorno está orientado correctamente
    return cv::contourArea(this->vertices);
}
cv::Point Polygon::centroide() const{
    cv::Moments m = cv::moments(vertices, true);
    return cv::Point(static_cast<int>(m.m10 / m.m00), static_cast<int>(m.m01 / m.m00));
}

// Getters
string Polygon::getName() const {
    return name;
}
string Polygon::getFamily() const {
    return family;
}
const vector<double>& Polygon::getSides() const {
    return sides;
}
const vector<cv::Point>& Polygon::getVertices() const {
    return vertices;
}

// Setters
void Polygon::setName(const string &name) {
    this->name = name;
}
void Polygon::setFamily(const string &family) {
    this->family = family;
}
