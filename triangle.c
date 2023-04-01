#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include "triangle.h"

void inputSides(double* a, double* b, double* c) {
    do {
        printf("Enter the lengths of the sides of the triangle: ");
        scanf("%lf %lf %lf", a, b, c);
        if (*a <= 0 || *b <= 0 || *c <= 0) {
            printf("Error: side lengths must be positive.\n");
        }
        else if (*a + *b <= *c || *a + *c <= *b || *b + *c <= *a) {
            printf("Error: sides do not satisfy the triangle inequality.\n");
        }
        else {
            break;
        }
    } while (1);

}

double calculatePerimeter(double a, double b, double c) {
    return a + b + c;
}

double calculateArea(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}