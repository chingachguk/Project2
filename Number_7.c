#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для хранения информации о человеке
struct human {
    char firstName[100];
    char lastName[100];
    int yearOfBirth;
};

// Функция для сравнения годов рождения
int compareYearOfBirth(const void* a, const void* b) {
    struct human* personA = (struct human*)a;
    struct human* personB = (struct human*)b;
    return personA->yearOfBirth - personB->yearOfBirth;
}


int main() {
    system("chcp 1251");
    int n = 0; // Количество строк в файле
    struct human* array1 = NULL; // Первый массив
    struct human* array2 = NULL; // Второй массив

    // Определение количества строк в файле
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        n++;
    }
    fclose(file);

    // Выделение памяти для массивов
    array1 = malloc(n * sizeof(struct human));
    array2 = malloc(n * sizeof(struct human));

    // Чтение элементов первого массива из файла
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d", array1[i].firstName, array1[i].lastName, &array1[i].yearOfBirth);
    }
    fclose(file);

    // Копирование элементов первого массива во второй массив
    memcpy(array2, array1, n * sizeof(struct human));

    // Сортировка элементов второго массива по годам рождения
    qsort(array2, n, sizeof(struct human), compareYearOfBirth);

    // Вывод результатов
    printf("\nУпорядоченный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("Элемент %d:\n", i + 1);
        printf("Имя: %s\n", array2[i].firstName);
        printf("Фамилия: %s\n", array2[i].lastName);
        printf("Год рождения: %d\n", array2[i].yearOfBirth);
        printf("\n");
    }

    free(array1);
    free(array2);
    return 0;
}