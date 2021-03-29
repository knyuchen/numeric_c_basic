#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ** array2d(int r, int c) {
  
   int i, j;
   int ** array;   
 
   array =  malloc (r*sizeof(int*));
   for (i = 0; i < r; i = i + 1) {
      array[i] = malloc (c*sizeof(int));
   }
  
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
         array[i][j] = 42;
      }
   }
   return array;
}


int main () {
   int r = 4;
   int c = 4;

   int ** array = array2d(r, c);

   int i, j;
   printf ("printing address \n");
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       printf ("%p \n", &array[i][j]);
      }
   }

   #define access_row    2 // must < 4
   #define access_column 3 // must < 4

   printf ("printing some content \n");
   printf ("%d \n", array[access_row][access_column]);

/*
  Free up memory
*/
   for (i = 0; i < r; i = i + 1) {
      free(array[i]);
   }
   free (array);


   return 0;
}
