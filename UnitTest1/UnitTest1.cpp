
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP3.5/Array.cpp"
#include "../OOP3.5/Polinom.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolinomTests
{
    TEST_CLASS(PolinomUnitTests)
    {
    public:

        // Перевірка конструктора без аргументів
        TEST_METHOD(TestDefaultConstructor)
        {
            Polinom p;

            Assert::AreEqual(1, p.GetSize());
            Assert::AreEqual(0.0, p[0], 0.0001);
        }

        // Перевірка конструктора ініціалізації
        TEST_METHOD(TestInitializationConstructor)
        {
            Polinom p(3, 2);

            Assert::AreEqual(3, p.GetSize());
            Assert::AreEqual(2.0, p[0], 0.0001);
            Assert::AreEqual(2.0, p[1], 0.0001);
            Assert::AreEqual(2.0, p[2], 0.0001);
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(TestCopyConstructor)
        {
            Polinom p1(3, 2);
            Polinom p2(p1);

            Assert::AreEqual(p1.GetSize(), p2.GetSize());

            for (int i = 0; i < p1.GetSize(); i++)
                Assert::AreEqual(p1[i], p2[i], 0.0001);
        }

        // Перевірка обчислення значення многочлена
        TEST_METHOD(TestCalculate)
        {
            Polinom p(3, 0);

            p[0] = 1;
            p[1] = 2;
            p[2] = 3;

            // 1 + 2*2 + 3*2^2 = 17
            Assert::AreEqual(17.0, p.Calculate(2), 0.0001);
        }

        // Перевірка додавання
        TEST_METHOD(TestAddition)
        {
            Polinom p1(3, 0);
            Polinom p2(3, 2);

            p1[0] = 1;
            p1[1] = 2;
            p1[2] = 3;

            Polinom result = p1 + p2;

            Assert::AreEqual(3.0, result[0], 0.0001);
            Assert::AreEqual(4.0, result[1], 0.0001);
            Assert::AreEqual(5.0, result[2], 0.0001);
        }

        // Перевірка віднімання
        TEST_METHOD(TestSubtraction)
        {
            Polinom p1(3, 0);
            Polinom p2(3, 2);

            p1[0] = 1;
            p1[1] = 2;
            p1[2] = 3;

            Polinom result = p1 - p2;

            Assert::AreEqual(-1.0, result[0], 0.0001);
            Assert::AreEqual(0.0, result[1], 0.0001);
            Assert::AreEqual(1.0, result[2], 0.0001);
        }

        // Перевірка множення
        TEST_METHOD(TestMultiplication)
        {
            Polinom p1(3, 0);
            Polinom p2(3, 2);

            p1[0] = 1;
            p1[1] = 2;
            p1[2] = 3;

            Polinom result = p1 * p2;

            Assert::AreEqual(5, result.GetSize());
            Assert::AreEqual(2.0, result[0], 0.0001);
            Assert::AreEqual(6.0, result[1], 0.0001);
            Assert::AreEqual(12.0, result[2], 0.0001);
            Assert::AreEqual(10.0, result[3], 0.0001);
            Assert::AreEqual(6.0, result[4], 0.0001);
        }

        // Перевірка диференціювання
        TEST_METHOD(TestDerivative)
        {
            Polinom p(3, 0);

            p[0] = 1;
            p[1] = 2;
            p[2] = 3;

            Polinom result = p.Derivative();

            Assert::AreEqual(2, result.GetSize());
            Assert::AreEqual(2.0, result[0], 0.0001);
            Assert::AreEqual(6.0, result[1], 0.0001);
        }

        // Перевірка інтегрування
        TEST_METHOD(TestIntegral)
        {
            Polinom p(3, 0);

            p[0] = 1;
            p[1] = 2;
            p[2] = 3;

            Polinom result = p.Integral();

            Assert::AreEqual(4, result.GetSize());
            Assert::AreEqual(0.0, result[0], 0.0001);
            Assert::AreEqual(1.0, result[1], 0.0001);
            Assert::AreEqual(1.0, result[2], 0.0001);
            Assert::AreEqual(1.0, result[3], 0.0001);
        }

        // Перевірка оператора присвоювання
        TEST_METHOD(TestAssignment)
        {
            Polinom p1(3, 2);
            Polinom p2;

            p2 = p1;

            Assert::AreEqual(p1.GetSize(), p2.GetSize());

            for (int i = 0; i < p1.GetSize(); i++)
                Assert::AreEqual(p1[i], p2[i], 0.0001);
        }

        // Перевірка +=
        TEST_METHOD(TestAdditionAssignment)
        {
            Polinom p1(3, 1);
            Polinom p2(3, 2);

            p1 += p2;

            for (int i = 0; i < 3; i++)
                Assert::AreEqual(3.0, p1[i], 0.0001);
        }

        // Перевірка -=
        TEST_METHOD(TestSubtractionAssignment)
        {
            Polinom p1(3, 3);
            Polinom p2(3, 2);

            p1 -= p2;

            for (int i = 0; i < 3; i++)
                Assert::AreEqual(1.0, p1[i], 0.0001);
        }

        // Перевірка *=
        TEST_METHOD(TestMultiplicationAssignment)
        {
            Polinom p1(3, 1);
            Polinom p2(3, 2);

            p1 *= p2;

            Assert::AreEqual(5, p1.GetSize());
            Assert::AreEqual(2.0, p1[0], 0.0001);
            Assert::AreEqual(4.0, p1[1], 0.0001);
            Assert::AreEqual(6.0, p1[2], 0.0001);
            Assert::AreEqual(4.0, p1[3], 0.0001);
            Assert::AreEqual(2.0, p1[4], 0.0001);
        }

        // Перевірка оператора ==
        TEST_METHOD(TestEquality)
        {
            Polinom p1(3, 2);
            Polinom p2(3, 2);

            Assert::IsTrue(p1 == p2);
        }

        // Перевірка оператора !=
        TEST_METHOD(TestInequality)
        {
            Polinom p1(3, 2);
            Polinom p2(3, 3);

            Assert::IsTrue(p1 != p2);
        }

        // Перевірка оператора <
        TEST_METHOD(TestLessThan)
        {
            Polinom p1(2, 1);
            Polinom p2(3, 1);

            Assert::IsTrue(p1 < p2);
        }

        // Перевірка оператора >
        TEST_METHOD(TestGreaterThan)
        {
            Polinom p1(3, 3);
            Polinom p2(2, 1);

            Assert::IsTrue(p1 > p2);
        }

        // Перевірка оператора <=
        TEST_METHOD(TestLessOrEqual)
        {
            Polinom p1(3, 2);
            Polinom p2(3, 2);

            Assert::IsTrue(p1 <= p2);
        }

        // Перевірка оператора >=
        TEST_METHOD(TestGreaterOrEqual)
        {
            Polinom p1(3, 2);
            Polinom p2(3, 2);

            Assert::IsTrue(p1 >= p2);
        }

        // Перевірка перетворення до string
        TEST_METHOD(TestStringConversion)
        {
            Polinom p(3, 0);

            p[0] = 1;
            p[1] = 2;
            p[2] = 3;

            string result = static_cast<string>(p);

            Assert::IsTrue(result == "1 + 2x + 3x^2");
        }
    };
}

