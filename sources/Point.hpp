#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{
    class Point {
    private:
        double xValue;
        double yValue;

    public:
        // Constructor
        Point(double xValue, double yValue);

        // Getters
        double getXValue();
        double getYValue();

        // Setters
        void setXValue(double xValue);
        void setYValue(double yValue);

        // Calculates the distance between this point and another point
        double distance(const Point& other) const;

        // Prints the coordinates of this point
        void print() const;

        // Returns the closest point to the destination point, which is at most the given distance from the source point
        Point moveTowards(const Point& source, const Point& destination, double distance) const;
    };
};
#endif // POINT_HPP
