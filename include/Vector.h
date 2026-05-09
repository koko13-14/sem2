#pragma once

#include "Node.h"
#include <initializer_list>
#include <string>
#include <ostream>

class Vector {
private:

    /*
    * @brief Указатель на первый элемент
    */
    Node* m_head;        

    /*
    * @brief Указатель на последний элемент
    */
    Node* m_tail;        

    /*
    * @brief Текущий размер вектора
    */
    size_t m_size;       

    /**
    * @brief Вспомогательный метод получения узла по индексу
    * @param index Индекс элемента
    * @return Указатель на узел или nullptr при неверном индексе
    */
    Node* getNodeAt(const size_t index) const;

    /**
    * @brief Очистка всей памяти вектора
    */
    void clear();

    /**
    * @brief Копирование данных из другого вектора
    * @param other Исходный вектор
    */
    void copyFrom(const Vector& other);

public:

    /**
    * @brief Конструктор по умолчанию
    * @post Создаёт пустой вектор
    */
    Vector();

    /**
    * @brief Конструктор со списком инициализации
    * @param initList Список инициализации
    */
    Vector(const std::initializer_list initList);

    /**
    * @brief Конструктор копирования
    * @param other Копируемый вектор
    */
    Vector(const Vector& other);

    /**
    * @brief Конструктор перемещения
    * @param other Перемещаемый вектор
    */
    Vector(Vector&& other) noexcept;

    /**
    * @brief Деструктор
    */
    ~Vector();

    /**
    * @brief Оператор присваивания копированием
    * @param other Копируемый вектор
    * @return Ссылка на текущий вектор
    */
    Vector& operator=(const Vector& other);

    /**
    * @brief Оператор присваивания перемещением
    * @param other Перемещаемый вектор
    * @return Ссылка на текущий вектор
    */
    Vector& operator=(Vector&& other) noexcept;

    /**
    * @brief Вставка элемента в конец вектора
    * @param value Вставляемое значение
    */
    void pushBack(int value);

    /**
    * @brief Вставка элемента по индексу
    * @param index Индекс для вставки
    * @param value Вставляемое значение
    */
    void insertAt(const size_t index, const int value);

    /**
    * @brief Удаление последнего элемента
    */
    void removeLast();

    /**
    * @brief Удаление элемента по индексу
    * @param index Индекс удаляемого элемента
    */
    void removeAt(const size_t index);

    /**
    * @brief Поиск первого вхождения элемента
    * @param value Искомое значение
    * @return Индекс элемента или -1 при отсутствии
    */
    int find(const int value) const;

    /**
    * @brief Проверка на пустоту
    * @return true если вектор пуст, иначе false
    */
    bool isEmpty() const;

    /**
    * @brief Получить размер вектора
    * @return Количество элементов
    */
    size_t getSize() const;

    /**
    * @brief Оператор доступа по индексу (константный)
    * @param index Индекс элемента
    * @return Константная ссылка на значение
    */
    int operator[](const size_t index) const;

    /**
    * @brief Оператор доступа по индексу
    * @param index Индекс элемента
    * @return Ссылка на значение
    */
    int& operator[](const size_t index);

    /**
    * @brief Оператор сдвига влево (заполнение нулями)
    * @param positions Количество позиций сдвига
    * @return Ссылка на текущий вектор
    */
    Vector& operator<<=(const size_t positions);

    /**
    * @brief Оператор сдвига вправо (заполнение нулями)
    * @param positions Количество позиций сдвига
    * @return Ссылка на текущий вектор
    */
    Vector& operator>>=(const size_t positions);

    /**
    * @brief Преобразование вектора в строку
    * @return Строковое представление вектора
    */
    std::string toString() const;

    /**
    * @brief оператор вывода 
    * @param os 
    * @param vector - очередь для вывода
    */
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);
};
