#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Point.h"

namespace geometry {

    class Polygon {

    protected:

        std::vector<Point> vertices;

    public:

        /**
        * @brief конструктор, стандартной реализации
        */
        Polygon() = default;

        /**
        * @brief виртуальный деструктор по умлочанию
        */
        virtual ~Polygon() = default;

        /**
        * @brief сериализация в строку
        */
        virtual std::string ToString() const = 0;

        /**
        * @brief высчитывает площадь квадрата
        * @return площадь
        */
        virtual double getArea() const = 0;

        /**
        * @brief высчитывает периметр квадрата
        * @return периметр
        */
        virtual double getPerimeter() const = 0;

        /**
        * @brief находит радиус описанной вокруг квадрата окружности
        * @return радиус
        */
        virtual double getCircumradius() const = 0;

        /**
        * @brief метод чтения из стандартного потока ввода
        */
        virtual void read(std::istream& is) = 0;

        /**
        * @brief получение "разрешения" у класса на доступ к private для вывода
        * @param os
        * @param p - точка, для вывода
        */
        friend std::ostream& operator<<(std::ostream& os, const Polygon& polygon);

        /**
        * @brief получение "разрешения" у класса на доступ к private для ввода
        * @param is
        * @param p - точка, для ввода
        */
        friend std::istream& operator>>(std::istream& is, Polygon& polygon);

        /**
        * @brief сериализация в строку
        */
        static std::string ToString(const Polygon& polygon);

        /**
        * @brief метод чтения из стандартного потока ввода
        */
        static Polygon* readFromStream(std::istream& is);
    };
}
