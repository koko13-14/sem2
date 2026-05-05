#pragma once
#include <iostream>

namespace geometry {

    class Point {

    private:

        /**
        * @brief x - координата точки по оси OX
        */
        double x;

        /**
        * @brief y - координата точки по оси OY
        */
        double y;

    public:

        /**
        * @brief конструктор, создает точку, с координатами x,y
        * @param x - координата точки по оси OX
        * @param y - координата точки по оси OY
        */
        Point(const double x = 0.0, const double y = 0.0);

        /**
        * @brief получение координаты x
        * @return x
        */
        double getX() const;

        /**
        * @brief получение координаты y
        * @return y
        */
        double getY() const;

        /**
        * @brief проверяет точки на совпадение
        * @param other-другая точка
        * @return true, если точки совпадают
        */
        bool operator==(const Point& other) const;

        /**
        * @brief проверяет точки на несовпадение
        * @param other-другая точка
        * @return true, если точки не совпадают
        */
        bool operator!=(const Point& other) const;

        /**
        * @brief получение "разрешения" у класса на доступ к private для вывода
        * @param os
        * @param p - точка, для вывода
        */
        friend std::ostream& operator<<(std::ostream& os, const Point& point);

        /**
        * @brief получение "разрешения" у класса на доступ к private для ввода
        * @param is
        * @param p - точка, для ввода
        */
        friend std::istream& operator>>(std::istream& is, Point& point);

    };
}
