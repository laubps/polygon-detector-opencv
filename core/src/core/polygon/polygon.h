#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <tuple>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <unordered_map>
#include <cmath>
#include <unordered_set>

using namespace std;

class Polygon
{
public:
    Polygon(const string &name, const string &family, const vector<cv::Point>& vertices,
            const vector<double>& sides, const vector<double>& angles);
    virtual ~Polygon() {}  // Destructor virtual para la herencia

    double perimeter() const;
    double area() const;
    cv::Point centroide() const;

    // Getters
    string getName() const;
    string getFamily() const;
    const vector<cv::Point> & getVertices() const;
    const vector<double> & getSides() const;

    // Setters
    void setName(const string &name);
    void setFamily(const string &family);

protected:
    string name;
    string family;
    //TODO: Tal vez no es necesario almacenar como miembro los vertices, solo los sides.
    vector<cv::Point> vertices;
    vector<double> sides;
    vector<double> angles;
};

#endif // SHAPE_H
