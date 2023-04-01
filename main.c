#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;
    inputSides(&a, &b, &c);
    double perimeter = calculatePerimeter(a, b, c);
    double area = calculateArea(a, b, c);
    printf("Perimeter: %lf\n", perimeter);
    printf("Area: %lf\n", area);
    return 0;
}