#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double actual (double in, double t) {
   double real_in = in*M_PI/25.0;
   double out = 4.0*sin(real_in)*exp(-1.0*t) + 2.0*sin(3.0*real_in)*exp(-9.0*t)+sin(10*real_in)*exp(-100.0*t);
   return out;
}


int main () {
   #define DT    0.0025
   #define TARGET  3.0000
   #define ROUND TARGET/(2.0*DT)
   int i, j;
   double base[102];
   double output[102];
//   double exact[100];
   double dx = 4.0*M_PI/100.0;
   double dx_sq = dx*dx;
   double dt = DT;
   double a = (1-2*dt/dx_sq);
   double b = dt/dx_sq;
   FILE * fp0;
   FILE * fp1;
   fp0 = fopen("exact.txt", "w+");
   fp1 = fopen("FTCS.txt", "w+");
/*
   prepare initial at t = 0
 */
   for (i = 0; i < 100; i = i + 1) {
      base[i+1] = actual(i, 0);
//      exact[i] = actual(i, TARGET);
      fprintf (fp0, "%e \n", actual(i, TARGET));
   }
   base[0] = base[100];
   base[101] = base[1];
   
/*
   start processing
 */
   for (j = 0; j < ROUND; j = j + 1) {
      for (i = 0; i < 100; i = i + 1) {
         output[i+1] = b*base[i]+a*base[i+1]+b*base[i+2];
      }     
         output[0] = output[100];
         output[101] = output[1];
      for (i = 0; i < 100; i = i + 1) {
         base[i+1] = b*output[i]+a*output[i+1]+b*output[i+2];
      }     
         base[0] = base[100];
         base[101] = base[1];
   }
/*
   print
 */ 
   for (i = 0; i < 100; i = i + 1) {
      fprintf (fp1, "%e \n", base[i+1]);
//      printf ("%d, numeric = %1f, exact = %1f \n", i, base[i+1], exact[i]);
   }
   close (fp0); 
   close (fp1); 

   return 0;
}
