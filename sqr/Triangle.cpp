#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <algorithm>

namespace geometry {

    Triangle::Triangle()
    {
    }

    Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    {
        vertices.push_back(p1);
        vertices.push_back(p2);
        vertices.push_back(p3);

        if (!isValidTriangle()) {
            throw std::invalid_argument("Некорректные вершины для треугольника");
        }
    }

    Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        vertices.push_back(Point(x1, y1));
        vertices.push_back(Point(x2, y2));
        vertices.push_back(Point(x3, y3));

        if (!isValidTriangle()) {
            throw std::invalid_argument("Некорректные вершины для треугольника");
        }
    }

    double Triangle::calculateSideLength(const Point& p1, const Point& p2) {
        double dx = p2.getX() - p1.getX();
        double dy = p2.getY() - p1.getY();
        return std::sqrt(dx * dx + dy * dy);
    }

    bool Triangle::isValidTriangle() const {
        if (vertices.size() != VERTEX_COUNT) {
            return false;
        }

        const Point& p1 = vertices[0];
        const Point& p2 = vertices[1];
        const Point& p3 = vertices[2];
        
        double area = 0.5 * std::abs(
            p1.getX() * (p2.getY() - p3.getY()) +
            p2.getX() * (p3.getY() - p1.getY()) +
            p3.getX() * (p1.getY() - p2.getY())
        );

        if (area < std::numeric_limits<double>::epsilon()) {
            return false;
        }

        std::vector<double> sides;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point& pt1 = vertices[i];
            const Point& pt2 = vertices[(i + 1) % vertices.size()];
            double side = calculateSideLength(pt1, pt2);
            
            if (side <= 0) {
                return false;
            }
            sides.push_back(side);
        }

        if (sides[0] + sides[1] <= sides[2] + std::numeric_limits<double>::epsilon() ||
            sides[1] + sides[2] <= sides[0] + std::numeric_limits<double>::epsilon() ||
            sides[2] + sides[0] <= sides[1] + std::numeric_limits<double>::epsilon()) {
            return false;
        }

        return true;
    }

    std::string Triangle::ToString() const {
        std::stringstream ss;
        ss << "Triangle: ";
        for (size_t i = 0; i < vertices.size(); ++i) {
            ss << "v" << (i + 1) << "=" << vertices[i];
            if (i < vertices.size() - 1) {
                ss << ", ";
            }
        }
        return ss.str();
    }

    double Triangle::getArea() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        const Point& p1 = vertices[0];
        const Point& p2 = vertices[1];
        const Point& p3 = vertices[2];

        return 0.5 * std::abs(
            p1.getX() * (p2.getY() - p3.getY()) +
            p2.getX() * (p3.getY() - p1.getY()) +
            p3.getX() * (p1.getY() - p2.getY())
        );
    }

    double Triangle::getPerimeter() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        double perimeter = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            const Point& p1 = vertices[i];
            const Point& p2 = vertices[(i + 1) % vertices.size()];
            perimeter += calculateSideLength(p1, p2);
        }
        return perimeter;
    }

    double Triangle::getCircumradius() const {
        if (vertices.size() != VERTEX_COUNT) {
            return 0.0;
        }

        double a = calculateSideLength(vertices[0], vertices[1]);
        double b = calculateSideLength(vertices[1], vertices[2]);
        double c = calculateSideLength(vertices[2], vertices[0]);

        double area = getArea();

        if (area < std::numeric_limits<double>::epsilon()) {
            return 0.0;
        }

        return (a * b * c) / (4.0 * area);
    }

    void Triangle::read(std::istream& is) {
        std::vector<Point> newVertices;
        newVertices.resize(VERTEX_COUNT);

        for (int i = 0; i < VERTEX_COUNT; ++i) {
            is >> newVertices[i];
        }

        vertices = newVertices;

        if (!isValidTriangle()) {
            throw std::invalid_argument("Некорректные вершины для треугольника при чтении");
        }
    }

    bool Triangle::operator==(const Triangle& other) const {
        if (vertices.size() != other.vertices.size()) {
            return false;
        }

        std::vector<Point> v1 = vertices;
        std::vector<Point> v2 = other.vertices;

        auto pointLess = [](const Point& a, const Point& b) {
            if (std::abs(a.getX() - b.getX()) > std::numeric_limits<double>::epsilon()) {
                return a.getX() < b.getX();
            }
            return a.getY() < b.getY();
            };

        std::sort(v1.begin(), v1.end(), pointLess);
        std::sort(v2.begin(), v2.end(), pointLess);

        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }

    bool Triangle::operator!=(const Triangle& other) const {
        return !(*this == other);
    }

    std::string Triangle::ToString(const Triangle& triangle) {
        return triangle.ToString();
    }

    Triangle Triangle::readFromStream(std::istream& is) {
        Triangle triangle;
        triangle.read(is);
        return triangle;
    }

}
