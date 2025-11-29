#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<locale.h>

/*
* @brief проверяет k
* @param k - параметр k
* @return завершает программу, чтобы она не продолжала с неккоректным k
*/
void CheckK(int k);

/**
* @brief проверяет на NULL pointer
* @param ptr - указатель
* @param fName - имя функции
* @param pName - имя параметра
* @return выводит ошибку если указатель равен NULL и немедленно завершает программу
*/
void CheckNullPointer(const void* ptr, const char* fName, const char* pName);

/**
 * @brief Ввод данных типа int
 * @return Введенное значение
 */
int Value(void);

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
* @param start - начало диапазона массива
* @param end - конец диапазона массива
* @return создает случайный массив
*/
void fillRandom(int* arr, const size_t size, int start, int end);

/*
* @brief заменяет первый отрицательный элемент массива на максимальный по модулю элемент
* @param arr - указатель на исходных массив 
* @param size - размер массива
* @return массив с замененным первым элементом
*/
void replaceFirstNegativeWithMaxAbs(int* arr, const size_t size);

/*
* @brief вставляет число К до и после каждого элемента массива, который оканчивается на цифру К по модулю
* @param arr - адрес указателя на массив
* @param size - адрес переменной,в которой хранится размер массива
* @param K - число, которое нужно вставлять
* @return массив со вставленным числом К до и после каждого элемента массива, который оканчивается на эту цифру по модулю
*/
void insertKBeforeAndAfter(int** arr, size_t* size, int K);

/*
* @brief создает массив А на основе массива D по заданной формуле
* @param D - исходный массив
* @param A - новый массив, куда будут записываться результаты
* @param size - количество элементов
* @return массив А
*/
void formArrayA(const int* D, int* A, const size_t size);

/**
* @param RANDOM - значение 1, случайное заполнение числами в заданном диапазоне
* @param MANUAL - значение 2, ручной ввод элементов массива с клавиатуры
*/
enum { RANDOM = 1, MANUAL = 2 };

/**
 * @brief Точка входа в программу
 * @param size - хранит размер массива, который пользователь вводит с клавиатуры
 * @param arr - динамически выделяемый основной массив целых чисел
 * @param choise - определяет способ заполнения массива: 1 - случайно, 2 - вручную
 * @param К - число, которое нужно вставлять до и после каждого элемента массива, который оканчивается на цифру К по модулю
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    srand((unsigned)time(NULL));

    setlocale(LC_ALL, "Russian");
    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    CheckNullPointer(arr, "main", "arr");
    printf("Выберите способ заполнения массива:\n"
        "%d случайными числамиб %d вручную ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        printf("Введите начало диапазона: ");
        const int start = Value();
        printf("Введите конец диапазона: ");
        const int end = Value();
        fillRandom(arr, size, start, end);
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

    // 1) Замена первого отрицательного на максимальный по модулю
    replaceFirstNegativeWithMaxAbs(arr, size);
    printf("\n1) После замены первого отрицательного на максимальный по модулю:\n");
    printArray(arr, size);

    // 2) Вставить число K до и после всех элементов, заканчивающихся на цифру K
    printf("\nВведите число K: ");
    int K = Value();
    CheckK(K);
    insertKBeforeAndAfter(&arr, &size, K);
    printf("\n2) После вставки K до и после элементов, оканчивающихся на цифру %d:\n", K);
    printArray(arr, size);

    // 3) Формируем массив A по правилу
    int* A = malloc(size * sizeof(int));
    if (!A) {
        printf("Ошибка выделения памяти для массива A!\n");
        free(arr);
        exit(1);
    }

    formArrayA(arr, A, size);
    printf("\n3) Сформированный массив A:\n");
    printArray(A, size);

    free(arr);
    free(A);
    return 0;
}

void CheckK(int k)
{
    if (k < 0) {
        printf("Ошибка: значение k не может быть отрицательным\n");
        exit(1);
    }
}

void CheckNullPointer(const void* ptr, const char* fName, const char* pName)
{
    if (ptr == NULL) {
        printf("Ошибка: NULL указатель передан в функцию %s (параметр: %s).\n", fName, pName);
        exit(1);
    }
}

int Value(void)
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
    CheckNullPointer(message, "getSize", "message");
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
    CheckNullPointer(arr, "fillArray", "arr");
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент [%zu] массива = ", i);
        arr[i] = Value();
    }
}

void printArray(int* arr, const size_t size)
{
    CheckNullPointer(arr, "printArray", "arr");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n ");
}

void fillRandom(int* arr, const size_t size, int start, int end)
{
    CheckNullPointer(arr, "fillRandom", "arr");
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % (end - start + 1)) + start;
    }
}

void replaceFirstNegativeWithMaxAbs(int* arr, const size_t size)
{
    CheckNullPointer(arr, "replaceFirstNegativeWithMaxAbs", "arr");
    int maxAbs = abs(arr[0]);
    for (size_t i = 1; i < size; i++)
        if (abs(arr[i]) > maxAbs)
            maxAbs = abs(arr[i]);

    for (size_t i = 0; i < size; i++) {
        if (arr[i] < 0) {
            arr[i] = maxAbs;
            return;
        }
    }
}

void insertKBeforeAndAfter(int** arr, size_t* size, int K)
{
    CheckNullPointer(arr, "insertKBeforeAndAfter", "arr");
    size_t newSize = *size;
    long long count = 0;

    for (size_t i = 0; i < *size; i++) {
        int lastDigit = abs((*arr)[i]) % 10;
        if (lastDigit == abs(K) % 10) {
            count++;
        }
    }

    if (count == 0) {
        return;
    }
    newSize = *size + count * 2;
    int* newArr = malloc(newSize * sizeof(int));

    size_t j = 0;
    for (size_t i = 0; i < *size; i++) {
        int lastDigit = abs((*arr)[i]) % 10;
        if (lastDigit == abs(K) % 10) {
            if (j + 3 <= newSize) {
                newArr[j++] = K;
                newArr[j++] = (*arr)[i];
                newArr[j++] = K;
            }
        }
        else {
            if (j + 1 <= newSize) {
                newArr[j++] = (*arr)[i];
            }
        }
    }

    if (j != newSize) {
        for (; j < newSize; j++) {
            newArr[j] = 0;
        }
    }

    free(*arr);
    *arr = newArr;
    *size = newSize;
}

void formArrayA(const int* D, int* A, const size_t size)
{
    CheckNullPointer(D, "formArrayA", "D");
    if (size == 0) {
        return;
    }
    for (size_t i = 0; i < size; i++) {
        size_t pos = i + 1;
        if (pos % 2 == 0) {
            A[i] = D[i] / (int)pos;
        }
        else {
            A[i] = D[i] * 2;
        }
    }
}
