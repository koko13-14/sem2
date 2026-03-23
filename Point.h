#pragma once
#include<iostream>

class Point {
private:

	/*
	* @brief x - координата точки по оси ОХ
	*/
	double x;

	/*
	* @brief y - координата точки по оси ОY
	*/
	double y;

public:

	/*
	* @brief создает точку с координатами x,y
	* @param x - координата точки по оси OX
	* @param y - координата точки по оси OY
	*/
	Point(const double x = 0, const double y = 0);

	/*
	* @brief получение координаты x
	* @return x
	*/
	double getX() const;

	/*
	* @brief получение координаты y
	* @return y
	*/
	double getY() const;

	/*
	* @brief измеряет расстояние до точки
	* @param other - другая точка
	* @return расстояние
	*/
	double distance(const Point& other) const;

	/*
	* @brief получение разрешения у класса на доступ к private для вывода
	* @param os
	* @param p - точка для вывода
	*/
	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	/*
	* @brief получение разрешения у класса на доступ к private для ввода
	* @param is
	* @param p - точка для ввода
	*/
	friend std::istream& operator>>(std::istream& is, Point& p);

	/*
	* @brief оператор ==
	* @return 1 если равно
	*/
	bool operator == (const Point& other) const;

	/*
	* @brief оператор !=
	* @return 1 если не равно
	*/
	bool operator != (const Point& other) const;
};
