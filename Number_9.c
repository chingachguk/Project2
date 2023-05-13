#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double calculate(double left, double right, char operator) {
    switch (operator) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    default:
        printf("Неподдерживаемый оператор: %c\n", operator);
        exit(1);
    }
}

int main() {
    system("chcp 1251");
    char input[100];
    printf("Введите выражение: ");
    fgets(input, sizeof(input), stdin);

    // Заменяем запятые на точки для корректного преобразования в число
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ',') {
            input[i] = '.';
        }
    }

    double result = 0.0;
    char* token = strtok(input, " ");
    double number = atof(token); // Преобразуем строку в число
    result = number;

    while (token != NULL) {
        token = strtok(NULL, " ");
        if (token != NULL) {
            char operator = token[0]; // Получаем оператор из токена
            token = strtok(NULL, " ");
            if (token != NULL) {
                // Заменяем запятые на точки для корректного преобразования в число
                for (int i = 0; i < strlen(token); i++) {
                    if (token[i] == ',') {
                        token[i] = '.';
                    }
                }
                number = atof(token);
                result = calculate(result, number, operator);
            }
        }
    }

    printf("Результат: %.2lf\n", result);

    return 0;
}
