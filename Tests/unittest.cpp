#include "CppUnitTest.h"
#include "../Task3/Vector.h"
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorTests
{
    TEST_CLASS(VectorConstructorTests)
    {
    public:
        /**
         * @brief Тест конструктора по умолчанию
         * Проверяет, что создаётся пустой вектор
         */
        TEST_METHOD(DefaultConstructor_CreatesEmptyVector)
        {
            Vector vec;
            
            Assert::IsTrue(vec.isEmpty());
            Assert::AreEqual(size_t(0), vec.getSize());
            Assert::AreEqual(std::string("[]"), vec.toString());
        }

        /**
         * @brief Тест конструктора со списком инициализации
         * Проверяет корректное создание вектора из списка
         */
        TEST_METHOD(InitializerListConstructor_CreatesVectorWithElements)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            Assert::IsFalse(vec.isEmpty());
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(3, vec[2]);
            Assert::AreEqual(4, vec[3]);
            Assert::AreEqual(5, vec[4]);
        }

        /**
         * @brief Тест конструктора с пустым списком инициализации
         */
        TEST_METHOD(InitializerListConstructor_EmptyList_CreatesEmptyVector)
        {
            Vector vec = {};
            
            Assert::IsTrue(vec.isEmpty());
            Assert::AreEqual(size_t(0), vec.getSize());
        }

        /**
         * @brief Тест конструктора копирования
         * Проверяет глубокое копирование вектора
         */
        TEST_METHOD(CopyConstructor_CreatesDeepCopy)
        {
            Vector original = {1, 2, 3};
            Vector copy(original);
            
            Assert::AreEqual(original.getSize(), copy.getSize());
            Assert::AreEqual(original[0], copy[0]);
            Assert::AreEqual(original[1], copy[1]);
            Assert::AreEqual(original[2], copy[2]);
            
            // Проверка независимости копии
            copy[0] = 100;
            Assert::AreEqual(1, original[0]);  // Оригинал не изменился
            Assert::AreEqual(100, copy[0]);    // Копия изменилась
        }

        /**
         * @brief Тест конструктора перемещения
         * Проверяет корректное перемещение ресурсов
         */
        TEST_METHOD(MoveConstructor_TransfersOwnership)
        {
            Vector original = {1, 2, 3};
            Vector moved(std::move(original));
            
            Assert::AreEqual(size_t(3), moved.getSize());
            Assert::AreEqual(1, moved[0]);
            Assert::AreEqual(2, moved[1]);
            Assert::AreEqual(3, moved[2]);
            
            // Исходный вектор должен быть пустым
            Assert::IsTrue(original.isEmpty());
            Assert::AreEqual(size_t(0), original.getSize());
        }
    };

    TEST_CLASS(VectorInsertionTests)
    {
    public:
        /**
         * @brief Тест вставки в конец вектора
         */
        TEST_METHOD(PushBack_AddsElementToEnd)
        {
            Vector vec;
            
            vec.pushBack(10);
            Assert::AreEqual(size_t(1), vec.getSize());
            Assert::AreEqual(10, vec[0]);
            
            vec.pushBack(20);
            Assert::AreEqual(size_t(2), vec.getSize());
            Assert::AreEqual(20, vec[1]);
            
            vec.pushBack(30);
            Assert::AreEqual(size_t(3), vec.getSize());
            Assert::AreEqual(30, vec[2]);
        }

        /**
         * @brief Тест вставки в начало вектора
         */
        TEST_METHOD(InsertAt_Beginning_AddsElementCorrectly)
        {
            Vector vec = {1, 2, 3};
            
            vec.insertAt(0, 0);
            
            Assert::AreEqual(size_t(4), vec.getSize());
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(1, vec[1]);
            Assert::AreEqual(2, vec[2]);
            Assert::AreEqual(3, vec[3]);
        }

        /**
         * @brief Тест вставки в середину вектора
         */
        TEST_METHOD(InsertAt_Middle_AddsElementCorrectly)
        {
            Vector vec = {1, 2, 4, 5};
            
            vec.insertAt(2, 3);
            
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(3, vec[2]);
            Assert::AreEqual(4, vec[3]);
            Assert::AreEqual(5, vec[4]);
        }

        /**
         * @brief Тест вставки в конец через insertAt
         */
        TEST_METHOD(InsertAt_End_AddsElementCorrectly)
        {
            Vector vec = {1, 2, 3};
            
            vec.insertAt(3, 4);
            
            Assert::AreEqual(size_t(4), vec.getSize());
            Assert::AreEqual(4, vec[3]);
        }

        /**
         * @brief Тест вставки за пределами вектора
         */
        TEST_METHOD(InsertAt_InvalidIndex_ThrowsException)
        {
            Vector vec = {1, 2, 3};
            
            auto func = [&vec]() { vec.insertAt(10, 100); };
            Assert::ExpectException<std::out_of_range>(func);
        }
    };

    TEST_CLASS(VectorRemovalTests)
    {
    public:
        /**
         * @brief Тест удаления последнего элемента
         */
        TEST_METHOD(RemoveLast_RemovesLastElement)
        {
            Vector vec = {1, 2, 3};
            
            vec.removeLast();
            Assert::AreEqual(size_t(2), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            
            vec.removeLast();
            Assert::AreEqual(size_t(1), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            
            vec.removeLast();
            Assert::AreEqual(size_t(0), vec.getSize());
            Assert::IsTrue(vec.isEmpty());
        }

        /**
         * @brief Тест удаления последнего элемента из пустого вектора
         */
        TEST_METHOD(RemoveLast_EmptyVector_ThrowsException)
        {
            Vector vec;
            
            auto func = [&vec]() { vec.removeLast(); };
            Assert::ExpectException<std::out_of_range>(func);
        }

        /**
         * @brief Тест удаления элемента по индексу из начала
         */
        TEST_METHOD(RemoveAt_Beginning_RemovesCorrectly)
        {
            Vector vec = {1, 2, 3, 4};
            
            vec.removeAt(0);
            
            Assert::AreEqual(size_t(3), vec.getSize());
            Assert::AreEqual(2, vec[0]);
            Assert::AreEqual(3, vec[1]);
            Assert::AreEqual(4, vec[2]);
        }

        /**
         * @brief Тест удаления элемента по индексу из середины
         */
        TEST_METHOD(RemoveAt_Middle_RemovesCorrectly)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            vec.removeAt(2);
            
            Assert::AreEqual(size_t(4), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(4, vec[2]);
            Assert::AreEqual(5, vec[3]);
        }

        /**
         * @brief Тест удаления элемента по индексу из конца
         */
        TEST_METHOD(RemoveAt_End_RemovesCorrectly)
        {
            Vector vec = {1, 2, 3};
            
            vec.removeAt(2);
            
            Assert::AreEqual(size_t(2), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
        }

        /**
         * @brief Тест удаления по неверному индексу
         */
        TEST_METHOD(RemoveAt_InvalidIndex_ThrowsException)
        {
            Vector vec = {1, 2, 3};
            
            auto func = [&vec]() { vec.removeAt(10); };
            Assert::ExpectException<std::out_of_range>(func);
        }
    };

    TEST_CLASS(VectorSearchTests)
    {
    public:
        /**
         * @brief Тест поиска существующего элемента
         */
        TEST_METHOD(Find_ExistingElement_ReturnsCorrectIndex)
        {
            Vector vec = {10, 20, 30, 40, 50};
            
            Assert::AreEqual(0, vec.find(10));
            Assert::AreEqual(2, vec.find(30));
            Assert::AreEqual(4, vec.find(50));
        }

        /**
         * @brief Тест поиска несуществующего элемента
         */
        TEST_METHOD(Find_NonExistingElement_ReturnsNegativeOne)
        {
            Vector vec = {1, 2, 3};
            
            Assert::AreEqual(-1, vec.find(100));
            Assert::AreEqual(-1, vec.find(-5));
        }

        /**
         * @brief Тест поиска в пустом векторе
         */
        TEST_METHOD(Find_EmptyVector_ReturnsNegativeOne)
        {
            Vector vec;
            
            Assert::AreEqual(-1, vec.find(42));
        }

        /**
         * @brief Тест поиска первого вхождения при дубликатах
         */
        TEST_METHOD(Find_DuplicateElements_ReturnsFirstOccurrence)
        {
            Vector vec = {1, 2, 3, 2, 4, 2};
            
            Assert::AreEqual(1, vec.find(2));  // Первое вхождение
        }
    };

    TEST_CLASS(VectorOperatorTests)
    {
    public:
        /**
         * @brief Тест оператора доступа по индексу
         */
        TEST_METHOD(IndexOperator_ValidIndex_ReturnsElement)
        {
            Vector vec = {10, 20, 30};
            
            Assert::AreEqual(10, vec[0]);
            Assert::AreEqual(20, vec[1]);
            Assert::AreEqual(30, vec[2]);
        }

        /**
         * @brief Тест изменения элемента через оператор индексации
         */
        TEST_METHOD(IndexOperator_ModifyElement_ChangesValue)
        {
            Vector vec = {1, 2, 3};
            
            vec[1] = 100;
            
            Assert::AreEqual(100, vec[1]);
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(3, vec[2]);
        }

        /**
         * @brief Тест оператора доступа с неверным индексом
         */
        TEST_METHOD(IndexOperator_InvalidIndex_ThrowsException)
        {
            Vector vec = {1, 2, 3};
            
            auto func = [&vec]() { vec[10]; };
            Assert::ExpectException<std::out_of_range>(func);
        }

        /**
         * @brief Тест оператора присваивания копированием
         */
        TEST_METHOD(AssignmentOperator_Copy_CreatesIndependentCopy)
        {
            Vector vec1 = {1, 2, 3};
            Vector vec2;
            
            vec2 = vec1;
            
            Assert::AreEqual(vec1.getSize(), vec2.getSize());
            Assert::AreEqual(vec1[0], vec2[0]);
            Assert::AreEqual(vec1[1], vec2[1]);
            Assert::AreEqual(vec1[2], vec2[2]);
            
            // Проверка независимости
            vec2[0] = 999;
            Assert::AreEqual(1, vec1[0]);    // Оригинал не изменился
            Assert::AreEqual(999, vec2[0]);  // Копия изменилась
        }

        /**
         * @brief Тест оператора присваивания перемещением
         */
        TEST_METHOD(AssignmentOperator_Move_TransfersOwnership)
        {
            Vector vec1 = {1, 2, 3};
            Vector vec2;
            
            vec2 = std::move(vec1);
            
            Assert::AreEqual(size_t(3), vec2.getSize());
            Assert::AreEqual(1, vec2[0]);
            Assert::AreEqual(2, vec2[1]);
            Assert::AreEqual(3, vec2[2]);
            
            // Исходный вектор должен быть пустым
            Assert::IsTrue(vec1.isEmpty());
        }

        /**
         * @brief Тест самоприсваивания
         */
        TEST_METHOD(AssignmentOperator_SelfAssignment_NoChanges)
        {
            Vector vec = {1, 2, 3};
            
            vec = vec;  // Самоприсваивание
            
            Assert::AreEqual(size_t(3), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(3, vec[2]);
        }
    };

    TEST_CLASS(VectorShiftTests)
    {
    public:
        /**
         * @brief Тест сдвига влево
         */
        TEST_METHOD(LeftShift_ShiftsElementsAndFillsWithZeros)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            vec <<= 2;
            
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(3, vec[0]);
            Assert::AreEqual(4, vec[1]);
            Assert::AreEqual(5, vec[2]);
            Assert::AreEqual(0, vec[3]);
            Assert::AreEqual(0, vec[4]);
        }

        /**
         * @brief Тест сдвига вправо
         */
        TEST_METHOD(RightShift_ShiftsElementsAndFillsWithZeros)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            vec >>= 2;
            
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(0, vec[1]);
            Assert::AreEqual(1, vec[2]);
            Assert::AreEqual(2, vec[3]);
            Assert::AreEqual(3, vec[4]);
        }

        /**
         * @brief Тест сдвига влево на весь размер
         */
        TEST_METHOD(LeftShift_AllElements_EmptiesVector)
        {
            Vector vec = {1, 2, 3};
            
            vec <<= 3;
            
            Assert::IsTrue(vec.isEmpty());
            Assert::AreEqual(size_t(0), vec.getSize());
        }

        /**
         * @brief Тест сдвига вправо на весь размер
         */
        TEST_METHOD(RightShift_AllElements_EmptiesVector)
        {
            Vector vec = {1, 2, 3};
            
            vec >>= 3;
            
            Assert::IsTrue(vec.isEmpty());
            Assert::AreEqual(size_t(0), vec.getSize());
        }

        /**
         * @brief Тест сдвига на количество больше размера
         */
        TEST_METHOD(Shift_MoreThanSize_EmptiesVector)
        {
            Vector vec = {1, 2, 3};
            
            vec <<= 10;
            
            Assert::IsTrue(vec.isEmpty());
        }

        /**
         * @brief Тест сдвига на 0
         */
        TEST_METHOD(Shift_ZeroPositions_NoChanges)
        {
            Vector vec = {1, 2, 3};
            
            vec <<= 0;
            Assert::AreEqual(size_t(3), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(3, vec[2]);
            
            vec >>= 0;
            Assert::AreEqual(size_t(3), vec.getSize());
            Assert::AreEqual(1, vec[0]);
            Assert::AreEqual(2, vec[1]);
            Assert::AreEqual(3, vec[2]);
        }

        /**
         * @brief Тест комбинированных сдвигов
         */
        TEST_METHOD(Shift_Combined_WorksCorrectly)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            vec <<= 2;  // [3, 4, 5, 0, 0]
            vec >>= 1;  // [0, 3, 4, 5, 0]
            
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(3, vec[1]);
            Assert::AreEqual(4, vec[2]);
            Assert::AreEqual(5, vec[3]);
            Assert::AreEqual(0, vec[4]);
        }
    };

    TEST_CLASS(VectorStringConversionTests)
    {
    public:
        /**
         * @brief Тест преобразования в строку пустого вектора
         */
        TEST_METHOD(ToString_EmptyVector_ReturnsBrackets)
        {
            Vector vec;
            
            Assert::AreEqual(std::string("[]"), vec.toString());
        }

        /**
         * @brief Тест преобразования в строку с одним элементом
         */
        TEST_METHOD(ToString_SingleElement_ReturnsElementInBrackets)
        {
            Vector vec = {42};
            
            Assert::AreEqual(std::string("[42]"), vec.toString());
        }

        /**
         * @brief Тест преобразования в строку с несколькими элементами
         */
        TEST_METHOD(ToString_MultipleElements_ReturnsCommaSeparated)
        {
            Vector vec = {1, 2, 3, 4, 5};
            
            Assert::AreEqual(std::string("[1, 2, 3, 4, 5]"), vec.toString());
        }
    };

    TEST_CLASS(VectorComplexScenarioTests)
    {
    public:
        /**
         * @brief Комплексный тест последовательных операций
         */
        TEST_METHOD(ComplexScenario_SequenceOfOperations)
        {
            // Создание и заполнение
            Vector vec = {10, 20, 30, 40, 50};
            Assert::AreEqual(size_t(5), vec.getSize());
            
            // Вставки
            vec.pushBack(60);
            vec.insertAt(0, 0);
            vec.insertAt(3, 25);
            
            Assert::AreEqual(size_t(8), vec.getSize());
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(10, vec[1]);
            Assert::AreEqual(20, vec[2]);
            Assert::AreEqual(25, vec[3]);
            Assert::AreEqual(60, vec[7]);
            
            // Удаления
            vec.removeAt(0);
            vec.removeLast();
            vec.removeAt(2);
            
            Assert::AreEqual(size_t(5), vec.getSize());
            Assert::AreEqual(10, vec[0]);
            Assert::AreEqual(20, vec[1]);
            Assert::AreEqual(40, vec[2]);
            Assert::AreEqual(50, vec[3]);
            Assert::AreEqual(0, vec.find(70));  // Элемент отсутствует
            
            // Изменение по индексу
            vec[2] = 35;
            Assert::AreEqual(35, vec[2]);
            
            // Сдвиги
            vec <<= 1;
            vec >>= 2;
            
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(0, vec[1]);
            Assert::AreEqual(20, vec[2]);
            Assert::AreEqual(35, vec[3]);
            Assert::AreEqual(0, vec[4]);
            
            // Проверка пустоты
            Assert::IsFalse(vec.isEmpty());
            
            // Полная очистка через сдвиг
            vec <<= 5;
            Assert::IsTrue(vec.isEmpty());
        }

        /**
         * @brief Тест с множеством элементов
         */
        TEST_METHOD(LargeVector_ManyOperations_WorksCorrectly)
        {
            Vector vec;
            
            // Добавление 100 элементов
            for (int i = 0; i < 100; ++i) {
                vec.pushBack(i);
            }
            
            Assert::AreEqual(size_t(100), vec.getSize());
            Assert::AreEqual(0, vec[0]);
            Assert::AreEqual(50, vec[50]);
            Assert::AreEqual(99, vec[99]);
            
            // Поиск элементов
            Assert::AreEqual(42, vec.find(42));
            Assert::AreEqual(0, vec.find(0));
            Assert::AreEqual(99, vec.find(99));
            
            // Удаление всех элементов
            while (!vec.isEmpty()) {
                vec.removeLast();
            }
            
            Assert::AreEqual(size_t(0), vec.getSize());
            Assert::IsTrue(vec.isEmpty());
        }
    };
}
