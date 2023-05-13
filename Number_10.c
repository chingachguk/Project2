#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    system("chcp 1251");
    int numbers[100];
    int count = 0;

    printf("Введите числа через пробел (для окончания ввода введите 0):\n");

    // Чтение чисел из строки
    while (1) {
        int num;
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        numbers[count] = num;
        count++;
    }

    // Вычисление максимального числа с использованием макроса
    int i;
    int max = numbers[0];
    for (i = 1; i < count; i++) {
        max = MAX(max, numbers[i]);
    }

    printf("Максимальное число: %d\n", max);

    return 0;
}