#pragma once

class Node {
private:

    /*
    * @brief Значение, хранящееся в узле
    */
    int m_data;          

    /*
    * @brief Указатель на следующий узел
    */
    Node* m_next;       

    /*
    * @brief Указатель на предыдущий узел
    */
    Node* m_previous;    

    // Только Vector имеет доступ к приватным членам Node
    friend class Vector;

public:

    /**
    * @brief Конструктор по умолчанию, создаёт узел со значением 0 и нулевыми указателями
    */
    Node();

    /**
    * @brief Параметризованный конструктор
    * @param data Значение для хранения в узле
    * @param next Указатель на следующий узел
    * @param previous Указатель на предыдущий узел
    */
    explicit Node(int data, Node* next = nullptr, Node* previous = nullptr);

    /**
    * @brief Деструктор
    */
    ~Node();

    /**
    * @brief Получить значение узла
    * @return Константная ссылка на значение
    */
    int getData() const;

    /**
    * @brief Получить указатель на следующий узел
    * @return Указатель на следующий узел
    */
    const Node* getNext() const;

    /**
    * @brief Получить указатель на предыдущий узел
    * @return Указатель на предыдущий узел
    */
    const Node* getPrevious() const;
};
