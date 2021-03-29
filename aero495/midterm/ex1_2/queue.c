#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main () {
   int a[9] = {4, 5, 6, 1, 2, 3, 7, 8, 9};
   int* b = a+4;
   printf("%d\n", a[*b]);
   printf("%d\n", *(a+*b+1));
   int c = a[*b];
   printf("%d\n", a[c]);
   printf("%d\n", *(a+c+1));
   return 1;
}
