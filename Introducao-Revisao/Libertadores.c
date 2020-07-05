#include <stdio.h>
int main () {
    int n, i = 0, time1, time2, pontos1 = 0, pontos2 = 0, saldoTime1, saldoTime2, golsTime1, golsTime2;
    char x;
    scanf("%d", &n);
    while (i < n) {
        scanf("%d %c %d", &time1, &x, &time2);
        saldoTime1 = time1 - time2;
        saldoTime2 = time2 - time1;
        golsTime2 = time2;
        if (time1 > time2) {
            pontos1 = 3;
        } else if (time2 > time1) {
            pontos2 = 3;
        } else {
            pontos1 = pontos2 = 1;
        }
        scanf("%d %c %d", &time2, &x, &time1);
        saldoTime1 = saldoTime1 + (time1 - time2);
        saldoTime2 = saldoTime2 + (time2 - time1);
        golsTime1 = time1;
        if (time1 > time2) {
            pontos1 = pontos1 + 3;
        } else if (time2 > time1) {
            pontos2 = pontos2 + 3;
        } else {
            pontos1++;
            pontos2++;
        }
        if (pontos1 > pontos2) {
            printf("Time 1\n");
        } else if (pontos2 > pontos1) {
            printf("Time 2\n");
        } else {
            if(saldoTime1 > saldoTime2) {
                printf("Time 1\n");
            } else if (saldoTime2 > saldoTime1) {
                printf("Time 2\n");
            } else {
                if (golsTime1 > golsTime2) {
                    printf("Time 1\n");
                } else if (golsTime2 > golsTime1) {
                    printf("Time 2\n");
                } else {
                    printf("Penaltis\n");
                }
            }
        }
        pontos1 = pontos2 = saldoTime1 = saldoTime2 = golsTime1 = golsTime2 = 0;
        i++;
    }
    return 0;
}