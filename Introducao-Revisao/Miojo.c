#include <stdio.h>
#include <stdlib.h>
int main () {
    long t, a, b, a2, b2;
    scanf("%ld %ld %ld", &t, &a, &b);
    a2 = a;
    b2 = b;
    while (abs(a - b) != t) {
        if (a < b) {
            a = a + a2;
        } else {
            b = b + b2;
        }
    }
    if (a < b) {
        printf("%ld\n", b);
    } else {
        printf("%ld\n", a);
    }
    return 0;
}