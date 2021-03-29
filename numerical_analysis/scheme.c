#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double actual (double in) {
   double out = exp(-1.0*pow((in-M_PI), 4));
   return out;
}
double actual_one (double in) {
   double out = -4.0*actual(in)*pow((in-M_PI),3);
   return out;
}


int main () {
   # define N_def 16
   # define MUL   2
   # define ROUND 11
   int N = N_def;
   int kk;
   FILE * fp0;
   FILE * fp1;
   FILE * fp2;
   fp0 = fopen("dr.txt", "w+");
   fp1 = fopen("l2_norm1.txt", "w+");
   fp2 = fopen("l2_norm2.txt", "w+");
   for (kk = 0; kk < ROUND; kk = kk + 1) {  
   double N_comp = N*1.0;
  
   double scheme1_original[N+3];
   double scheme2_original[N+5];
   double scheme1_out     [N+1];
   double scheme2_out     [N+1];
   double actual_out      [N+1];
   int i;
   double j, r;
   for (i = 0; i < N+1; i = i + 1) {
      j = i*1.0;
      r = j*(2.0*M_PI/N_comp);
      scheme1_original[i+1] = actual(r);
      scheme2_original[i+2] = actual(r); 
   }
   scheme1_original[0] = scheme1_original[N+1];
   scheme1_original[N+2] = scheme1_original[1];
   scheme2_original[0] = scheme2_original[N+1];
   scheme2_original[N+3] = scheme2_original[2];
   scheme2_original[1] = scheme2_original[N+2];
   scheme2_original[N+4] = scheme2_original[3];
 
   for (i = 0; i < N+1; i = i + 1) {
      scheme1_out[i] = (-1.0*scheme1_original[i] + scheme1_original[i+2])/(2.0*2.0*M_PI/N_comp); 
      scheme2_out[i] = (scheme2_original[i] - 8.0*scheme2_original[i+1] + 8.0*scheme2_original[i+3]-scheme2_original[i+4])/(12.0*2.0*M_PI/N_comp); 
      j = i*1.0;
      r = j*(2.0*M_PI/N_comp);
      actual_out[i] = actual_one(r);
   }
   for (i = 0; i < N+1; i = i + 1) {
  //    printf("%d, %1f, %1f, %1f \n", actual_out[i], scheme1_out[i], scheme2_out[i]);
   }
/*
   calculate L2 norm
 */
   double l2_norm1 = 0;
   double l2_norm2 = 0;
   double tmp1, tmp2;
   for (i = 0; i < N-1; i = i + 1) {
      tmp1 = (actual_out[i]-scheme1_out[i])*(actual_out[i]-scheme1_out[i]);
      tmp2 = (actual_out[i]-scheme2_out[i])*(actual_out[i]-scheme2_out[i]);
      l2_norm1 = l2_norm1 + tmp1;
      l2_norm2 = l2_norm2 + tmp2;
   }
   l2_norm1 = l2_norm1/N_comp;
   l2_norm2 = l2_norm2/N_comp;
   l2_norm1 = sqrt(l2_norm1);
   l2_norm2 = sqrt(l2_norm2);
   fprintf (fp0, "%e \n", 2.0*M_PI/N_comp);
   fprintf (fp1, "%e \n", l2_norm1);
   fprintf (fp2, "%e \n", l2_norm2);
   N = N*MUL; 
   }
   close (fp0); 
   close (fp1); 
   close (fp2); 

   return 0;
}
