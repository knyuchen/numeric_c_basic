#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main () {
/*
  Define Parameter 
*/
   #define dimen1 3
   #define dimen2 4
   #define dimen3 3
   int i, j, k;

/*
  Allocate Memory 
*/
   int *** array = NULL;
   array =  malloc (dimen1*sizeof(int**));
   for (i = 0; i < dimen1; i = i + 1){
      array[i] =  malloc (dimen2*sizeof(int*));
   }  
   for (i = 0; i < dimen1; i = i + 1){
      for (j = 0; j < dimen2; j = j + 1){
         array[i][j] =  malloc (dimen3*sizeof(int));
      }  
   }  

/*
  Initialize Array
*/
   for (i = 0; i < dimen1; i = i + 1) {
      for (j = 0; j < dimen2; j = j + 1) {
         for (k = 0; k < dimen3; k = k + 1) {
            array[i][j][k] = k + j*10 + i*100;
       //     printf ("%d \n", array[i][j][k]);
         }
      }
   }
/*
  Access Memory
*/
   #define access1 2  // must < 3
   #define access2 0  // must < 4
   #define access3 1  // must < 3

   int access = *(*(*(array + access1)+access2)+access3);
   printf ("%d \n", access);

/*
  Free up Memory
*/
   for (i = 0; i < dimen1; i = i + 1){
      for (j = 0; j < dimen2; j = j + 1){
         free(array[i][j]); 
      }  
   }  

   for (i = 0; i < dimen1; i = i + 1){
      free(array[i]);
   }  

   free(array);
   return 0;
}
