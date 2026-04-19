#include "../Task2/Triangle.h"
#include "../Task2/Point.h"
#include <CppUnitTest.h>
#include <sstream>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace geometry;

namespace Tests
{
    TEST_CLASS(TriangleTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Triangle triangle;
            Assert::IsTrue(true);
        }

        // 2. Тест конструктора с точками
        TEST_METHOD(TestConstructorWithPoints)
        {
            Point p1(0, 0);
            Point p2(3, 0);
            Point p3(0, 4);
            Triangle triangle(p1, p2, p3);

            Assert::AreEqual(12.0, triangle.getPerimeter());
            Assert::AreEqual(6.0, triangle.getArea());
            Assert::AreEqual(2.5, triangle.getCircumradius());
        }

        // 3. Тест конструктора с координатами
        TEST_METHOD(TestConstructorWithCoordinates)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            Assert::AreEqual(12.0, triangle.getPerimeter());
            Assert::AreEqual(6.0, triangle.getArea());
        }

        // 4. Тест конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Triangle original(0, 0, 3, 0, 0, 4);
            Triangle copy(original);

            Assert::AreEqual(original.getPerimeter(), copy.getPerimeter());
            Assert::AreEqual(original.getArea(), copy.getArea());
            Assert::AreEqual(original.getCircumradius(), copy.getCircumradius());
        }

        // 5. Тест оператора присваивания
        TEST_METHOD(TestAssignmentOperator)
        {
            Triangle original(0, 0, 3, 0, 0, 4);
            Triangle assigned;
            assigned = original;

            Assert::AreEqual(original.getPerimeter(), assigned.getPerimeter());
            Assert::AreEqual(original.getArea(), assigned.getArea());
            Assert::AreEqual(original.getCircumradius(), assigned.getCircumradius());
        }

        // 6. Тест самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            double originalPerimeter = triangle.getPerimeter();
            triangle = triangle;
            Assert::AreEqual(originalPerimeter, triangle.getPerimeter());
        }

        // 7. Тест оператора сравнения ==
        TEST_METHOD(TestEqualityOperator)
        {
            Triangle triangle1(0, 0, 3, 0, 0, 4);
            Triangle triangle2(0, 0, 3, 0, 0, 4);
            Triangle triangle3(0, 0, 4, 0, 0, 3);

            Assert::IsTrue(triangle1 == triangle2);
            Assert::IsTrue(triangle1 == triangle3); // Треугольники с одинаковыми вершинами в разном порядке равны
        }

        // 8. Тест оператора сравнения !=
        TEST_METHOD(TestInequalityOperator)
        {
            Triangle triangle1(0, 0, 3, 0, 0, 4);
            Triangle triangle2(0, 0, 3, 0, 0, 4);
            Triangle triangle3(0, 0, 5, 0, 0, 4);

            Assert::IsFalse(triangle1 != triangle2);
            Assert::IsTrue(triangle1 != triangle3);
        }

        // 9. Тест метода getPerimeter()
        TEST_METHOD(TestGetPerimeter)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            Assert::AreEqual(12.0, triangle.getPerimeter());

            Triangle triangle2(0, 0, 6, 0, 0, 8);
            Assert::AreEqual(24.0, triangle2.getPerimeter());
        }

        // 10. Тест метода getArea()
        TEST_METHOD(TestGetArea)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            Assert::AreEqual(6.0, triangle.getArea());

            Triangle triangle2(0, 0, 6, 0, 0, 8);
            Assert::AreEqual(24.0, triangle2.getArea());
        }

        // 11. Тест метода getCircumradius()
        TEST_METHOD(TestGetCircumradius)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            Assert::AreEqual(2.5, triangle.getCircumradius());

            Triangle triangle2(0, 0, 6, 0, 0, 8);
            Assert::AreEqual(5.0, triangle2.getCircumradius());
        }

        // 12. Тест равностороннего треугольника
        TEST_METHOD(TestEquilateralTriangle)
        {
            double side = 3.0;
            double height = side * std::sqrt(3.0) / 2.0;
            Triangle triangle(0, 0, side, 0, side / 2.0, height);

            double expectedPerimeter = 3.0 * side;
            double expectedArea = side * height / 2.0;
            double expectedCircumradius = side / std::sqrt(3.0);

            Assert::AreEqual(expectedPerimeter, triangle.getPerimeter(), 0.0001);
            Assert::AreEqual(expectedArea, triangle.getArea(), 0.0001);
            Assert::AreEqual(expectedCircumradius, triangle.getCircumradius(), 0.0001);
        }

        // 13. Тест метода ToString()
        TEST_METHOD(TestToString)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            std::string result = triangle.ToString();

            Assert::IsTrue(result.find("Triangle") != std::string::npos);
            Assert::IsTrue(result.find("(0, 0)") != std::string::npos);
            Assert::IsTrue(result.find("(3, 0)") != std::string::npos);
            Assert::IsTrue(result.find("(0, 4)") != std::string::npos);
        }

        // 14. Тест статического метода ToString
        TEST_METHOD(TestStaticToString)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            std::string result = Triangle::ToString(triangle);
            Assert::IsTrue(result.find("Triangle") != std::string::npos);
        }

        // 15. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Triangle triangle(0, 0, 3, 0, 0, 4);
            std::stringstream ss;
            ss << triangle;
            std::string result = ss.str();
            Assert::IsTrue(result.find("Triangle") != std::string::npos);
        }

        // 16. Тест оператора ввода >>
        TEST_METHOD(TestInputStreamOperator)
        {
            Triangle triangle;
            std::string input = "(0,0)(3,0)(0,4)";
            std::stringstream ss(input);
            ss >> triangle;

            Assert::AreEqual(12.0, triangle.getPerimeter());
            Assert::AreEqual(6.0, triangle.getArea());
        }

        // 17. Тест метода read()
        TEST_METHOD(TestReadMethod)
        {
            Triangle triangle;
            std::string input = "(0,0)(3,0)(0,4)";
            std::stringstream ss(input);
            triangle.read(ss);

            Assert::AreEqual(12.0, triangle.getPerimeter());
        }

        // 18. Тест статического метода readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input = "(0,0)(3,0)(0,4)";
            std::stringstream ss(input);
            Triangle triangle = Triangle::readFromStream(ss);

            Assert::AreEqual(12.0, triangle.getPerimeter());
        }

        // 19. Тест на некорректный треугольник (точки на одной прямой)
        TEST_METHOD(TestInvalidTriangleCollinearPoints)
        {
            auto func = []() {
                Triangle triangle(0, 0, 1, 1, 2, 2);
                };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 20. Тест на некорректный треугольник (нарушение неравенства треугольника)
        TEST_METHOD(TestInvalidTriangleInequality)
        {
            auto func = []() {
                // Стороны: 2, 3, 6 (2+3 < 6)
                Triangle triangle(0, 0, 2, 0, 0, 6);
                };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 21. Тест на некорректный треугольник (совпадающие точки)
        TEST_METHOD(TestInvalidTriangleCoincidentPoints)
        {
            auto func = []() {
                Triangle triangle(0, 0, 0, 0, 1, 1);
                };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 22. Тест метода getPerimeter с некорректным объектом
        TEST_METHOD(TestGetPerimeterWithInvalidObject)
        {
            Triangle triangle;
            Assert::AreEqual(0.0, triangle.getPerimeter());
        }

        // 23. Тест метода getArea с некорректным объектом
        TEST_METHOD(TestGetAreaWithInvalidObject)
        {
            Triangle triangle;
            Assert::AreEqual(0.0, triangle.getArea());
        }

        // 24. Тест метода getCircumradius с некорректным объектом
        TEST_METHOD(TestGetCircumradiusWithInvalidObject)
        {
            Triangle triangle;
            Assert::AreEqual(0.0, triangle.getCircumradius());
        }

        // 25. Тест полиморфизма через базовый класс
        TEST_METHOD(TestPolymorphism)
        {
            std::unique_ptr<Polygon> polygon = std::make_unique<Triangle>(0, 0, 3, 0, 0, 4);
            Assert::AreEqual(12.0, polygon->getPerimeter());
            Assert::AreEqual(6.0, polygon->getArea());
            Assert::AreEqual(2.5, polygon->getCircumradius());
        }

        // 26. Тест коллекции объектов базового класса
        TEST_METHOD(TestCollectionOfPolygons)
        {
            std::vector<std::unique_ptr<Polygon>> polygons;
            polygons.push_back(std::make_unique<Triangle>(0, 0, 3, 0, 0, 4));
            polygons.push_back(std::make_unique<Triangle>(0, 0, 6, 0, 0, 8));

            Assert::AreEqual(12.0, polygons[0]->getPerimeter());
            Assert::AreEqual(24.0, polygons[1]->getPerimeter());
            Assert::AreEqual(6.0, polygons[0]->getArea());
            Assert::AreEqual(24.0, polygons[1]->getArea());
        }

        // 27. Тест цепочечного присваивания
        TEST_METHOD(TestChainedAssignment)
        {
            Triangle triangle1(0, 0, 3, 0, 0, 4);
            Triangle triangle2, triangle3;
            triangle3 = triangle2 = triangle1;

            Assert::AreEqual(triangle1.getPerimeter(), triangle2.getPerimeter());
            Assert::AreEqual(triangle1.getPerimeter(), triangle3.getPerimeter());
        }
    };

    TEST_CLASS(PointTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Point p(3.5, 7.2);
            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(7.2, p.getY());
        }

        // 3. Тест конструктора с целыми числами
        TEST_METHOD(TestConstructorWithIntegers)
        {
            Point p(5, 10);
            Assert::AreEqual(5.0, p.getX());
            Assert::AreEqual(10.0, p.getY());
        }

        // 4. Тест метода getX()
        TEST_METHOD(TestGetX)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(4.5, p.getX());
        }

        // 5. Тест метода getY()
        TEST_METHOD(TestGetY)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(6.7, p.getY());
        }

        // 6. Тест оператора равенства == (равные точки)
        TEST_METHOD(TestEqualityOperator_EqualPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Assert::IsTrue(p1 == p2);
        }

        // 7. Тест оператора равенства == (разные точки)
        TEST_METHOD(TestEqualityOperator_DifferentPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 4.0);
            Point p3(3.0, 3.5);
            Assert::IsFalse(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        // 8. Тест оператора неравенства !=
        TEST_METHOD(TestInequalityOperator)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Point p3(2.5, 4.0);
            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        // 9. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Point p(3.14, 2.71);
            std::stringstream ss;
            ss << p;
            std::string result = ss.str();
            Assert::IsTrue(result.find("(") != std::string::npos);
            Assert::IsTrue(result.find(")") != std::string::npos);
            Assert::IsTrue(result.find("3.14") != std::string::npos);
            Assert::IsTrue(result.find("2.71") != std::string::npos);
        }

        // 10. Тест оператора вывода << с отрицательными числами
        TEST_METHOD(TestOutputStreamOperator_NegativeNumbers)
        {
            Point p(-5.5, -10.2);
            std::stringstream ss;
            ss << p;
            std::string result = ss.str();
            Assert::IsTrue(result.find("-5.5") != std::string::npos);
            Assert::IsTrue(result.find("-10.2") != std::string::npos);
        }

        // 11. Тест оператора ввода >> (формат (x, y))
        TEST_METHOD(TestInputStreamOperator_ValidFormat)
        {
            Point p;
            std::string input = "(15.5, 20.3)";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(15.5, p.getX());
            Assert::AreEqual(20.3, p.getY());
        }

        // 12. Тест оператора ввода >> с целыми числами
        TEST_METHOD(TestInputStreamOperator_IntegerValues)
        {
            Point p;
            std::string input = "(10, 20)";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(10.0, p.getX());
            Assert::AreEqual(20.0, p.getY());
        }

        // 13. Тест оператора ввода >> с отрицательными числами
        TEST_METHOD(TestInputStreamOperator_NegativeValues)
        {
            Point p;
            std::string input = "(-7.5, -12.3)";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(-7.5, p.getX());
            Assert::AreEqual(-12.3, p.getY());
        }

        // 14. Тест оператора ввода >> с пробелами
        TEST_METHOD(TestInputStreamOperator_WithSpaces)
        {
            Point p;
            std::string input = "( 10 , 20 )";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(10.0, p.getX());
            Assert::AreEqual(20.0, p.getY());
        }

        // 15. Тест оператора ввода >> (несколько точек подряд)
        TEST_METHOD(TestInputStreamOperator_MultiplePoints)
        {
            Point p1, p2;
            std::string input = "(1.0, 2.0)(3.0, 4.0)";
            std::stringstream ss(input);
            ss >> p1 >> p2;
            Assert::AreEqual(1.0, p1.getX());
            Assert::AreEqual(2.0, p1.getY());
            Assert::AreEqual(3.0, p2.getX());
            Assert::AreEqual(4.0, p2.getY());
        }

        // 16. Тест цепочечного вывода
        TEST_METHOD(TestChainedOutputStream)
        {
            Point p1(1.0, 2.0);
            Point p2(3.0, 4.0);
            std::stringstream ss;
            ss << p1 << " " << p2;
            std::string result = ss.str();
            Assert::IsTrue(result.find("(1, 2)") != std::string::npos);
            Assert::IsTrue(result.find("(3, 4)") != std::string::npos);
        }

        // 17. Тест цепочечного ввода
        TEST_METHOD(TestChainedInputStream)
        {
            Point p1, p2;
            std::string input = "(1.0,2.0)(3.0,4.0)";
            std::stringstream ss(input);
            ss >> p1 >> p2;
            Assert::AreEqual(1.0, p1.getX());
            Assert::AreEqual(2.0, p1.getY());
            Assert::AreEqual(3.0, p2.getX());
            Assert::AreEqual(4.0, p2.getY());
        }

        // 18. Тест оператора равенства с очень близкими числами
        TEST_METHOD(TestEqualityOperator_VeryCloseNumbers)
        {
            Point p1(0.1 + 0.2, 0.3);
            Point p2(0.3, 0.3);
            Assert::IsTrue(p1 == p2);
        }

        // 19. Тест оператора неравенства с очень близкими числами
        TEST_METHOD(TestInequalityOperator_VeryCloseNumbers)
        {
            Point p1(0.1 + 0.2, 0.3);
            Point p2(0.3, 0.3);
            Assert::IsFalse(p1 != p2);
        }

        // 20. Тест оператора вывода << с нулевыми координатами
        TEST_METHOD(TestOutputStreamOperator_ZeroCoordinates)
        {
            Point p(0, 0);
            std::stringstream ss;
            ss << p;
            std::string result = ss.str();
            Assert::IsTrue(result.find("0") != std::string::npos);
        }

        // 21. Тест оператора ввода >> с нулевыми координатами
        TEST_METHOD(TestInputStreamOperator_ZeroCoordinates)
        {
            Point p;
            std::string input = "(0, 0)";
            std::stringstream ss(input);
            ss >> p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        // 22. Тест сравнения с самим собой
        TEST_METHOD(TestEqualityOperator_SelfComparison)
        {
            Point p(5.0, 10.0);
            Assert::IsTrue(p == p);
        }

        // 23. Тест транзитивности оператора равенства
        TEST_METHOD(TestEqualityOperator_Transitivity)
        {
            Point p1(2.0, 3.0);
            Point p2(2.0, 3.0);
            Point p3(2.0, 3.0);
            Assert::IsTrue(p1 == p2);
            Assert::IsTrue(p2 == p3);
            Assert::IsTrue(p1 == p3);
        }
    };
}
