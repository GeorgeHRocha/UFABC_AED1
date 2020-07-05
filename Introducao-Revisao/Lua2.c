#include <stdio.h>
int main() {
    int m1, m2, n, i = 0;
    scanf("%d", &n);
    while (i < n) {
        scanf("%d %d", &m1, &m2);
        if (m2 <= 2) {
            printf("Nova\n");
        } else if (m2 >= 97) {
            printf("Cheia\n");
        } else {
            if (m1 < m2) {
                printf("Crescente\n");
            } else if (m1 > m2) {
                printf("Minguante\n");
            }
        }
        i++;
    }
    return 0;
}