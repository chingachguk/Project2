#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
    double** matrix1 = (double**)malloc(n * sizeof(double*)); // выделение памяти под двумерный массив matrix1 размером n x n
    double** matrix2 = (double**)malloc(n * sizeof(double*)); // выделение памяти под двумерный массив matrix2 размером n x n
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double)); // выделение памяти для i-й строки матрицы matrix1
        matrix2[i] = (double*)malloc(n * sizeof(double)); // выделение памяти для i-й строки матрицы matrix2
    }
    printf("Enter the elements of matrix 1:\n");
    inputMatrix(matrix1, n); // вызов функции для ввода матрицы matrix1

    printf("Enter the elements of matrix 2:\n");
    inputMatrix(matrix2, n); // вызов функции для ввода матрицы matrix2

    char operation;
    printf("Enter the operation (+, -, or *): ");
    scanf(" %c", &operation); // ввод символа операции (+, -, или *)

    double** result = calculateMatrixOperation(matrix1, matrix2, n, operation); // вызов функции для вычисления результата операции над матрицами
    printf("Resulting matrix:\n");
    outputMatrix(result, n); // вызов функции для вывода результата операции на экран

    for (int i = 0; i < n; i++) { // цикл для освобождения памяти, выделенной под строки матриц
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1); // освобождение памяти, выделенной под массив matrix1
    free(matrix2); // освобождение памяти, выделенной под массив matrix2
    free(result); // освобождение памяти, выделенной под массив с результатом операции

    return 0; // возврат нуля - успешное завершение программы
}