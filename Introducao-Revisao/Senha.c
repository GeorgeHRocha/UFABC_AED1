#include <stdio.h>
int main () {
    char senha[5];
    int i = 0;
    scanf ("%s", senha);
    while (i < 4 && senha[i] != '0') {
        i++;
    }
    if (i < 4) {
        printf("NAO\n");
    } else {
        printf("SIM\n");
    }
    return 0;
}