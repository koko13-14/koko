#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf
/**
 * @brief Считывает значение, введенное с клавиатуры с проверкой ввода
 * @return Считанное значение
 */
int Value();
/**
 * @brief Получение размера массива
 * @param message сообщение пользователю
 * @return Размер массива
 */
size_t getSize(char* message);
/**
 * @brief Заполнение массива с клавиатуры
 * @param arr Указатель на массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Вывод массива на экран
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void printArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Заполнение массива случайными числами
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void fillRandom(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Создаёт массив по указанным пользователем вводным данным
 * @param rows количество строк массива
 * @param columns количество столбцов массива
 * @return полученный массив
 */
int** getArray(const size_t rows, const size_t columns);
/**
 * @brief Освобождает память, выделенную под массив
 * @param arr массив
 * @param rows количество строк массива
 */
void freeArray(int** arr, const size_t rows);
/**
 * @brief Проверяет корректность диапазона случайных чисел
 * @param start Начало диапазона
 * @param end Конец диапазона
 */
void checkRange(const int start, const int end);
/**
 * @brief Создаёт копию массива
 * @param arr Исходный массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 * @return Полученный массив
 */
int** copyArray(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Заменяет минимальный по модулю элемент каждого столбца нулём
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 */
void replaceAbs(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Определяет, какие столбцы нужно удалить
 * @param arr Массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов массива
 * @return Количество столбцов для удаления
 */
size_t columnsToDelete(int** arr, const size_t rows, const size_t columns);
/**
 * @brief Удаляет столбцы, в которых первый элемент больше последнего
 * @param arr Исходный массив
 * @param newArr Новый массив
 * @param rows Количество строк массива
 * @param columns Количество столбцов исходного массива
 * @param newCols Количество столбцов после удаления
 */
void deleteColumns(int** arr, int** newArr, const size_t rows, const size_t columns, const size_t newCols);
/**
 * @brief RANDOM - заполнение массива случайными числами
 * @brief MANUAL - заполнение массива вручную.
 */
enum {RANDOM = 1, MANUAL};
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    size_t rows = getSize("Введите количество строк массива: ");
    size_t columns = getSize("Введите количество столбцов массива: ");
    int** arr = getArray(rows, columns);
    printf("Выберите способ заполнения массива:\n"
           "%d - случайными числами\n"
           "%d - вручную\n"
           "Введите нужный номер заполнения: ",
           RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
        case RANDOM:
            fillRandom(arr, rows, columns);
            break;
        case MANUAL:
            fillArray(arr, rows, columns);
            break;
        default:
            printf("Ошибка!\n");
            freeArray(arr, rows);
            break;
    }
    printf("Исходный массив:\n");
    printArray(arr, rows, columns);
    int** copyArr1 = copyArray(arr, rows, columns);
    replaceAbs(copyArr1, rows, columns);
    printf("Массив после замены минимальных по модулю элементов нулём:\n");
    printArray(copyArr1, rows, columns);
    freeArray(copyArr1, rows);
    size_t newCols = columns - columnsToDelete(arr, rows, columns);
    int** copyArr2 = getArray(rows, newCols);
    deleteColumns(arr, copyArr2, rows, columns, newCols);
    printf("Результат удаления столбцов:\n");
    printArray(copyArr2, rows, newCols);
    freeArray(copyArr2, rows);
    freeArray(arr, rows);
    return 0;
}

int Value()
{
    int value = 0;
    if (!scanf_s("%d", &value))
    {
        printf("Ошибка!\n");
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
        printf("Ошибка!");
        abort();
    }
    return (size_t)value;
}

void fillArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("Введите a[%zu,%zu] = ", i, j);
            arr[i][j] = Value();
        }
    }
}

void printArray(int** arr, const size_t rows, const size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fillRandom(int** arr, const size_t rows, const size_t columns)
{
    printf("Введите начало диапазона случайных чисел: ");
    int start = Value();
    printf("Введите конец диапазона случайных чисел: ");
    int end = Value();
    checkRange(start, end);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr[i][j] = (rand() % (end - start + 1)) + start;
        }
    }
}

int** getArray(const size_t rows, const size_t columns)
{
    int** arr = malloc(rows * sizeof(int*));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = malloc(columns * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Ошибка выделения памяти.\n");
            for (size_t j = 0; j < i; j++)
            {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }
    return arr;
}

void freeArray(int** arr, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

void checkRange(const int start, const int end)
{
    if (start > end)
    {
        printf("Ошибка, конец должен быть больше начала!\n");
        exit(1);
    }
}

int** copyArray(int** arr, const size_t rows, const size_t columns)
{
    int** copyArr = getArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    return copyArr;
}

void replaceAbs(int** arr, const size_t rows, const size_t columns)
{
    for (size_t j = 0; j < columns; j++)
    {
        size_t minIndex = 0;
        int minAbs = abs(arr[0][j]);
        for (size_t i = 1; i < rows; i++)
        {
            int curAbs = abs(arr[i][j]);
            if (curAbs < minAbs)
            {
                minAbs = curAbs;
                minIndex = i;
            }
        }
        arr[minIndex][j] = 0;
    }
}

size_t columnsToDelete(int** arr, const size_t rows, const size_t columns)
{
    size_t count = 0;
    for (size_t j = 0; j < columns; j++)
    {
        if (arr[0][j] > arr[rows - 1][j])
        {
            count++;
        }
    }
    return count;
}

void deleteColumns(int** arr, int** newArr, const size_t rows, const size_t columns, const size_t newCols)
{
    size_t k = 0;
    for (size_t j = 0; j < columns; j++)
    {
        if (arr[0][j] <= arr[rows - 1][j])
        {
            for (size_t i = 0; i < rows; i++)
            {
                newArr[i][k] = arr[i][j];
            }
            k++;
        }
    }
}
