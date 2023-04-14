#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "matrix_operations.h"

int main() {
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
    double** matrix1 = (double**)malloc(n * sizeof(double*));
    double** matrix2 = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        matrix2[i] = (double*)malloc(n * sizeof(double));
    }

    
    return 0;
}