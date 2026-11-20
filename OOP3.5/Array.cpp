
#include "Array.h"
#include <cstdlib>

// Конструктор без аргументів
Array::Array()
{
    size = 0;

    for (int i = 0; i < MAX_SIZE; i++)
        elements[i] = 0;
}

// Конструктор ініціалізації
Array::Array(int size, double initialValue)
{
    if (size < 1 || size > MAX_SIZE)
    {
        cerr << "Invalid array size!" << endl;
        exit(1);
    }

    this->size = size;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i < size)
            elements[i] = initialValue;
        else
            elements[i] = 0;
    }
}

// Деструктор
Array::~Array()
{
}

// Гетер
int Array::GetSize() const
{
    return size;
}

// Перевірка індексу
bool Array::rangeCheck(int index) const
{
    return index >= 0 && index < size;
}

// Сетер елемента
void Array::SetElement(int index, double value)
{
    if (!rangeCheck(index))
    {
        cerr << "Invalid array index!" << endl;
        exit(1);
    }

    elements[index] = value;
}

// Перевантаження оператора []
double& Array::operator[](int index)
{
    if (!rangeCheck(index))
    {
        cerr << "Invalid array index!" << endl;
        exit(1);
    }

    return elements[index];
}

// Константна версія оператора []
const double& Array::operator[](int index) const
{
    if (!rangeCheck(index))
    {
        cerr << "Invalid array index!" << endl;
        exit(1);
    }

    return elements[index];
}

// Введення масиву
void Array::Input()
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element [" << i << "]: ";
        cin >> elements[i];
    }
}

// Виведення масиву
void Array::Display() const
{
    for (int i = 0; i < size; i++)
    {
        cout << elements[i] << " ";
    }

    cout << endl;
}

// Перетворення до рядка
Array::operator string() const
{
    string result = "[";

    for (int i = 0; i < size; i++)
    {
        result += to_string(elements[i]);

        if (i < size - 1)
            result += ", ";
    }

    result += "]";

    return result;
}

