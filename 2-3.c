#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<float.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/*
* @brief проверка, можно ли разместить грань кирпича a и b в отверстия r, s
* @param a - одно ребро кирпича
* @param b - второе ребро кирпича
* @param r - первая сторона отверстия
* @param s - вторая сторона отверстия
* @return выводит 0 или 1,
* проходит ли грань кирпича в указанное отверстие
*/
double getProhod(const double a, const double b, const double r, const double s);

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void ChekValue(const double value);

/**
 * @brief Точка входа в программу
 * @param x - вводится значение x
 * @param y - вводится значение y
 * @param z - вводится значение z
 * @param r - вводится значение r
 * @param s - вводится значение s
 * @return возвращает 0, если программма выполнена корректно
 */
int main() {
    setlocale(LC_ALL, "Russian");

    printf("Введите значения параметров кирпича x, y, z = ");
    double x = getValue();
    ChekValue(x);
    double y = getValue();
    ChekValue(y);
    double z = getValue();
    ChekValue(z);

    printf("Введите значения параметов отверстия r, s = ");
    double r = getValue();
    ChekValue(r);
    double s = getValue();
    ChekValue(s);
    
    if (getProhod(x, y, r, s) || getProhod(x, z, r, s) || getProhod(y, z, r, s)) {
        printf("Кирпич пройдет через отверстие\n");
    }
    else {
        printf("Кирпич не пройдет через отверстие\n");
    }

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

double getProhod(const double a, const double b, const double r, const double s) {
    return ((a <= r - DBL_EPSILON && b <= s - DBL_EPSILON) || (a <= s - DBL_EPSILON && b <= r - DBL_EPSILON));
}

void ChekValue(const double value) {
    if (value <= 0 - DBL_EPSILON)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
