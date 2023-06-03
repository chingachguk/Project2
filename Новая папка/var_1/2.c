#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для создания квадратной матрицы размера n x n
// и заполнения ее случайными числами от 0 до 9
int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10; // Генерация случайного числа от 0 до 9
        }
    }
    return matrix;
}

// Функция для освобождения памяти, занятой матрицей
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для вычисления суммы всех элементов матрицы
int calculateSum(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    // Задаем начальные значения для генератора случайных чисел
    srand(time(NULL));

    // Открываем файл для записи
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    int n = 2; // Размерность матрицы
    int** matrix;
    int sum1, sum2;

    // Замеряем время начала работы программы
    clock_t start_time = clock();

    do {
        // Создаем и заполняем матрицу
        matrix = createMatrix(n);

        // Вычисляем сумму всех элементов матрицы
        sum1 = calculateSum(matrix, n);

        // Выводим матрицу в файл
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(file, "%d ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "Сумма: %d\n\n", sum1);

        // Освобождаем память, занятую матрицей
        freeMatrix(matrix, n);

        // Создаем и заполняем новую матрицу
        matrix = createMatrix(n);

        // Вычисляем сумму всех элементов новой матрицы
        sum2 = calculateSum(matrix, n);

        // Освобождаем память, занятую новой матрицей
        freeMatrix(matrix, n);
    } while (sum1 != sum2);

    // Закрываем файл
    fclose(file);

    // Замеряем время окончания работы программы
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Выводим время работы программы
    printf("Время работы программы: %f секунд\n", total_time);

    return 0;
}