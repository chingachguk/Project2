#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp = fopen("input.txt", "r"); // ������� ���� �� ������
    if (fp == NULL) { // ��������� ������ ��� �������� �����
        printf("Error: failed to open the file.\n");
        return 1;
    } 
    char buffer[100]; // ����� ��� ������ ������ �� �����
    int year; // ���������� ��� �������� ���� ��������

    while (fgets(buffer, 100, fp) != NULL) { // ������ ������ �� �����, ���� �� ��������� ����� �����
        sscanf(buffer, "%*s %*s %*s %d", &year); // ������� ��� �������� �� ������
        if (year > 1980) { // ���������, ������� �� ������� ����� 1980 ����
            printf("%s", buffer); // ������� ������ � �������
        }
    }

    fclose(fp); // ������� ����
    return 0;
}