#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double arr[3][3]; // объ€вл€ем массив данных типа double размером 3 на 3
    double sum_main = 0, sum_secondary = 0; // объ€вл€ем переменные дл€ хранени€ сумм

    printf("Vvedite znacheniya elementov massiva:\n");

    // заполн€ем массив данными, введенными пользователем
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &arr[i][j]);
            if (i == j) { // провер€ем, находитс€ ли элемент на главной диагонали
                sum_main += arr[i][j];
            }
            if (i + j == 2) { // провер€ем, находитс€ ли элемент на побочной диагонали
                sum_secondary += arr[i][j];
            }
        }
    }

    printf("Summ elemets for osnovnoy diagonaly: %.2f\n", sum_main);
    printf("Summ elemets for pobochnoy diagonaly: %.2f\n", sum_secondary);

    return 0;
}

