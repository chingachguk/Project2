#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    system("chcp 1251");
    int numbers[100];
    int count = 0;

    printf("������� ����� ����� ������ (��� ��������� ����� ������� 0):\n");

    // ������ ����� �� ������
    while (1) {
        int num;
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        numbers[count] = num;
        count++;
    }

    // ���������� ������������� ����� � �������������� �������
    int i;
    int max = numbers[0];
    for (i = 1; i < count; i++) {
        max = MAX(max, numbers[i]);
    }

    printf("������������ �����: %d\n", max);

    return 0;
}