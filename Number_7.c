#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��������� ��� �������� ���������� � ��������
struct human {
    char firstName[100];
    char lastName[100];
    int yearOfBirth;
};

// ������� ��� ��������� ����� ��������
int compareYearOfBirth(const void* a, const void* b) {
    struct human* personA = (struct human*)a;
    struct human* personB = (struct human*)b;
    return personA->yearOfBirth - personB->yearOfBirth;
}


int main() {
    system("chcp 1251");
    struct human array1[4]; // ������ ������
    struct human array2[4]; // ������ ������

    // ���� ��������� ������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < 4; i++) {
        printf("������� %d:\n", i + 1);
        printf("���: ");
        scanf("%s", array1[i].firstName);
        printf("�������: ");
        scanf("%s", array1[i].lastName);
        printf("��� ��������: ");
        scanf("%d", &array1[i].yearOfBirth);
    }

    // ����������� ��������� ������� ������� �� ������ ������
    memcpy(array2, array1, sizeof(array1));

    // ���������� ��������� ������� ������� �� ����� ��������
    qsort(array2, 4, sizeof(struct human), compareYearOfBirth);

    // ����� �����������
    printf("\n������������� ������:\n");
    for (int i = 0; i < 4; i++) {
        printf("������� %d:\n", i + 1);
        printf("���: %s\n", array2[i].firstName);
        printf("�������: %s\n", array2[i].lastName);
        printf("��� ��������: %d\n", array2[i].yearOfBirth);
        printf("\n");
    }

    return 0;
}