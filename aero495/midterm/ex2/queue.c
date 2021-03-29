#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void print_array (int a[], int n) {
   int i;
   printf("[");
   for (i = 0; i < n; i = i + 1) {
      printf("%d ", a[i]);
   }
   printf("]\n");
}

void gnome_sort(int a[], int n) {
   int p = 1;
   while (p<n) {
      print_array(a, n);
      if (a[p-1] <= a[p]) {
         p++;
      }
      else {
         int tmp = a[p-1];
         a[p-1] = a[p];
         a[p] = tmp;
         p--;
         if(p == 0) {
           p = 1;
         }
      }
   }
}


int main () {
   int x[4] = {4, 3, 1, 2};
   gnome_sort(x, 4);
   return 0;
}
