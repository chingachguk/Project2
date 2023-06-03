#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Открываем файл для чтения
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    // Считываем дату из файла
    int day, month, year;
    fscanf(file, "%d.%d.%d", &day, &month, &year);

    // Закрываем файл
    fclose(file);

    // Получаем текущую дату
    time_t now = time(NULL);
    struct tm* current = localtime(&now);
    int current_day = current->tm_mday;
    int current_month = current->tm_mon + 1; // Поля tm_mon начинаются с 0
    int current_year = current->tm_year + 1900; // Поля tm_year содержат количество лет с 1900 года

    // Рассчитываем разницу в днях
    struct tm date = { 0 };
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    time_t target = mktime(&date);

    double difference = difftime(target, now);
    int days_difference = (int)(difference / (60 * 60 * 24));

    // Выводим результат
    printf("Количество дней до указанной даты: %d\n", days_difference);

    return 0;
}