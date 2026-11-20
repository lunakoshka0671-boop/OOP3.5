
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Array
{
protected:
    static const int MAX_SIZE = 100;

    double elements[MAX_SIZE];
    int size;

public:
    // Конструктори
    Array();
    Array(int size, double initialValue = 0);

    // Деструктор
    virtual ~Array();

    // Гетер
    int GetSize() const;

    // Сетер
    void SetElement(int index, double value);

    // Перевірка індексу
    bool rangeCheck(int index) const;

    // Перевантаження індексування
    double& operator[](int index);
    const double& operator[](int index) const;

    // Введення та виведення
    virtual void Input();
    virtual void Display() const;

    // Перетворення до рядка
    virtual operator string() const;
};


