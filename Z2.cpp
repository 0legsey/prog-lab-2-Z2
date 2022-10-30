// Z2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Segment.h"
#include "Point.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#define N 20
using namespace std;

int static_variables() {
    Point point;
    Segment segment;
    Circle circle; 
    Square square;
    Triangle triangle;
    int answer;
    cout << "\n\nВыберите фигуру, параметры которой необходимо посчитать:" << endl;
    cout << "1) Точка\n2) Отрезок\n3) Круг\n4) Квадрат\n5) Треугольник\n6) Возврат в меню выбора режима работы" << endl;
    do {
        cout << "Ответ: ";
        cin >> answer;
    } while (answer < 1 || answer > 6);
    switch (answer) {
    case 1: {
        point.input();
        point.output();
        break;
    }
    case 2: {
        segment.input();
        segment.output();
        break;
    }
    case 3: {
        circle.input();
        circle.output();
        break;
    }
    case 4: {
        square.input();
        square.output();
        break;
    }
    case 5: {
        triangle.input();
        triangle.output();
        break;
    }
    case 6: {
        return 0;
    }
    }
    static_variables();
}

int dynamic_variables() {
    Point* point = new Point;
    Segment* segment = new Segment;
    Circle* circle = new Circle;
    Square* square = new Square;
    Triangle* triangle = new Triangle;
    int answer;
    cout << "\n\nВыберите фигуру, параметры которой необходимо посчитать:" << endl;
    cout << "1) Точка\n2) Отрезок\n3) Круг\n4) Квадрат\n5) Треугольник\n6) Возврат в меню выбора режима работы" << endl;
    do {
        cout << "Ответ: ";
        cin >> answer;
    } while (answer < 1 || answer > 6);
    switch (answer) {
    case 1: {
        point->input();
        point->output();
        break;
    }
    case 2: {
        segment->input();
        segment->output();
        break;
    }
    case 3: {
        circle->input();
        circle->output();
        break;
    }
    case 4: {
        square->input();
        square->output();
        break;
    }
    case 5: {
        triangle->input();
        triangle->output();
        break;
    }
    case 6: {
        delete point;
        delete segment;
        delete circle;
        delete square;
        delete triangle;
        return 0;
    }
    }
    dynamic_variables();
}

int dynamic_array_segment() {
    Segment* segments = new Segment[N];
    int i = 0, answer, number = 0;
    while (1) {
        cout << "\n\nВыберите вариант ответа:" << endl;
        cout << "1) Создать новый отрезок\n2) Вывести на экран существующий отрезок\n3) Возврат в меню выбора режима работы(информация об объектах будет удалена)" << endl;
        do {
            cout << "Ответ: ";
            cin >> answer;
        } while (answer < 1 || answer > 3);
        switch (answer) {
        case 1: {
            segments[i].input();
            i++;
            break;
        }
        case 2: {
            if (i == 0) {
                cout << "Объектов класса нет";
                break;
            }
            else {
                do {
                    cout << "Введите номер объекта: ";
                    cin >> number;
                } while (number < 1 || number > i);
                segments[number - 1].output();
                break;
            }
        }
        case 3: {
            delete[] segments;
            return 0;
        }
        }
    }
    return 0;
}

int array_of_dynamic_segments() {
    Segment* segments[N];
    Segment* one_segment = new Segment;
    int i = 0, n, answer, number;
    while (1) {
        cout << "\n\nВыберите вариант ответа:" << endl;
        cout << "1) Создать новый массив отрезков\n2) Вывести на экран существующий отрезок\n3) Возврат в меню выбора режима работы(массив отрезков будет удалён)" << endl;
        do {
            cout << "Ответ: ";
            cin >> answer;
        } while (answer < 1 || answer > 3);
        switch (answer) {
        case 1: {
            for (i = 0; i < N; i++) {
                segments[i] = 0;
            }
            do {
                cout << "Введите количество отрезков, которые вы хотите создать: ";
                cin >> n;
            } while (n < 1 || n > 20);
            for (i = 0; i < n; i++) {
                Segment* aux_segment = new Segment;
                cout << "Отрезок №" << i + 1 << ":" << endl;
                one_segment->input();
                *aux_segment = *one_segment;
                segments[i] = aux_segment;
                cout << endl;
            }
            break;
        }
        case 2: {
            if (i == 0) {
                cout << "Массив пуст";
                break;
            }
            else {
                do {
                    cout << "Введите номер отрезка: ";
                    cin >> number;
                } while (number < 1 || number > i);
                segments[number - 1]->output();
                break;
            }
        }
        case 3: {
            delete one_segment;
            return 0;
        }
        }
    }
}

int menu() {
    int answer;
    cout << "\nВыберите режим работы программы:" << endl;
    cout << "1) Работа со статическими переменными\n2) Работа с динамическими переменными\n3) Создать динамический массив объектов класса Segment\n4) Создать массив динамических объектов класса Segment\n5) Выход из программы" << endl;
    do {
        cout << "Ответ: ";
        cin >>answer;
    } while (answer < 1 || answer > 5);
    switch (answer) {
    case 1: static_variables(); break;
    case 2: dynamic_variables(); break;
    case 3: dynamic_array_segment(); break;
    case 4: array_of_dynamic_segments(); break;
    case 5: return 0;
    }
    menu();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    menu();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
