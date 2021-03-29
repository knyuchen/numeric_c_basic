#include <stdio.h>
#include <math.h>
#include <stdlib.h>
   // input an entire array, but only operate on segment
void merge (int arr [], int start, int middle, int end) {
   int i; // dummy for loop index
   int length_sub1 = middle - start + 1; // first sub include middle
   int length_sub2 = end - middle;
/*
  Initialize sub array
 */
   int sub1[length_sub1], sub2[length_sub2];
   for (i = 0; i < length_sub1; i = i + 1) {
      sub1[i] = arr[start+i];
   }  
   for (i = 0; i < length_sub2; i = i + 1) {
      sub2[i] = arr[middle+1+i];
   }  
/*
   merging 
*/   
   int i0 = start; // original
   int i1 =   0;
   int i2 =   0;
   while (i1 < length_sub1 && i2 < length_sub2) {
      if (sub1[i1] > sub2[i2]) {
         arr[i0] = sub2[i2];
         i2 = i2 + 1;
      }
      else {
         arr[i0] = sub1[i1];
         i1 = i1 + 1;
      }
      i0 = i0 + 1;
   }
   // copy the rest
   while (i1 < length_sub1) {
      arr[i0] = sub1[i1];
      i0 = i0 + 1;
      i1 = i1 + 1;
   }
   while (i2 < length_sub2) {
      arr[i0] = sub2[i2];
      i0 = i0 + 1;
      i2 = i2 + 1;
   }
   
}
void merge_sort_help (int arr[], int start, int end) {
   if (start < end) {
   int middle = start + (end - start) / 2;
   merge_sort_help (arr, start, middle);
   merge_sort_help (arr, middle+1, end);
   merge (arr, start, middle, end);
   }
}

int* merge_sort (int a[], int n) {
   int* sorted;
   sorted = malloc(n*sizeof(int));
   int i;
   for (i = 0; i < n; i = i + 1) {
      sorted[i] = a[i];
   }
   merge_sort_help (sorted, 0, n-1);
   return sorted;
}

int main () {
/*
   Initialize an array 
 */
   #define ARRAY_SIZE 5
   int i;
   int size = ARRAY_SIZE;
//   int array[ARRAY_SIZE] = {7, 8, 2, 9, 4};
   int array[ARRAY_SIZE] = {7, 2, 2, 7, 2};
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
   int* sorted_array = merge_sort(array, size);

/*
  print sorted array
*/

   printf ("\nsorted array is: \n");
   for (i = 0; i < ARRAY_SIZE; i = i + 1){
      printf ("%d ", sorted_array[i]);
   }

   printf ("\n");
   printf ("\noriginal array is: \n");
   for (i = 0; i < ARRAY_SIZE; i = i + 1){
      printf ("%d ", array[i]);
   }
   printf ("\n");

   free (sorted_array);   

   return 0;
}
