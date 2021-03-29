#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct complex_number {
   double real;
   double imag;
} complex_number;

complex_number cmult (complex_number opa, complex_number opb) {
   complex_number out;
   double RR = opa.real * opb.real;
   double IR = opa.imag * opb.real;
   double RI = opa.real * opb.imag;
   double II = opa.imag * opb.imag;

   out.real = RR - II;
   out.imag = RI + IR;
   return out;
}

complex_number cadd (complex_number opa, complex_number opb) {
   complex_number out;
   out.real = opa.real + opb.real;
   out.imag = opa.imag + opb.imag;
   return out;
}

// input how many PI
complex_number euler(double x) {
   complex_number out;
   out.real = cos(x*M_PI);
   out.imag = sin(x*M_PI);
   return out;
}
// input index really input x*2pi/N
double func (double x, double N) {
   double out = sin(2.0*x*2.0*M_PI/N) + exp(-1.0*pow(x*2.0*M_PI/N - M_PI, 4));
   return out;
}

int main () {
   #define N  8
   double seed [N];  //a seed to do -4 ~ 3
   int i, j; // for looping
   for (i = 0; i < N; i = i + 1) {
      seed[i] = i - 4;
   }
  
   complex_number F [N][N]; 

   for (i = 0; i < N; i = i + 1) {
      for (j = 0; j < N; j = j + 1) {
 //        printf("%1f \n", -1.0*seed[i]*j*(2.0/8.0));
         F[i][j] = euler(-1.0*seed[i]*j*(2.0/N));
      }
   }
 
   for (i = 0; i < N; i = i + 1) {
      printf("start of %d row \n", i);
      for (j = 0; j < N; j = j + 1) {
         printf("%1f %1fi \n", F[i][j].real, F[i][j].imag);
//         printf(",");
      }
      printf("\n");
   }

   double f[N];
   double size = N;    

   printf("start of data point \n", i);
   for (i = 0; i < N; i = i + 1) {
         f[i] = func(seed[i], size);
         printf("%1f \n", f[i]);
   }
/*
   complex_number test = euler(0.75);
   printf("%1f %1fi \n", test.real, test.imag);
*/
   return 0;
}
