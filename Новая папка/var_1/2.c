#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������� ��� �������� ���������� ������� ������� n x n
// � ���������� �� ���������� ������� �� 0 �� 9
int** createMatrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10; // ��������� ���������� ����� �� 0 �� 9
        }
    }
    return matrix;
}

// ������� ��� ������������ ������, ������� ��������
void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// ������� ��� ���������� ����� ���� ��������� �������
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
    // ������ ��������� �������� ��� ���������� ��������� �����
    srand(time(NULL));

    // ��������� ���� ��� ������
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("�� ������� ������� ����.\n");
        return 1;
    }

    int n = 2; // ����������� �������
    int** matrix;
    int sum1, sum2;

    // �������� ����� ������ ������ ���������
    clock_t start_time = clock();

    do {
        // ������� � ��������� �������
        matrix = createMatrix(n);

        // ��������� ����� ���� ��������� �������
        sum1 = calculateSum(matrix, n);

        // ������� ������� � ����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(file, "%d ", matrix[i][j]);
            }
            fprintf(file, "\n");
        }
        fprintf(file, "�����: %d\n\n", sum1);

        // ����������� ������, ������� ��������
        freeMatrix(matrix, n);

        // ������� � ��������� ����� �������
        matrix = createMatrix(n);

        // ��������� ����� ���� ��������� ����� �������
        sum2 = calculateSum(matrix, n);

        // ����������� ������, ������� ����� ��������
        freeMatrix(matrix, n);
    } while (sum1 != sum2);

    // ��������� ����
    fclose(file);

    // �������� ����� ��������� ������ ���������
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // ������� ����� ������ ���������
    printf("����� ������ ���������: %f ������\n", total_time);

    return 0;
}