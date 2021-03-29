#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ** array2d(int r, int c) {
  
   int i, j;
   int ** array;   
 
   array =  malloc (r*sizeof(int*));
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
      &array[i][j] = malloc (sizeof(int));
   }
   }
  
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
         array[i][j] = 42;
  //     printf ("%d \n", array[i][j][k]);
      }
   }
   return array;
}


int main () {
   int r = 4;
   int c = 4;

   int ** array = array2d(r, c);

   int i, j;
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
  //       array[i][j] = 42;
  //     printf ("%d \n", array[i][j]);
       printf ("%p \n", &array[i][j]);
      }
   }


   return 0;
}
