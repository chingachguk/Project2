#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double arr[3][3]; // ��������� ������ ������ ���� double �������� 3 �� 3
    double sum_main = 0, sum_secondary = 0; // ��������� ���������� ��� �������� ����

    printf("Vvedite znacheniya elementov massiva:\n");

    // ��������� ������ �������, ���������� �������������
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &arr[i][j]);
            if (i == j) { // ���������, ��������� �� ������� �� ������� ���������
                sum_main += arr[i][j];
            }
            if (i + j == 2) { // ���������, ��������� �� ������� �� �������� ���������
                sum_secondary += arr[i][j];
            }
        }
    }

    printf("Summ elemets for osnovnoy diagonaly: %.2f\n", sum_main);
    printf("Summ elemets for pobochnoy diagonaly: %.2f\n", sum_secondary);

    return 0;
}

