
#include "Polinom.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Створення об'єктів різними конструкторами
    Polinom p1(3,0);
    Polinom p2(3, 2);
    Polinom p3(p2);

    cout << "Polynomial p1: " << string(p1) << endl;
    cout << "Polynomial p2: " << string(p2) << endl;
    cout << "Polynomial p3: " << string(p3) << endl;

    // Введення коефіцієнтів
    cout << "\nEnter coefficients for p1:" << endl;
    p1.Input();

    cout << "\nPolynomial p1: ";
    p1.Display();

    cout << "\nPolynomial p2: ";
    p2.Display();

    // Арифметичні операції
    cout << "\nAddition: " << string(p1 + p2) << endl;
    cout << "Subtraction: " << string(p1 - p2) << endl;
    cout << "Multiplication: " << string(p1 * p2) << endl;

    // Обчислення значення многочлена
    double x;

    cout << "\nEnter x: ";
    cin >> x;

    cout << "p1(" << x << ") = " << p1.Calculate(x) << endl;

    // Диференціювання та інтегрування
    Polinom derivative = p1.Derivative();
    Polinom integral = p1.Integral();

    cout << "\nDerivative of p1: " << string(derivative) << endl;
    cout << "Integral of p1: " << string(integral) << endl;


    // Операція присвоювання
    Polinom p4;

    p4 = p1;

    cout << "\nAssignment p4 = p1:" << endl;
    p4.Display();

    // Операції присвоювання з арифметичними діями
    Polinom p5(3, 1);

    p5 += p2;
    cout << "\np5 += p2: " << string(p5) << endl;

    p5 -= p2;
    cout << "p5 -= p2: " << string(p5) << endl;

    p5 *= p2;
    cout << "p5 *= p2: " << string(p5) << endl;

    // Операції порівняння
    cout << "\nComparison:" << endl;

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 <= p2: " << (p1 <= p2) << endl;
    cout << "p1 >= p2: " << (p1 >= p2) << endl;


    // Масив об'єктів класу Polinom
    cout << "\nArray of polynomial objects:" << endl;

    Polinom polynomials[3] = {
        Polinom(3, 1),
        Polinom(3, 2),
        Polinom(3, 3)
    };

    // Виведення елементів масиву
    for (int i = 0; i < 3; i++)
    {
        cout << "Polynomial " << i + 1 << ": ";
        polynomials[i].Display();
    }

    // Обчислення значень многочленів з масиву
    cout << "\nCalculating polynomials:" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Polynomial " << i + 1
            << " at x = 2: "
            << polynomials[i].Calculate(2) << endl;
    }

    return 0;
}
