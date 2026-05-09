#include <iostream>
#include "Vector.h"
#include <clocale>

using namespace std;

/**
* @brief Точка входа в программу
* @return 0, если программа выполнена успешно
*/
int main() {

    setlocale(LC_ALL, "Russian");

    cout << " Демонстрация работы класса Vector " << endl << endl;

    cout << "1. Создание пустого вектора:" << endl;
    Vector vec1;
    cout << "vec1: " << vec1 << endl;
    cout << "Пустой: " << (vec1.isEmpty() ? "да" : "нет") << endl;
    cout << endl;

    cout << "2. Создание вектора со списком инициализации:" << endl;
    Vector vec2 = { 1, 2, 3, 4, 5 };
    cout << "vec2: " << vec2 << endl;
    cout << "Размер: " << vec2.getSize() << endl;
    cout << "Пустой: " << (vec2.isEmpty() ? "да" : "нет") << endl;
    cout << endl;

    cout << "3. Вставка элементов:" << endl;
    vec2.pushBack(6);
    cout << "После pushBack(6): " << vec2 << endl;
    vec2.insertAt(2, 10);
    cout << "После insertAt(2, 10): " << vec2 << endl;
    vec2.insertAt(0, 0);
    cout << "После insertAt(0, 0): " << vec2 << endl;
    cout << endl;

    cout << "4. Доступ по индексу:" << endl;
    cout << "vec2[0] = " << vec2[0] << endl;
    cout << "vec2[3] = " << vec2[3] << endl;
    vec2[1] = 100;
    cout << "После vec2[1] = 100: " << vec2 << endl;
    cout << endl;

    cout << "5. Поиск элементов:" << endl;
    cout << "Индекс элемента 10: " << vec2.find(10) << endl;
    cout << "Индекс элемента 100: " << vec2.find(100) << endl;
    cout << "Индекс элемента 999: " << vec2.find(999) << " (отсутствует)" << endl;
    cout << endl;

    cout << "6. Удаление элементов:" << endl;
    vec2.removeLast();
    cout << "После removeLast(): " << vec2 << endl;
    vec2.removeAt(2);
    cout << "После removeAt(2): " << vec2 << endl;
    cout << endl;

    cout << "7. Операции сдвига:" << endl;
    Vector vec3 = { 1, 2, 3, 4, 5 };
    cout << "Исходный vec3: " << vec3 << endl;
    vec3 <<= 2;
    cout << "После vec3 <<= 2: " << vec3 << endl;
    vec3 >>= 1;
    cout << "После vec3 >>= 1: " << vec3 << endl;
    cout << endl;

    cout << "8. Конструктор копирования:" << endl;
    Vector vec4(vec3);
    cout << "vec4 (копия vec3): " << vec4 << endl;
    vec4[0] = 99;
    cout << "После изменения vec4[0] = 99:" << endl;
    cout << "vec3: " << vec3 << " (не изменился)" << endl;
    cout << "vec4: " << vec4 << " (изменился)" << endl;
    cout << endl;

    cout << "9. Конструктор перемещения:" << endl;
    Vector vec5(move(vec4));
    cout << "vec5 (перемещение из vec4): " << vec5 << endl;
    cout << "vec4 после перемещения: " << vec4 << endl;
    cout << "vec4 пустой: " << (vec4.isEmpty() ? "да" : "нет") << endl;
    cout << endl;

    cout << "10. Оператор присваивания:" << endl;
    Vector vec6;
    vec6 = vec3;
    cout << "vec6 = vec3: " << vec6 << endl;
    cout << endl;

    cout << "11. Итерация по элементам vec2:" << endl;
    for (size_t i = 0; i < vec2.getSize(); ++i) {
        cout << "vec2[" << i << "] = " << vec2[i] << endl;
    }

    cout << endl << " Демонстрация завершена " << endl;
    return 0;
}
