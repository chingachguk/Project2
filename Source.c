#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, x1, x2;

    printf("Enter the values of a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = pow(b, 2) - 4 * a * c; // вычисляем дискриминант

    if (discriminant < 0) {
        printf("The roots are complex.\n");
    }
    else {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("x1 = %lf, x2 = %lf\n", x1, x2);
    }

    return 0;
}
