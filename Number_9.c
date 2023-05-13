#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для выполнения бинарной операции
float executeBinaryOperation(float leftOperand, float rightOperand, char operator) {
    switch (operator) {
    case '+':
        return leftOperand + rightOperand;
    case '-':
        return leftOperand - rightOperand;
    default:
        printf("Ошибка: Неизвестный оператор\n");
        exit(1);
    }
}

// Функция для выполнения унарной операции
float executeUnaryOperation(float operand, char operator) {
    switch (operator) {
    case '+':
        return operand;
    case '-':
        return -operand;
    default:
        printf("Ошибка: Неизвестный оператор\n");
        exit(1);
    }
}

int main() {
    system("chcp 1251");
    char expression[100];
    printf("Введите выражение: ");
    fgets(expression, sizeof(expression), stdin);

    // Удаление символа новой строки, если он присутствует
    if (expression[strlen(expression) - 1] == '\n')
        expression[strlen(expression) - 1] = '\0';

    // Получение первого операнда
    char* token = strtok(expression, " ");
    float result = atof(token);

    // Получение остальных операндов и операторов
    while ((token = strtok(NULL, " ")) != NULL) {
        char operator = token[0];
        token = strtok(NULL, " ");
        float operand = atof(token);

        // Выполнение операции
        if (operator == '+' || operator == '-')
            result = executeBinaryOperation(result, operand, operator);
        else
            result = executeUnaryOperation(operand, operator);
    }

    printf("Результат: %.2f\n", result);

    return 0;
}