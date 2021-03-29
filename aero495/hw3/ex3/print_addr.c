#include <stdio.h>
#include <math.h>

int main () {
   int arr [7] = {3, 5, 4, -2, 3, 1, 0};

   int *ptr = arr;
   
   printf("%p \n", ptr);
   printf("%p \n", arr + 7);
   int i;
//   while (ptr < arr + 7) {
   for (i = 0; i < 5; i = i + 1) {
      printf("%p : %d \n", ptr, *ptr);
      ptr = ptr + *ptr;
   }

   return 0;
}
