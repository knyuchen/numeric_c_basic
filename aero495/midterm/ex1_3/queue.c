#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void swap2(int *pa, int*pb) {
   int t;
   t = *pa; *pa = *pb, *pb = t;
}

int main () {
   int x[5] = {0, 1, 2, 3, 4};
   swap2(x+1, x+4);
   printf("x = { %d, %d, %d, %d, %d }\n", x[0], x[1], x[2], x[3], x[4]);
   return 1;
}
