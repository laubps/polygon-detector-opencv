#include "polygonfactory.h"

PolygonFactory::PolygonFactory(const vector<cv::Point> vertices) : vertices(vertices){
    this->setSidesFromVertices();
    this->setAnglesFromVertices();
}

//Función que crea el objeto según cumpla con las validaciones
shared_ptr<Polygon> PolygonFactory::createPolygon(){

    if (this->isCuadrilateral())
        return handleIsQuadrilateral();
    if (this->isTriangle())
        return handleIsTriangle();
    if (this->getVertices().size() > 4 && this->isCircle())
        return make_shared<Polygon>("Circulo", "Poligono", this->vertices, this->sides, this->angles);

    return nullptr;
}

shared_ptr<Polygon> PolygonFactory::handleIsQuadrilateral() const{

    shared_ptr<Polygon> polygon = make_shared<Polygon>("Cuadrilatero", "Poligono", this->vertices, this->sides, this->angles);

    if (this->isSquare())
        polygon->setName("Cuadrado");
    else if (this->isRectangle())
        polygon = make_shared<Rectangle>(this->vertices, this->sides, this->angles);
    else if (this->isRhombus())
        polygon->setName("Rombo");

    return polygon;
}

shared_ptr<Triangle> PolygonFactory::handleIsTriangle(){

    shared_ptr<Triangle> triangle = make_shared<Triangle>(this->vertices, this->sides, this->angles);

    if (this->isEquilateralTriangle())
        triangle->setName("Triangulo equilatero");
    else if (this->isIsoscelesTriangle())
        triangle->setName("Triangulo isosceles");
    else if (this->isEscalenoTriangle())
        triangle->setName("Triangulo escaleno");

    return triangle;
}

// VALIDACIONES POR FIGURA //
bool PolygonFactory::isCuadrilateral() const{
    return isNumSidesValid(4) && isSumOfAnglesValid(360);
}
bool PolygonFactory::isSquare() const{
    return areSidesEqual() && areAnglesEqualTo(90);
}
bool PolygonFactory::isRectangle() const{
    return areSidesSymetrical() && areAnglesEqualTo(90);
}
bool PolygonFactory::isRhombus() const{
    return areSidesEqual() && areAnglesSymetrical();
}
bool PolygonFactory::isTriangle() const{
    return isNumSidesValid(3) && isSumOfAnglesValid(180);
}
bool PolygonFactory::isEquilateralTriangle() const{
    return areSidesEqual() && areAnglesEqualTo(60);
}
bool PolygonFactory::isIsoscelesTriangle(){
    return isEqualSidesCountValid(2) && isEqualAnglesCountValid(2);
}
bool PolygonFactory::isEscalenoTriangle(){
    return areSidesDifferent() && areAnglesDifferent();
}
bool PolygonFactory::isCircle() const{
    cv::Point2f center;
    double idealCircularity = 0.9;
    float radius;

    // Calcular el círculo mínimo que encierra el contorno.
    cv::minEnclosingCircle(this->vertices, center, radius);

    // Calcula el área del círculo
    double circleArea = CV_PI * radius * radius;

    // Calcula el área del contorno
    double verticesArea = cv::contourArea(this->vertices);

    // Calcula la circularidad
    double circularity = verticesArea / circleArea;

    // Determina si el contorno es suficientemente circular según el umbral
    return circularity >= idealCircularity;
}

// MICRO VALIDACIONES //
bool PolygonFactory::isNumSidesValid(const int targetNumSides) const {
    return sides.size() == targetNumSides ? true : false;
}

bool PolygonFactory::isSumOfAnglesValid(const int targetSum) const{
    double sumOfAngles = 0;

    const double diffTolerance = targetSum * PolygonFactory::TOLERANCE;

    for (auto angle : angles)
        sumOfAngles += angle;

    return std::fabs(sumOfAngles - targetSum) > diffTolerance ? false : true;
}

bool PolygonFactory::areSidesEqual() const{
    const int numVertices = sides.size();

    // Para comprobar si los lados son de igual longitud dentro de un margen del 10%
    double meanLength = accumulate(sides.begin(), sides.end(), 0.0) / numVertices;
    for (double side : sides) {
        if (std::fabs(side - meanLength) > PolygonFactory::TOLERANCE * meanLength)
            return false;
    }

    return true;
}

