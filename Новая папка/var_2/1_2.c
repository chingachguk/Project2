#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������� ��� �������� ������� ������� n x m
// � ���������� �� ���������� ������� �� 0 �� 9
int** createMatrix(int n, int m) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
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

// ������� ��� ������������ ���� ������
int** multiplyMatrices(int** matrix1, int n1, int m1, int** matrix2, int n2, int m2) {
    if (m1 != n2) {
        printf("���������� �������� �������. ����������� �� ���������.\n");
        return NULL;
    }

    int** result = (int**)malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        result[i] = (int*)malloc(m2 * sizeof(int));
        for (int j = 0; j < m2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// ������� ��� �������� ���� ������
int** addMatrices(int** matrix1, int n1, int m1, int** matrix2, int n2, int m2) {
    if (n1 != n2 || m1 != m2) {
        printf("���������� ������� �������. ����������� �� ���������.\n");
        return NULL;
    }

    int** result = (int**)malloc(n1 * sizeof(int*));
    for (int i = 0; i < n1; i++) {
        result[i] = (int*)malloc(m1 * sizeof(int));
        for (int j = 0; j < m1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// ������� ��� ������ ���� ��������� � �������
void swapElements(int** matrix, int row, int col1, int col2) {
    int temp = matrix[row][col1];
    matrix[row][col1] = matrix[row][col2];
    matrix[row][col2] = temp;
}

// ������� ��� ������ ������������ �������� � ������� � ��� �������
void findMinElement(int** matrix, int n, int m, int* minElement, int* minRow, int* minCol) {
    *minElement = matrix[0][0];
    *minRow = 0;
    *minCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < *minElement) {
                *minElement = matrix[i][j];
                *minRow = i;
                *minCol = j;
            }
        }
    }
}

// ������� ��� �������� ���������� �������� ����� � �������
int countOddNumbers(int** matrix, int n, int m) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] % 2 != 0) {
                count++;
            }
        }
    }

    return count;
}

// ������� ��� ������ ������� � ����������� ������� � ������ ��� �������
int** findMatrixWithSameNumbers(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum == matrix[i][0] * m) {
            return matrix;
        }
    }

    for (int j = 0; j < m; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum == matrix[0][j] * n) {
            return matrix;
        }
    }

    return NULL;
}

int main() {
    system("chcp 1251");
    // ������ ��������� �������� ��� ���������� ��������� �����
    srand(time(NULL));

    // ��������� ���� ��� ������
    FILE* file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return 1;
    }

    int n, m; // ����������� ������
    printf("������� ����������� ������� (n x m): ");
    scanf("%d %d", &n, &m);

    // ������� � ��������� �������
    int** matrix1 = createMatrix(n, m);
    int** matrix2 = createMatrix(n, m);

    // ���������� ������� � ����
    fprintf(file, "������� 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix1[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n������� 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix2[i][j]);
        }
        fprintf(file, "\n");
    }

    // ��������� ����
    fclose(file);

    // ��������� ���� ��� ������
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return 1;
    }

    // ������ ������� �� �����
    int** readMatrix1 = (int**)malloc(n * sizeof(int*));
    int** readMatrix2 = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        readMatrix1[i] = (int*)malloc(m * sizeof(int));
        readMatrix2[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &readMatrix1[i][j]);
        }
    }
    fseek(file, 1, SEEK_CUR); // ���������� ������ ����� ������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &readMatrix2[i][j]);
        }
    }

    // ��������� ����
    fclose(file);

    // ��������� ������������ � �������� ������
    int** productMatrix = multiplyMatrices(readMatrix1, n, m, readMatrix2, n, m);
    int** sumMatrix = addMatrices(readMatrix1, n, m, readMatrix2, n, m);

    // ��������� ���� ��� ������
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return 1;
    }

    // ���������� ���������� � ����
    fprintf(file, "��������� ��������� ������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", productMatrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n��������� �������� ������:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", sumMatrix[i][j]);
        }
        fprintf(file, "\n");
    }

    // ��������� ����
    fclose(file);

    // �������� ������� ���� ��������� � ������� 1
    swapElements(readMatrix1, 0, 1, 2);

    // ����� ����������� ������� � ���������� �������� ����� � ������� 1
    int minElement, minRow, minCol;
    findMinElement(readMatrix1, n, m, &minElement, &minRow, &minCol);
    int oddCount = countOddNumbers(readMatrix1, n, m);

    // ����� ������� � ����������� ������� � ������ ��� �������
    int** sameNumbersMatrix = findMatrixWithSameNumbers(readMatrix1, n, m);

    // �������� ����� ������ ���������
    clock_t start_time = clock();

    // ������� ���������� �� �����
    printf("����������� ������� � ������� 1: %d\n", minElement);
    printf("������ ������������ ��������: (%d, %d)\n", minRow, minCol);
    printf("���������� �������� ����� � ������� 1: %d\n", oddCount);
    if (sameNumbersMatrix != NULL) {
        printf("������� ������� � ����������� ������� � ������ ��� �������.\n");
    }
    else {
        printf("������� � ����������� ������� � ������ ��� ������� �� �������.\n");
    }

    // ������� ����� ������ ���������
    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("����� ������ ���������: %f ������\n", total_time);

    // ����������� ������, ������� ���������
    freeMatrix(matrix1, n);
    freeMatrix(matrix2, n);
    freeMatrix(readMatrix1, n);
    freeMatrix(readMatrix2, n);
    freeMatrix(productMatrix, n);
    freeMatrix(sumMatrix, n);

    return 0;
}