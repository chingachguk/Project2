#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

// Структура для хранения информации о человеке
struct Person {
    char firstName[100];
    char lastName[100];
    int year;
};

// Функция для сравнения фамилий
int compareLastName(const void* a, const void* b) {
    struct Person* personA = (struct Person*)a;
    struct Person* personB = (struct Person*)b;
    return strcmp(personA->lastName, personB->lastName);
}

int main(int argc, wchar_t* argv[]) {
    setlocale(LC_ALL, "Rus");
    system("chcp 1251"); // настраиваем кодировку консоли
    wprintf(L"%s", L"Unicode -- English -- Русский -- Ελληνικά -- Español.\n");

    FILE* fp = fopen("input.txt", "r"); // открыть файл на чтение
    if (fp == NULL) { // обработка ошибок при открытии файла
        printf("Error: failed to open the file.\n");
        return 1;
    }
    char buffer[1000]; // буфер для чтения строки из файла
    int year; // переменная для хранения года рождения
    int numPeople = 0; // количество людей в файле
    struct Person people[100]; // массив для хранения информации о людях

    while (fgets(buffer, 1000, fp) != NULL) { // читать строки из файла, пока не достигнут конец файла
        sscanf(buffer, "%s %s %*s %d", people[numPeople].firstName, people[numPeople].lastName, &people[numPeople].year); // считать информацию о человеке из строки
        if (people[numPeople].year > 1980) { // проверить, родился ли человек после 1980 года
            numPeople++; // увеличить счетчик людей
        }
    }

    fclose(fp); // закрыть файл

    qsort(people, numPeople, sizeof(struct Person), compareLastName); // сортировка по фамилии

    for (int i = 0; i < numPeople; i++) {
        printf("%s %s %d\n", people[i].firstName, people[i].lastName, people[i].year); // вывести информацию о человеке в консоль
    }

    return 0;
}