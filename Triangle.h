#pragma once
#include<iostream>
#include"Point.h"

using namespace std;

class Triangle {
private:

	/*
	* @brief A,B,C - вершины треугольника с координатами
	*/
	Point A, B, C;

	/*
	* @brief проверка на треугольник
	* @return выводит 0 если не треугольник, иначе 1
	*/
	bool isTriangle() const;

public:

	/*
	* @brief создает треугольник с указанными вершинами, проверяет треугольник
	* @param a - точка 1
	* @param b - точка 2
	* @param c - точка 3
	*/
	Triangle(const Point& a, const Point& b, const Point& c);

	/*
	* @brief высчитывает периметр треугольника
	* @return периметр
	*/
	double getPerimetr() const;

	/*
    * @brief высчитывает площадь треугольника
    * @return площадь
    */
	double getSquare() const;
};
