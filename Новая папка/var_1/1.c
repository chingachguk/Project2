#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ��������� ���� ��� ������
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("�� ������� ������� ����.\n");
        return 1;
    }

    // ��������� ���� �� �����
    int day, month, year;
    fscanf(file, "%d.%d.%d", &day, &month, &year);

    // ��������� ����
    fclose(file);

    // �������� ������� ����
    time_t now = time(NULL);
    struct tm* current = localtime(&now);
    int current_day = current->tm_mday;
    int current_month = current->tm_mon + 1; // ���� tm_mon ���������� � 0
    int current_year = current->tm_year + 1900; // ���� tm_year �������� ���������� ��� � 1900 ����

    // ������������ ������� � ����
    struct tm date = { 0 };
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t target = mktime(&date);

    double difference = difftime(target, now);
    int days_difference = (int)(difference / (60 * 60 * 24));

    // ������� ���������
    printf("���������� ���� �� ��������� ����: %d\n", days_difference);

    return 0;
}