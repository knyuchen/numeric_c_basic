#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// put pivot in the right place of a range
int partitioning (int a[], int start, int end) {
   int pivot = a[end];
   int i = start; // to be swap
   int j = start; // to be compared
   int tmp = 0; // help swapping
   for (j = start; j < end; j = j + 1) {
      if (a[j] < pivot) {
        // swapping
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
        // increment to be swapped
        i = i + 1;
      }
   } 
   a[end] = a[i];
   a[i] = pivot;
   return i;
}

void quicksort_helper (int a[], int start, int end){
   int new_pivot;
   if (start < end) { // if start == end, then we're done (1 element sub array)
      new_pivot = partitioning (a, start, end);
      quicksort_helper(a, start, new_pivot - 1); // previous pivot is in place
      quicksort_helper(a, new_pivot + 1, end);
   }
}

void quick_sort (int a[], int n) {
  quicksort_helper(a, 0, n-1); 
}


int main () {
/*
   Initialize an array 
 */
   #define ARRAY_SIZE 5
   int i;
   int size = ARRAY_SIZE;
//   int array[ARRAY_SIZE] = {7, 8, 2, 9, 4};
   int array[ARRAY_SIZE] = {7, 7, 2, 7, 2};
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

   quick_sort(array, size);


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
