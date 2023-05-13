#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������� ��� ���������� �������� ��������
float executeBinaryOperation(float leftOperand, float rightOperand, char operator) {
    switch (operator) {
    case '+':
        return leftOperand + rightOperand;
    case '-':
        return leftOperand - rightOperand;
    default:
        printf("������: ����������� ��������\n");
        exit(1);
    }
}

// ������� ��� ���������� ������� ��������
float executeUnaryOperation(float operand, char operator) {
    switch (operator) {
    case '+':
        return operand;
    case '-':
        return -operand;
    default:
        printf("������: ����������� ��������\n");
        exit(1);
    }
}

int main() {
    system("chcp 1251");
    char expression[100];
    printf("������� ���������: ");
    fgets(expression, sizeof(expression), stdin);

    // �������� ������� ����� ������, ���� �� ������������
    if (expression[strlen(expression) - 1] == '\n')
        expression[strlen(expression) - 1] = '\0';

    // ��������� ������� ��������
    char* token = strtok(expression, " ");
    float result = atof(token);

    // ��������� ��������� ��������� � ����������
    while ((token = strtok(NULL, " ")) != NULL) {
        char operator = token[0];
        token = strtok(NULL, " ");
        float operand = atof(token);

        // ���������� ��������
        if (operator == '+' || operator == '-')
            result = executeBinaryOperation(result, operand, operator);
        else
            result = executeUnaryOperation(operand, operator);
    }

    printf("���������: %.2f\n", result);

    return 0;
}