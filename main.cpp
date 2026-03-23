#include<iostream>
#include<clocale>
#include"Triangle.h"
#include"Point.h"

using namespace std;

/*
* @brief точка входа в программу
* return 0, если программа выполнена правильно
*/
int main(void) {

	setlocale(LC_ALL, "Russian");

    Point a, b, c;

    cout << "Введите 3 точки треугольника (x y):" << endl;
    cin >> a >> b >> c;

    Triangle t(a, b, c); 

    cout << "Площадь: " << t.getSquare() << endl;
    cout << "Периметр: " << t.getPerimetr() << endl;
    return 0;
}
