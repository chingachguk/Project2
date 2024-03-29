#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
    double** matrix1 = (double**)malloc(n * sizeof(double*)); // ��������� ������ ��� ��������� ������ matrix1 �������� n x n
    double** matrix2 = (double**)malloc(n * sizeof(double*)); // ��������� ������ ��� ��������� ������ matrix2 �������� n x n
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double)); // ��������� ������ ��� i-� ������ ������� matrix1
        matrix2[i] = (double*)malloc(n * sizeof(double)); // ��������� ������ ��� i-� ������ ������� matrix2
    }
    printf("Enter the elements of matrix 1:\n");
    inputMatrix(matrix1, n); // ����� ������� ��� ����� ������� matrix1

    printf("Enter the elements of matrix 2:\n");
    inputMatrix(matrix2, n); // ����� ������� ��� ����� ������� matrix2

    char operation;
    printf("Enter the operation (+, -, or *): ");
    scanf(" %c", &operation); // ���� ������� �������� (+, -, ��� *)

    double** result = calculateMatrixOperation(matrix1, matrix2, n, operation); // ����� ������� ��� ���������� ���������� �������� ��� ���������
    printf("Resulting matrix:\n");
    outputMatrix(result, n); // ����� ������� ��� ������ ���������� �������� �� �����

    for (int i = 0; i < n; i++) { // ���� ��� ������������ ������, ���������� ��� ������ ������
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1); // ������������ ������, ���������� ��� ������ matrix1
    free(matrix2); // ������������ ������, ���������� ��� ������ matrix2
    free(result); // ������������ ������, ���������� ��� ������ � ����������� ��������

    return 0; // ������� ���� - �������� ���������� ���������
}