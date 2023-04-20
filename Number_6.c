#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp = fopen("input.txt", "r"); // открыть файл на чтение
    if (fp == NULL) { // обработка ошибок при открытии файла
        printf("Error: failed to open the file.\n");
        return 1;
    }