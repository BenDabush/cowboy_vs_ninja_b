#include "Point.hpp"
#include <cmath>
#include <iostream>

using namespace std;

using namespace ariel;

// Constructor
Point::Point(double xValue , double yValue ) : xValue(xValue), yValue(yValue) {}

// Getters
double Point::getXValue(){
    return this->xValue;
}
double Point::getYValue(){
    return this->yValue;
}

// Setters
void Point::setXValue(double xValue){
    this->xValue = xValue;;
}
void Point::setYValue(double yValue){
    this->yValue = yValue;;
}

// Calculates the distance between this point and another point
double Point::distance(const Point& other) const {
    if ((abs(xValue) > std::numeric_limits<double>::max() - abs(other.xValue)) ||
    (abs(xValue) > std::numeric_limits<double>::max() - abs(other.xValue))) {
        throw std::overflow_error("Overflow error: distance is too large to calculate");
    }
    double dx = xValue - other.xValue;
    double dy = yValue - other.yValue;
    return sqrt(dx * dx + dy * dy);
}

// Prints the coordinates of this point
void Point::print() const {
    cout << "(" << xValue << ", " << yValue << ")";
}


// Returns the closest point to the destination point, which is at most the given distance from the source point
Point Point::moveTowards(const Point& source, const Point& destination, double distance) const {
    double dist = source.distance(destination);

    if (dist == 0) {
        throw std::runtime_error("Invalid arguments: source and destination points are the same");
    }

    // Distance cannot be negative
    if (distance < 0) {
        throw std::invalid_argument("Invalid arguments: distance cannot be negative");
    }

    // If the distance is less than or equal to the given distance, return the destination point
    if (dist <= abs(distance)) {
        return destination;
    }

    // Calculate the direction and magnitude of the movement vector
    double dx = destination.xValue - source.xValue;
    double dy = destination.yValue - source.yValue;

    // Check for overflow when calculating the magnitude
    double maxMagnitude = std::numeric_limits<double>::max() / dist;
    if (distance > maxMagnitude) {
        throw std::overflow_error("Overflow error: distance is too large to calculate");
    }

    double magnitude = distance / dist;
    dx *= magnitude;
    dy *= magnitude;

    // Return the point that is the result of adding the movement vector to the source point
    return Point(source.xValue + dx, source.yValue + dy);
}

