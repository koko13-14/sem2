#include<iostream>
#include<limits>
#include"Point.h"

using namespace std;

Point::Point(const double x, const double y) {
	this->x = x;
	this->y = y;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

double Point::distance(const Point& other) const {
	double x = this->x - other.x;
	double y = this->y - other.y;
	return sqrt(pow(x, 2) + pow(y, 2));
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << ";" << p.y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
	while (!(is >> p.x >> p.y)) {
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cerr << "Ошибка, введите числа (x y): ";
	}
	return is;
}

bool Point::operator == (const Point& other) const {
	return (this->x == other.x) && (this->y == other.y);
}

bool Point::operator != (const Point& other) const {
	return !(*this == other);
}
