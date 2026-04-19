#pragma once
#include "Polygon.h"
#include <vector>

namespace geometry {

    class Triangle : public Polygon {

    private:

        /**
        * @brief VERTEX_COUNT - постоянное количество вершин треугольника, для проверки
        */
        static const int VERTEX_COUNT = 3;

        /**
        * @brief проверяет длину динамического массива с вершинами треугольника с
        * постоянным количеством вершин, проверяет неотрицательность сторон,
        * выполнение неравенства треугольника
        * @return true, если все условия выполнены
        */
        bool isValidTriangle() const;

        /**
        * @brief вычисляет длину стороны между двумя точками
        * @param p1 - первая точка
        * @param p2 - вторая точка
        * @return длина стороны
        */
        static double calculateSideLength(const Point& p1, const Point& p2);

    public:

        /**
        * @brief конструктор, создает треугольник по умолчанию
        */
        Triangle();

        /**
        * @brief конструктор, создает треугольник с указанными вершинами, вызывает проверку на треугольник
        * @param p1 - точка 1
        * @param p2 - точка 2
        * @param p3 - точка 3
        */
        Triangle(const Point& p1, const Point& p2, const Point& p3);

        /**
        * @brief конструктор, создает треугольник с указанными координатами вершин,
        * вызывает проверку на треугольник
        * @param x1 - координата по оси x вершины 1
        * @param y1 - координата по оси y вершины 1
        * @param x2 - координата по оси x вершины 2
        * @param y2 - координата по оси y вершины 2
        * @param x3 - координата по оси x вершины 3
        * @param y3 - координата по оси y вершины 3
        */
        Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

        /**
        * @brief сериализация в строку
        */
        std::string ToString() const override;

        /**
        * @brief высчитывает площадь треугольника (по формуле Герона)
        * @return S
        */
        double getArea() const override;

        /**
        * @brief высчитывает периметр треугольника
        * @return P
        */
        double getPerimeter() const override;

        /**
        * @brief высчитывает радиус описанной окружности треугольника
        * @return R
        */
        double getCircumradius() const override;

        /**
        * @brief метод чтения из стандартного потока ввода
        */
        void read(std::istream& is) override;

        /**
        * @brief проверяет треугольники на совпадение
        * @param other - другой треугольник
        * @return true, если треугольники совпадают
        */
        bool operator==(const Triangle& other) const;

        /**
        * @brief проверяет треугольники на несовпадение
        * @param other - другой треугольник
        * @return true, если треугольники не совпадают
        */
        bool operator!=(const Triangle& other) const;

        /**
        * @brief метод сериализации в строку
        */
        static std::string ToString(const Triangle& triangle);

        /**
        * @brief метод чтения из стандартного потока ввода
        */
        static Triangle readFromStream(std::istream& is);
    };

}
