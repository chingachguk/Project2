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
    int n = 0; // ���������� ����� � �����
    struct human* array1 = NULL; // ������ ������
    struct human* array2 = NULL; // ������ ������

    // ����������� ���������� ����� � �����
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("������ ��� �������� �����\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        n++;
    }
    fclose(file);

    // ��������� ������ ��� ��������
    array1 = malloc(n * sizeof(struct human));
    array2 = malloc(n * sizeof(struct human));

    // ������ ��������� ������� ������� �� �����
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("������ ��� �������� �����\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d", array1[i].firstName, array1[i].lastName, &array1[i].yearOfBirth);
    }
    fclose(file);

    // ����������� ��������� ������� ������� �� ������ ������
    memcpy(array2, array1, n * sizeof(struct human));

    // ���������� ��������� ������� ������� �� ����� ��������
    qsort(array2, n, sizeof(struct human), compareYearOfBirth);

    // ����� �����������
    printf("\n������������� ������:\n");
    for (int i = 0; i < n; i++) {
        printf("������� %d:\n", i + 1);
        printf("���: %s\n", array2[i].firstName);
        printf("�������: %s\n", array2[i].lastName);
        printf("��� ��������: %d\n", array2[i].yearOfBirth);
        printf("\n");
    }

    free(array1);
    free(array2);
    return 0;
}