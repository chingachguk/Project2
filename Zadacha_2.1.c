#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[2][2]; // объявляем массив данных типа int размером 2 на 2

    printf("Vvedite znacheniya elementov massiva:\n");

    // заполняем массив данными, введенными пользователем
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // выводим на консоль квадрат данной матрицы
    printf("Kvadrt matrici massiva:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", arr[i][j] * arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}