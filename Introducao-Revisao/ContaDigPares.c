#include <stdio.h>
#include <string.h>
int main () {
    char n[10];
    int i = 0, k = 0;
    while (scanf("%s", n) != EOF) {
        while (i < strlen(n)) {
            if ((int)n[i] % 2 == 0) {
                k++;
            }
            i++;
        }
        printf("%d\n", k);
        k = i = 0;
    }
    return 0;
}