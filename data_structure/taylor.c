#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double cal_one_term (double in, double ref, double zero_term, double one_term) {
   
   double out = zero_term + (in-ref) * one_term;
   return out;
}

double cal_two_term (double in, double ref, double zero_term, double one_term, double two_term) {
   
   double out =  zero_term + (in-ref) * one_term + pow((in-ref), 2) * two_term ;
   return out;
}

double cal_three_term (double in, double ref, double zero_term, double one_term, double two_term, double three_term) {
   
   double out = zero_term + (in-ref) * one_term + pow((in-ref), 2) * two_term  + pow((in-ref), 3) * three_term ;
   return out;
}

double actual (double in) {
   double out = exp(-1.0*pow((in-M_PI), 4));
   return out;
}


int main () {
   #define REF 3.5
   #define INTERVAL  0.01
   // POINT = (5.0-2.0)/INTERVAL + 1
   #define POINT     301
   double ref = REF;
   double zero_term = actual(ref);
   printf ("%1f \n", zero_term);
   double one_term = -4.0*actual(ref)*pow((ref-M_PI),3);
   printf ("%1f \n", one_term);
   double two_term = (16.0*pow((ref-M_PI), 6) - 12.0*pow((ref-M_PI), 2))*actual(ref)/2.0;
   printf ("%1f \n", two_term);
   double three_term = (-1.0*64.0*pow((ref-M_PI),9) + 144.0*pow((ref-M_PI), 5) - 24.0*(ref-M_PI))*actual(ref)/6.0;
   printf ("%1f \n", three_term);
   double array [4][POINT];
   int i;
   double j;
   FILE * fp0;
   FILE * fp1;
   FILE * fp2;
   FILE * fp3;
   fp0 = fopen("data0.txt", "w+");
   fp1 = fopen("data1.txt", "w+");
   fp2 = fopen("data2.txt", "w+");
   fp3 = fopen("data3.txt", "w+");
   for (i = 0; i < POINT; i = i + 1) {
      j = 2.0 + INTERVAL*i;
      array[0][i] = actual(j);
      printf ("%1f ", array[0][i]);
      fprintf (fp0, "%e \n", array[0][i]);
      array[1][i] = cal_one_term(j, ref, zero_term, one_term);
      printf ("%1f ", array[1][i]);
      fprintf (fp1, "%e \n", array[1][i]);
      array[2][i] = cal_two_term(j, ref, zero_term, one_term, two_term);
      printf ("%1f ", array[2][i]);
      fprintf (fp2, "%e \n", array[2][i]);
      array[3][i] = cal_three_term(j, ref, zero_term, one_term, two_term, three_term);
      printf ("%1f ", array[3][i]);
      fprintf (fp3, "%e \n", array[3][i]);
      printf ("\n");
   }
   close (fp0); 
   close (fp1); 
   close (fp2); 
   close (fp3); 
   return 0;
}