bool PolygonFactory::areAnglesEqualTo(const int targetAngle) const{
    const double diffTolerance = targetAngle * PolygonFactory::TOLERANCE;

    for (auto angle : angles ){
        if (std::fabs(angle - targetAngle) > diffTolerance)
            return false;
    }

    return true;
}

bool PolygonFactory::areSidesSymetrical() const{
    const int numVertices = sides.size();

    for (int i = 0; i < numVertices / 2; i++) {
        double side = sides[i];
        double oppositeSide = sides[i + numVertices - 2];
        const double diffTolerance = side * PolygonFactory::TOLERANCE;

        if (std::fabs(side - oppositeSide) > diffTolerance )
            return false;
    }

    return true;
}

bool PolygonFactory::areAnglesSymetrical() const{
    int numVertices = angles.size();

    for (int i = 0; i < numVertices / 2; i++) {
        double angle = angles[i];
        double oppositeAngle = angles[i + numVertices - 2];
        const double diffTolerance = angle * PolygonFactory::TOLERANCE;

        if (std::fabs(angle - oppositeAngle) > diffTolerance)
            return false;

    }

    return true;
}

vector<pair<double, int>> PolygonFactory::groupValuesByProximity(const vector<double>& values, double tolerance){
    std::vector<std::pair<double, int>> groups;

    for (double value : values) {
        bool found = false;

        // Buscar en los grupos existentes
        for (auto& [groupValue, count] : groups) {
            double diffTolerance = groupValue * tolerance;

            if (std::fabs(groupValue - value) < diffTolerance) {
                count++;  // Incrementar el contador del grupo
                found = true;
                break;
            }
        }

        // Si no se encuentra ningún grupo que coincida, se crea uno nuevo
        if (!found) {
            groups.push_back({value, 1});
        }
    }

    return groups;
}

bool PolygonFactory::isEqualAnglesCountValid(const int numAngles) {
    vector<pair<double, int>> angleGroups;
    angleGroups = this->groupValuesByProximity(this->angles, PolygonFactory::TOLERANCE);

    for (const auto& [groupValue, count] : angleGroups) {
        if (count == numAngles)
            return true;
    }

    return false;
}


bool PolygonFactory::isEqualSidesCountValid(const int numSides) {
    std::vector<std::pair<double, int>> sideGroups;

    sideGroups = this->groupValuesByProximity(this->sides, PolygonFactory::TOLERANCE);

    for (const auto& [groupValue, count] : sideGroups) {
        if (count == numSides)
            return true;
    }

    return false;
}

bool PolygonFactory::areSidesDifferent() {
    std::vector<std::pair<double, int>> sideGroups;

    sideGroups = this->groupValuesByProximity(this->sides, PolygonFactory::TOLERANCE);

    for (const auto& [groupValue, count] : sideGroups) {
        if (count > 1)
            return false;  // Al menos un grupo tiene más de un lado igual, por lo tanto, no todos son diferentes

    }

    return true;
}

bool PolygonFactory::areAnglesDifferent() {
    std::vector<std::pair<double, int>> angleGroups;

    angleGroups = this->groupValuesByProximity(this->angles, PolygonFactory::TOLERANCE);

    for (const auto& [groupValue, count] : angleGroups) {
        if (count > 1)
            return false;  // Al menos un grupo tiene más de un lado igual, por lo tanto, no todos son diferentes

    }

    return true;
}

void PolygonFactory::setAnglesFromVertices(){
    const int numVertices = vertices.size();
    this->angles.clear();

    for (int i = 0; i < numVertices; i++){
        cv::Point side1 = vertices[(i + numVertices - 1) % numVertices] - vertices[i];
        cv::Point side2 = vertices[(i + 1) % numVertices] - vertices[i];

        double dotProduct = side1.x * side2.x + side1.y * side2.y;
        this->angles.push_back(acos(dotProduct / (cv::norm(side1) * cv::norm(side2))) * 180.0 / CV_PI);
    }
}

void PolygonFactory::setSidesFromVertices(){
    const int numVertices = vertices.size();

    for (int i = 0; i < numVertices; i++)
        this->sides.push_back(cv::norm(vertices[i] - vertices[(i + 1) % numVertices]));
}



