#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    FILE* fp = fopen("input.txt", "r"); // ������� ���� �� ������
    if (fp == NULL) { // ��������� ������ ��� �������� �����
        printf("Error: failed to open the file.\n");
        return 1;
    }