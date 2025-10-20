#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>

/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);

/**
 * @brief рассчитывает коэффициент рекуррентного выражения
 * @param i текущий индекс
 * @return рассчитанное значение коэффициента
 */
double getRecurent(const int i);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите n:");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.4lf\n",
        n, getSumN(n));
    printf("Введите e:");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма последовательности с точностью "
        "%lf равна %.4lf\n",
        e, getSumE(e));

    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getSumN(const int n)
{
    double current = 1.0;
    double result = current;
    for (int i = 0; i < n - 1; i++)
    {
        current *= getRecurent(i);
        result += current;
    }
    return result;
}

double getRecurent(const int i)
{
    return -1.0 / ((i + 1) * (i + 2));
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Error\n");
        exit(1);
    }
}

double getSumE(const double e)
{
    double current = 1.0;
    double result = 0.0;
    for (int i = 0; fabs(current) > e; i++)
    {
        result += current;
        current *= getRecurent(i);
    }
    return result;
}
