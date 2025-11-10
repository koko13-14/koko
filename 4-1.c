#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

/**
 * @brief Ввод данных типа int
 * @return Введенное значение
 */
int Value();

/*
* @brief ввод размера массива
* @param message - указатель на строку с сообщением, которое будет выведено на экран
* @return выводит размер массива
*/
size_t getSize(char* message);

/*
* @brief ручное заполнение массива
* @param arr - указатель на массив, куда будут записываться введенные элементы
* @param size - размер массива
* @return вручную заполненный массив
*/
void fillArray(int* arr, const size_t size);

/*
* @brief выводит массив на экран
* @param arr - указатель на массив, который нужно вывести
* @param size - количество элементов массива
* @return выводит все элементы массива через пробел
*/
void printArray(int* arr, const size_t size);

/*
* @brief случайное заполнение массива
* @param arr - указатель на массив, который нужно заполнить
* @param size - количество элементов массива
* @return создает случайный массив
*/
void fillRandom(int* arr, const size_t size);

/*
* @brief находит произведения всех четных элементов
* @param arr - указатель на исходных массив (для чтения)
* @param size - размер массива
* @return если четных элементов нет возвращает 0
*/
long long productEvenValues(const int* arr, const size_t size);

/*
* @brief заменяет элементы с нечетным индексом
* @param arr - указатель на массив, который нужно изменить
* @param size - количество элементов массива
* @return квадрат индекса замененного числа
*/
void replaceOddIndexElements(int* arr, const size_t size);

/*
* @brief проверяет, есть ли положительные элементы, у которых остаток от деления на k = 2
* @param arr - указатель на массив (для чтения)
* @param size - размер массива
* @param k - число, на которое проверяется деление
* @return если есть возвращает 1, иначе 0
*/
int PositiveDivisibleWithRemainder2(const int* arr, const size_t size, int k);

enum { RANDOM = 1, MANUAL };

/**
 * @brief Точка входа в программу
 * @param size - хранит размер массива, который пользователь вводит с клавиатуры
 * @param arr - динамически выделяемый основной массив целых чисел
 * @param choise - определяет способ заполнения массива: 1 - случайно, 2 - вручную
 * @param k - число, на которое проверяется деление элементов с остатком 2
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("error");
        exit(1);
    }
    printf("Выберите способ заполнения массива:\n"
        "%d случайными числамиб %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("error");
        free(arr);
        break;
    }

    printArray(arr, size);

    // 1. Произведение элементов с чётным значением
    long long prod = productEvenValues(arr, size);
    printf("\n1) Произведение элементов с чётным значением = %lld\n", prod);

    // 2. Замена элементов с нечётными индексами на квадраты их номеров
    replaceOddIndexElements(arr, size);
    printf("\n2) После замены элементов с нечётными индексами:\n");
    printArray(arr, size);

    // 3. Проверка положительных элементов, делящихся на k с остатком 2
    printf("\nВведите число k: ");
    int k = Value();
    if (PositiveDivisibleWithRemainder2(arr, size, k)) {
        printf("\n3) Есть положительные элементы, делящиеся на %d с остатком 2.\n", k);
    }
    else {
        printf("\n3) Нет таких положительных элементов.\n");
    }

    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("ERROR\n");
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("ERROR");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        int value = 0;
        do {
            printf("Введите элемент [%zu] массива (от -15 до 15) = ", i);
            value = Value();

            if (value < -15 || value >15) {
                printf("Ошибка: число должно быть в диапазоне (от -15 до 15)!\n");
            }
        } while (value < -15 || value >15);

        arr[i] = value;
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n ");
}

void fillRandom(int* arr, const size_t size)
{
    int start = -15;
    int end = 15;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

long long productEvenValues(const int* arr, const size_t size)
{
    long long prod = 1;
    int hasEven = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            prod *= arr[i];
            hasEven = 1;
        }
    }
    if (!hasEven) {
        return 0;
    }
    return prod;
}

void replaceOddIndexElements(int* arr, const size_t size)
{
    for (size_t i = 1; i < size; i += 2)
    {
        arr[i] = (int)(i * i);
    }
}

int PositiveDivisibleWithRemainder2(const int* arr, const size_t size, int k)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] % k == 2) {
            return 1;
        }
    }
    return 0;
}
