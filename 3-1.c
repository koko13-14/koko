#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>
#include <math.h>
#include<locale.h>

/**
 * @brief проверяет,что переменная положительная
 * @param step значение проверяемой переменной
 */
void checkStep(const double step);

/**
 * @brief проверяет, принадлежит ли значение аргумента функции
 * её области определения
 * @param x - аргумент функции
 * @return true, если аргумент принадлежит ООФ, иначе false
 */
bool defineOOF(const double x);

/**
 * @brief рассчитывает значение функции y по заданной формуле
 * @param x значение
 * @return
 */
double getY(const double x);


int main()
{
	setlocale(LC_ALL, "Russian");
	const double start = 0;
	const double end = 2;
	const double step = 0.2;
	for (double x = start; x < end + DBL_EPSILON; x = x + step)
	{
		if (defineOOF(x))
		{
			printf("x = %.2lf, y = %.4lf\n", x, getY(x));
		}
		else
		{
			printf("x = %.2lf, не принадлежит ООФ\n", x);
		}
	}
	return 0;
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Ошибка, шаг должен быть положительным\n");
		abort();
	}
}

bool defineOOF(const double x)
{
	return x > 0;
}

double getY(const double x)
{
	return 0.29 * pow(x, 3) + x - 1.2502;
}
