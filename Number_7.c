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
    struct human array1[4]; // Первый массив
    struct human array2[4]; // Второй массив

    // Ввод элементов первого массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < 4; i++) {
        printf("Элемент %d:\n", i + 1);
        printf("Имя: ");
        scanf("%s", array1[i].firstName);
        printf("Фамилия: ");
        scanf("%s", array1[i].lastName);
        printf("Год рождения: ");
        scanf("%d", &array1[i].yearOfBirth);
    }

    // Копирование элементов первого массива во второй массив
    memcpy(array2, array1, sizeof(array1));

    // Сортировка элементов второго массива по годам рождения
    qsort(array2, 4, sizeof(struct human), compareYearOfBirth);

    // Вывод результатов
    printf("\nУпорядоченный массив:\n");
    for (int i = 0; i < 4; i++) {
        printf("Элемент %d:\n", i + 1);
        printf("Имя: %s\n", array2[i].firstName);
        printf("Фамилия: %s\n", array2[i].lastName);
        printf("Год рождения: %d\n", array2[i].yearOfBirth);
        printf("\n");
    }

    return 0;
}