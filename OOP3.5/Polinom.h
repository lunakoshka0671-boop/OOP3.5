
#pragma once
#include "Array.h"

class Polinom : public Array
{
public:
    // Конструктори
    Polinom();
    Polinom(int size, double initialValue = 0);
    Polinom(const Polinom& other);

    // Деструктор
    ~Polinom();

    // Обчислення значення многочлена
    double Calculate(double x) const;

    // Диференціювання
    Polinom Derivative() const;

    // Інтегрування
    Polinom Integral() const;

    // Операція присвоювання
    Polinom& operator=(const Polinom& other);

    // Операції з присвоюванням
    Polinom& operator+=(const Polinom& other);
    Polinom& operator-=(const Polinom& other);
    Polinom& operator*=(const Polinom& other);

    // Дружні арифметичні операції
    friend Polinom operator+(const Polinom& a, const Polinom& b);
    friend Polinom operator-(const Polinom& a, const Polinom& b);
    friend Polinom operator*(const Polinom& a, const Polinom& b);

    // Дружні операції порівняння
    friend bool operator==(const Polinom& a, const Polinom& b);
    friend bool operator!=(const Polinom& a, const Polinom& b);
    friend bool operator<(const Polinom& a, const Polinom& b);
    friend bool operator>(const Polinom& a, const Polinom& b);
    friend bool operator<=(const Polinom& a, const Polinom& b);
    friend bool operator>=(const Polinom& a, const Polinom& b);

    // Введення та виведення
    void Input() override;
    void Display() const override;

    // Перетворення до рядка
    operator string() const override;
};



