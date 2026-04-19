#include <iostream>
#include <vector>
#include <memory>
#include "Triangle.h"
#include <clocale>

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена успешно
 */
int main() {
    setlocale(LC_ALL, "Russian");

    try {
        std::cout << "=== Демонстрация работы с классами Polygon и Triangle ===\n\n";

        std::cout << "1. Создание треугольника через точки:\n";
        geometry::Point p1(0, 0);
        geometry::Point p2(3, 0);
        geometry::Point p3(0, 4);
        geometry::Triangle triangle1(p1, p2, p3);
        std::cout << "Треугольник 1: " << triangle1 << "\n";
        std::cout << "Площадь: " << triangle1.getArea() << "\n";
        std::cout << "Периметр: " << triangle1.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << triangle1.getCircumradius() << "\n\n";

        std::cout << "2. Создание треугольника через пары чисел:\n";
        geometry::Triangle triangle2(1, 1, 4, 1, 1, 5);
        std::cout << "Треугольник 2: " << triangle2 << "\n";
        std::cout << "Площадь: " << triangle2.getArea() << "\n";
        std::cout << "Периметр: " << triangle2.getPerimeter() << "\n";
        std::cout << "Радиус описанной окружности: " << triangle2.getCircumradius() << "\n\n";

        std::cout << "3. Коллекция объектов базового типа:\n";
        std::vector<std::unique_ptr<geometry::Polygon>> polygons;
        polygons.push_back(std::make_unique<geometry::Triangle>(triangle1));
        polygons.push_back(std::make_unique<geometry::Triangle>(triangle2));
        polygons.push_back(std::make_unique<geometry::Triangle>(0, 0, 6, 0, 0, 8));

        std::cout << "Итерация по коллекции:\n";
        for (size_t i = 0; i < polygons.size(); ++i) {
            std::cout << "Объект " << (i + 1) << ": " << *polygons[i] << "\n";
            std::cout << "  Площадь: " << polygons[i]->getArea() << "\n";
            std::cout << "  Периметр: " << polygons[i]->getPerimeter() << "\n";
            std::cout << "  Радиус описанной окружности: " << polygons[i]->getCircumradius() << "\n\n";
        }

        std::cout << "4. Демонстрация операторов сравнения:\n";
        geometry::Triangle triangle3(0, 0, 3, 0, 0, 4);
        geometry::Triangle triangle4(0, 0, 3, 0, 0, 4);
        geometry::Triangle triangle5(0, 0, 4, 0, 0, 3);

        std::cout << "triangle3 == triangle4: " << (triangle3 == triangle4 ? "true" : "false") << "\n";
        std::cout << "triangle3 == triangle5: " << (triangle3 == triangle5 ? "true" : "false") << "\n\n";

        std::cout << "5. Демонстрация статического метода ToString:\n";
        std::cout << geometry::Triangle::ToString(triangle1) << "\n\n";

        std::cout << "6. Попытка создания некорректного треугольника (ожидается исключение):\n";
        try {
            geometry::Triangle invalidTriangle(0, 0, 1, 1, 2, 2);
        }
        catch (const std::exception& e) {
            std::cout << "Исключение: " << e.what() << "\n";
        }
        
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма завершена успешно.\n";
    return 0;
}
