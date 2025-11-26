#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<locale.h>

/*
 * @brief рассчитывает силу тяжести тела
 * @param m вводится масса мешка с картошкой в кг
 * @param g ускорение свободного падения в м/с^2
 * @return возвращает силу тяжести тела
 */
double getSilaTishesty(const double m, const double g);

/*
 * @brief рассчитывает вес тела
 * @param m вводится масса мешка с картошкой в кг
 * @param g ускорение свободного падения в м/с^2
 * @return возвращает вес тела
 */
double getVes(const double m, const double g);

/*
* @brief точка входа в программу
* @param m вводится масса мешка с картошкой в кг
* @param g ускорение свободного падения в м/с^2
* @return возвращает 0, если прогамма выполнена корректно
*/
int main() {
	const double g = 9.81;
	setlocale(LC_ALL, "Russian");
	double m;
	printf("Введите массу мешка с картошкой\n");
	scanf("%lf", &m);
	printf("Масса мешка с кортошкой = %.2f кг\n", m);
	printf("Ускорение свободного падения = %.2f м/с^2\n", g);
	printf("Сила тяжести тела = %.2f Н\n", getSilaTishesty(m, g));
	printf("Вес тела = %.2f Н\n", getVes(m, g));
	return 0;
}

double getSilaTishesty(const double m, const double g) {
	return m * g;
}

double getVes(const double m, const double g) {
	return m * g;
}

