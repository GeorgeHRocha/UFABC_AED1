#include <stdio.h>
int main () {
   char a[5], b[5];
   int i = 0;
   scanf("%s %s", a, b);
   while (i < 4 && a[i] == b[3 - i]) {
       i++;
   }
   if (i == 4) {
       printf("espelho\n");
   } else {
       printf("nao espelho\n");
   }
   return 0;
}