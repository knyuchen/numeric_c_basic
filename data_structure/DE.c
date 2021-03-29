#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

double funcx (double x) {
   double out = cos(2.0*x)*exp(-0.1*x);
//   double out = sin(x*2.0*M_PI);
   return out;
}
double funcy (double x) {
   double out = sin(2.0*x)*exp(-0.1*x);
//   double out = sin(x*2.0*M_PI);
   return out;
}

int main () {
   #define INTERVAL 0.04 
   #define POINT    251 
   int i;
   double j; // for looping
   FILE * fp0;
   FILE * fp1;
   fp0 = fopen("data0.txt", "w+");
   fp1 = fopen("data1.txt", "w+");
   for (i = 0; i < POINT; i = i + 1) {
      j = INTERVAL*i;
      fprintf(fp0, "%e \n", funcx(j));
      fprintf(fp1, "%e \n", funcy(j));
   }
   close (fp0); 
   close (fp1); 
   return 0;
}
