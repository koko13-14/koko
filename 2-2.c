#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/*
* @brief рассчитывает значение функции y
* @param a значение параметра а
* @param x значение параметра x
* @return считает значение функции y
*/
double getFunctionY(const double x, const double a);

/**
 * @brief Точка входа в программу
 * @param x - вводится значение x
 * @return возвращает 0, если программма выполнена корректно
 */
int main() {
    setlocale(LC_ALL, "Russian");
    const double a = 2.0;
    printf("Введите значение параметра x = ");
    double x = getValue();
    printf("Значение функции = %.2lf", getFunctionY(x, a));
    return 0;
}

double getValue() {
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

double getFunctionY(const double x, const double a) {
    if (x < 1) {
        return 1;
    }
    else if (1 <= x <= 2) {
        return a * pow(x, 2 * log(x));
    }
    else if (x > 2) {
        return exp(a * x) * cos(x);
    }
}
