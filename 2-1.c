#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/**
 * @brief рассчитывает периметр прямоугольного треугольника
 * @param side1 первая сторона прямоугольного треугольника
 * @param side2 вторая сторона прямоугольного треугольника
 * @param side3 третья сторона прямоугольного треугольника
 * @return возвращает рассчитанный Периметр
 */
double getPerimitr(const double side1, const double side2, const double side3);

/*
* @brief рассчитывает площадь прямоугольного треугольника
* @param side1 первая сторона прямоугольного треугольника
* @param side2 вторая сторона прямоугольного треугольника
* @param side3 третья сторона прямоугольного треугольника
* @return возвращает рассчитанную площадь
*/
double getPloshad(const double side1, const double side2, const double side3);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void ChekValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void) {
    setlocale(LC_ALL, "Russian");
    printf("Введите стороны прямоугольного треугольника: ");
    double side1 = getValue();
    ChekValue(side1);
    double side2 = getValue();
    ChekValue(side2);
    double side3 = getValue();
    ChekValue(side3);
    printf("Периметр = %.2lf\n", getPerimitr(side1, side2, side3));
    printf("Площадь = %.2lf\n", getPloshad(side1, side2, side3));
	return 0;
}

double getPerimitr(const double side1, const double side2, const double side3) {
    return side1 + side2 + side3;
}

double getPloshad(const double side1, const double side2, const double side3) {
    if (pow(side1, 2) + pow(side3, 2) == pow(side2, 2)) {
        return (side1 * side3) / 2.0;
    }
    else if (pow(side1, 2) + pow(side2, 2) == pow(side3, 2)) {
        return (side1 * side2) / 2.0;
    }
    else if (pow(side3, 2) + pow(side2, 2) == pow(side1, 2)) {
        return (side3 * side2) / 2.0;
    }
    else {
        printf("Треугольник не прямоугольный\n");
        abort();
    }
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

void ChekValue(const double value) {
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
