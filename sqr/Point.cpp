#define _USE_MATH_DEFINES
#include <string>
#include <iostream>
#include "Point.h"
#include <cmath>
using namespace std;

namespace geometry {
    Point::Point(const double x, const double y) : x(x), y(y)
    {
    }

    double Point::getX() const
    {
        return x;
    }

    double Point::getY() const
    {
        return y;
    }

    bool Point::operator==(const Point& other) const {
        return std::abs(x - other.x) < numeric_limits<double>::epsilon() && std::abs(y - other.y) < numeric_limits<double>::epsilon();
    }


    std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    std::istream& operator>>(std::istream& is, Point& point) {
        char comma, bracket;
        is >> bracket >> point.x >> comma >> point.y >> bracket;
        return is;
    }
    bool Point::operator!=(const Point& other) const {
        return !(*this == other);
    }
}
