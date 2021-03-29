#include <stdio.h>
#include <math.h>

double max2Array (double a[], int size) {
   double max1, max2;
   
   int i;

   for (i = 0; i < size; i = i + 1) {
      if (i == 0) {
         max1 = a[i];
      }
      else if (i == 1) {
         if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
         }
      }
      else {
         if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
         }
         else if (a[i] > max2) {
            max2 = a[i];
         }
      }
   }
   return max2;
}


int main () {


/*
  Initializing Array
*/
/*
   #define  array_size  6
   double array [array_size] = {5, 4, 2, 6, 8, 9};
*/

/*
   #define  array_size  4
   double array [array_size] = {7, 7, 7, 7};
*/


   #define  array_size  5
   double array [array_size] = {6, 10, 9, 9, 3};

/*
  Printing Array
*/
   int i;
 
   printf ("Printing Array \n");

   for (i = 0; i < array_size; i = i + 1) {
      printf ("%1f ", array[i]);
   }

/*
  Doing Computation and printing out result
*/
   double b = max2Array(array, 6);

   printf ("\nThe Second Largest number in the array is %1f \n", b);

   return 0;
}
