#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int ** copy_array2d(int** arr, int r, int c) {
  
   int i, j;
   int ** array;   
 
   array =  malloc (r*sizeof(int*));
   for (i = 0; i < r; i = i + 1) {
      array[i] = malloc (c*sizeof(int));
   }
  
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
         array[i][j] = arr[i][j];
      }
   }
   return array;
}


int main () {
   int r = 4;
   int c = 4;

/*
  allocate memory space for original array
*/

   int i, j;
   int ** original_array =  malloc (r*sizeof(int*));
   for (i = 0; i < r; i = i + 1) {
      original_array[i] = malloc (c*sizeof(int));
   }
/*
  Initialize original array
*/
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       original_array[i][j] = i*10+j; 
      }
   }
   

   int ** copy_array = copy_array2d(original_array, r, c);

/*
  print array
*/
   printf ("this is the original array \n");

   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       printf ("%d ", original_array[i][j]);
      }
      printf ("\n");
   }

   printf ("\nthis is the copied array \n");
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       printf ("%d ", copy_array[i][j]);
      }
      printf ("\n");
   }
/*
  change copy array
*/
   printf ("\nadding 3 to each element in the copied array \n");
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       copy_array[i][j] = copy_array[i][j] + 3;
      }
   }
   
/*
  print array
*/
   printf ("\nthis is the original array which shouldn't change \n");

   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       printf ("%d ", original_array[i][j]);
      }
      printf ("\n");
   }

   printf ("\nthis is the copied array after modification \n");
   for (i = 0; i < r; i = i + 1) {
      for (j = 0; j < c; j = j + 1) {
       printf ("%d ", copy_array[i][j]);
      }
      printf ("\n");
   }
/*
  free up array
*/ 
   for (i = 0; i < r; i = i + 1) {
      free(original_array[i]);
      free(copy_array[i]);
   }

   free(original_array); 
   free(copy_array); 

   return 0;
}
