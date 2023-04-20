#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp = fopen("input.txt", "r"); // открыть файл на чтение
    if (fp == NULL) { // обработка ошибок при открытии файла
        printf("Error: failed to open the file.\n");
        return 1;
    } 
    char buffer[100]; // буфер для чтения строки из файла
    int year; // переменная для хранения года рождения

    while (fgets(buffer, 100, fp) != NULL) { // читать строки из файла, пока не достигнут конец файла
        sscanf(buffer, "%*s %*s %*s %d", &year); // считать год рождения из строки
        if (year > 1980) { // проверить, родился ли человек после 1980 года
            printf("%s", buffer); // вывести строку в консоль
        }
    }

    fclose(fp); // закрыть файл
    return 0;
}