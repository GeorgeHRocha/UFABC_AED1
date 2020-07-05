#include <stdio.h>
#include <math.h>
int main () {
    double a, b, c, delta;
    double x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = (b * b) - (4 * a * c);
    if (delta < 0) {
        printf("nao ha raiz real\n");
    } else {
        x1 = (- b + sqrt(delta)) / (2 * a);
        if (delta == 0) {
            printf("%.4lf\n", x1);
        } else {
            x2 = (- b - sqrt(delta)) / (2 * a);
            printf("%.4lf %.4lf\n", x1, x2);
        }
    }
    return 0;
}