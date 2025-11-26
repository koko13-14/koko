#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<locale.h>

/**
 * @brief рассчитывает площадь грани куба
 * @param side длина ребра куба
 * @return возвращает рассчитанную площадь грани
 */
double getPloshadGrani(const double side);

/**
 * @brief рассчитывает площадь полной поверхности куба
 * @param side длина ребра куба
 * @return возвращает рассчитанную площадь полной поверхности куба
 */
double getPolnaiaPoverknostCuba(const double side);

/**
 * @brief рассчитывает объем куба
 * @param side длина ребра куба
 * @return возвращает рассчитанный объем куба
 */
double getObiemCuba(const double side);

/**
 * @brief Точка входа в программу
 * @param side вводится длина ребра куба
 * @return возвращает 0, если программма выполнена корректно
 */
int main() {
	setlocale(LC_ALL, "Russian");
	double side;
	printf("Введите длину ребра куба\n");
	scanf("%lf", &side);
	printf("Длина ребра куба = %.2f\n", side);
	printf("Площадь грани куба = %.2f\n", getPloshadGrani(side));
	printf("Полная поверхность куба = %.2f\n", getPolnaiaPoverknostCuba(side));
	printf("Объем куба = %.2f\n", getObiemCuba(side));
	return 0;
}

double getPloshadGrani(const double side) {
	return pow(side, 2);
}

double getPolnaiaPoverknostCuba(const double side) {
	return pow(side, 2) * 6;
}

double getObiemCuba(const double side) {
	return pow(side, 3);
}
