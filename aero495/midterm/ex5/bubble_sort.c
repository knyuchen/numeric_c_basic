#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void bubble_sort (int a[], int n) {
  int i, j; // for creating 2 for loops
  int tmp; // used for swapping
  int count = 0; // check if another round of sorting is needed
  do {  // loop over each starting point
     count = 0;
     for (j = 0; j < n-1; j = j + 1) { // loop number of "pairs"
        if (a[j] > a[j+1]){
           tmp = a[j];
           a[j] = a[j+1];  
           a[j+1] = tmp;  
           count = count + 1;      
        }
     } 
  } while (count != 0);
}


int main () {
/*
   Initialize an array 
 */
   #define ARRAY_SIZE 5
   int i;
   int size = ARRAY_SIZE;
   int array[ARRAY_SIZE] = {7, 8, 2, 9, 4};
//   int array[ARRAY_SIZE] = {7, 7, 2, 7, 2};
/*
  print original array
*/
   printf ("original array is: \n");
   for (i = 0; i < ARRAY_SIZE; i = i + 1){
      printf ("%d ", array[i]);
   }
   printf ("\n");

/*
   do sort
*/

   bubble_sort(array, size);


/*
  print sorted array
*/
   printf ("\nsorted array is: \n");
   for (i = 0; i < ARRAY_SIZE; i = i + 1){
      printf ("%d ", array[i]);
   }
   printf ("\n");


   return 0;
}
