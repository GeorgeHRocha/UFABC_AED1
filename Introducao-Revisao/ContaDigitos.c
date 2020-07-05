#include <stdio.h>
#include <string.h>
int main () {
    char n[10];
    while (scanf("%s", n) != EOF) {
        printf("%ld\n", strlen(n));
    }
    return 0;
}