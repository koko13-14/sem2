#include<iostream>
#include"Point.h"
#include"Triangle.h"

using namespace std;

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
	A = a;
	B = b;
	C = c;

	if (!isTriangle()) {
		cout << "Ошибка точки не образуют треугольник\n";
		exit(EXIT_FAILURE);
	}
}

bool Triangle::isTriangle() const {

	double ab = A.distance(B);
	double bc = B.distance(C);
	double ca = C.distance(A);

	bool TriangleInequality = (ab + bc > ca) && (ab + ca > bc) && (bc + ca > ab);

	bool NotOneStraightLine = (C.getX() - A.getX()) / (B.getX() - A.getX()) != (C.getY() - A.getY()) / (B.getY() - A.getY());

	bool NePoparnoRavnu = (A != B) && (A != C) && (B != C);

	return TriangleInequality && NotOneStraightLine && NePoparnoRavnu;
}

double Triangle::getPerimetr() const {
	return A.distance(B) + B.distance(C) + C.distance(A);
}

double Triangle::getSquare() const {

	double ab = A.distance(B);
	double bc = B.distance(C);
	double ca = C.distance(A);

	double p = (ab + bc + ca) / 2;

	return sqrt(p * (p - ab) * (p - bc) * (p - ca));
}
