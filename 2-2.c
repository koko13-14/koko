#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#define EPS 1e-9

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
    if (x < 1.0 - EPS) {
        return 1;
    }
    else if (x > 1.0 - EPS && x < 2.0 + EPS) {
        return a * pow(x, 2 * log(x));
    }
    else {
        return exp(a * x) * cos(x);
    }
}
