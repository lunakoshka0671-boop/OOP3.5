
#include "Polinom.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Допоміжна функція: визначає кількість значущих коефіцієнтів
static int effectiveSize(const Polinom& p)
{
    int n = p.GetSize();

    while (n > 1 && p[n - 1] == 0)
        n--;

    return n;
}

// Конструктор без аргументів
Polinom::Polinom() : Array(1, 0)
{
}

// Конструктор ініціалізації
Polinom::Polinom(int size, double initialValue)
    : Array(size, initialValue)
{
}

// Конструктор копіювання
Polinom::Polinom(const Polinom& other)
    : Array(other)
{
}

// Деструктор
Polinom::~Polinom()
{
}

// Обчислення значення многочлена
double Polinom::Calculate(double x) const
{
    double result = 0;

    for (int i = size - 1; i >= 0; i--)
        result = result * x + elements[i];

    return result;
}

// Диференціювання
Polinom Polinom::Derivative() const
{
    int n = effectiveSize(*this);

    if (n == 1)
        return Polinom(1, 0);

    Polinom result(n - 1, 0);

    for (int i = 1; i < n; i++)
        result[i - 1] = i * elements[i];

    return result;
}

// Інтегрування
Polinom Polinom::Integral() const
{
    int n = effectiveSize(*this);

    if (n + 1 > MAX_SIZE)
    {
        cerr << "Integral result exceeds maximum size!" << endl;
        exit(1);
    }

    Polinom result(n + 1, 0);

    for (int i = 0; i < n; i++)
        result[i + 1] = elements[i] / (i + 1);

    return result;
}

// Оператор присвоювання
Polinom& Polinom::operator=(const Polinom& other)
{
    if (this != &other)
    {
        size = other.size;

        for (int i = 0; i < MAX_SIZE; i++)
            elements[i] = other.elements[i];
    }

    return *this;
}

// Операція додавання з присвоюванням
Polinom& Polinom::operator+=(const Polinom& other)
{
    *this = *this + other;
    return *this;
}

// Операція віднімання з присвоюванням
Polinom& Polinom::operator-=(const Polinom& other)
{
    *this = *this - other;
    return *this;
}

// Операція множення з присвоюванням
Polinom& Polinom::operator*=(const Polinom& other)
{
    *this = *this * other;
    return *this;
}

// Оператор додавання
Polinom operator+(const Polinom& a, const Polinom& b)
{
    int n1 = effectiveSize(a);
    int n2 = effectiveSize(b);

    int resultSize = (n1 > n2) ? n1 : n2;

    Polinom result(resultSize, 0);

    for (int i = 0; i < resultSize; i++)
    {
        if (i < n1)
            result[i] += a[i];

        if (i < n2)
            result[i] += b[i];
    }

    return result;
}

// Оператор віднімання
Polinom operator-(const Polinom& a, const Polinom& b)
{
    int n1 = effectiveSize(a);
    int n2 = effectiveSize(b);

    int resultSize = (n1 > n2) ? n1 : n2;

    Polinom result(resultSize, 0);

    for (int i = 0; i < resultSize; i++)
    {
        if (i < n1)
            result[i] += a[i];

        if (i < n2)
            result[i] -= b[i];
    }

    return result;
}

// Оператор множення
Polinom operator*(const Polinom& a, const Polinom& b)
{
    int n1 = effectiveSize(a);
    int n2 = effectiveSize(b);

    int resultSize = n1 + n2 - 1;

    if (resultSize > Polinom::MAX_SIZE)
    {
        cerr << "Multiplication result exceeds maximum size!" << endl;
        exit(1);
    }

    Polinom result(resultSize, 0);

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
            result[i + j] += a[i] * b[j];
    }

    return result;
}

// Оператор рівності
bool operator==(const Polinom& a, const Polinom& b)
{
    int n1 = effectiveSize(a);
    int n2 = effectiveSize(b);

    if (n1 != n2)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (a[i] != b[i])
            return false;
    }

    return true;
}

// Оператор нерівності
bool operator!=(const Polinom& a, const Polinom& b)
{
    return !(a == b);
}

// Оператор менше
bool operator<(const Polinom& a, const Polinom& b)
{
    int n1 = effectiveSize(a);
    int n2 = effectiveSize(b);

    if (n1 != n2)
        return n1 < n2;

    for (int i = n1 - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }

    return false;
}

// Оператор більше
bool operator>(const Polinom& a, const Polinom& b)
{
    return b < a;
}

// Оператор менше або дорівнює
bool operator<=(const Polinom& a, const Polinom& b)
{
    return !(a > b);
}

// Оператор більше або дорівнює
bool operator>=(const Polinom& a, const Polinom& b)
{
    return !(a < b);
}

// Введення многочлена
void Polinom::Input()
{
    cout << "Enter polynomial coefficients:" << endl;

    Array::Input();
}

// Виведення многочлена
void Polinom::Display() const
{
    cout << string(*this) << endl;
}

// Перетворення многочлена до рядка
Polinom::operator string() const
{
    ostringstream result;

    int n = effectiveSize(*this);
    bool first = true;

    for (int i = 0; i < n; i++)
    {
        double coefficient = elements[i];

        if (coefficient == 0)
            continue;

        if (!first)
        {
            if (coefficient > 0)
                result << " + ";
            else
                result << " - ";
        }
        else if (coefficient < 0)
        {
            result << "-";
        }

        double absoluteValue = abs(coefficient);

        if (i == 0 || absoluteValue != 1)
            result << absoluteValue;

        if (i > 0)
        {
            result << "x";

            if (i > 1)
                result << "^" << i;
        }

        first = false;
    }

    if (first)
        result << "0";

    return result.str();
}

