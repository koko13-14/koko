#include<stdio.h>
#include<math.h>

/**
* @brief рассчиывает значение функции B
* @param x рассчитывает значение x
* @param y рассчитывает значение y
* @param z рассчитывает значение z
* @return рассчитывает значениe
*/
double getB(const double x, const double y, const double z);


/**
* @brief рассчиывает значение функции A
* @param x рассчитывает значение x
* @param y рассчитывает значение y
* @param z рассчитывает значение z
* @return рассчитывает значениe
*/
double getA(const double x, const double y, const double z);


/**
* @brief точка входа в программу
* @param x - значение константы x
* @param y - значение константы y
* @param z - значение константы z
* @return возвращает 0 если программа выполнена корректно, иначе 1
*/
int main() {
	const double x = 1.825;
	const double y = 18.225;
	const double z = -3.298;
	printf("x = %.3f\n", x);
	printf("y = %.3f\n", y);
	printf("z = %.3f\n", z);
	printf("A = %.3f\n", getA(x, y, z));
	printf("B = %.3f\n", getB(x, y, z));
	return 0;
}

double getA(const double x, const double y, const double z) {
	return pow(x, y / x) - pow(y / x, 1. / 3);
}

double getB(const double x, const double y, const double z) {
	return (y - x) + (((y - z) / (y - x)) / (3 + (pow(z, 2) / 5)));
}
