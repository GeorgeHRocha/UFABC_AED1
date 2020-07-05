#include <stdio.h>
int main () {
    int n, v, i = 0, metros = 0, v2;
    scanf("%d %d", &n, &v);
    while (n != 0 && v != 0) {
        v2 = v;
        while (metros < n && v > 0) {
            while (metros < n && i < v) {
                metros = metros + v;
                //printf("%d\n", metros);
                i++;
            }
            i = 0;
            v--;
            if (metros > n) {
                v2--;
                v = v2;
                metros = 0;
            }
        }
        if (metros == n) {
            printf("possivel\n");
        } else {
            printf("impossivel\n");
        }
        metros = 0;
        i = 0;
        scanf("%d %d", &n, &v);
    }
    return 0;
}

/*while (v > 0) {
            while (i < v && metros < n) {
                metros = metros + v;
                //printf("%d\n", metros);
                i++;
            }
            if (i < v) {
                break;
            }
            i = 0;
            v--;
        }
        if (metros == n) {
            printf("possivel\n");
        } else {
            printf("impossivel\n");
        }
        metros = 0;
        i = 0;
        scanf("%d %d", &n, &v);*/