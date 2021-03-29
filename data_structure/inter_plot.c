#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

// input index really input x*2pi
double func (double x) {
   double out = sin(2.0*x*2.0*M_PI) + exp(-1.0*pow(x*2.0*M_PI - M_PI, 4));
//   double out = sin(x*2.0*M_PI);
   return out;
}

// input x*2pi
long double complex euler(double x) {
   long double complex out;
   out = cos(x*2.0*M_PI) + sin(x*2.0*M_PI)*I;
   return out;
}

void DMV (long double complex* M, long double complex * A, double* V, int R, int C) {
   long double complex out [R];
   int k, j;
   double comp = R*1.0;
   for (k = 0; k < R; k = k + 1) {
         out[k] = 0;
      for (j = 0; j < C; j = j + 1) {
         long double complex mm = M[k*R+j] * V[j];
         out[k] = out[k] + mm;
      } 
   }
   for (j = 0; j < C; j = j + 1) {
      A[j] = out[j]/comp;
   }
//   return out;
}
// in is how many 2pi
long double complex  approx (long double complex * coeff, double in, int N) {
   int i;
   long double complex out = 0;
   for (i = 0; i < N; i = i + 1) {
     out = out + euler((i - N/2.0)*in)*coeff[i]; 
   } 
   return out;
}

int main () {
   int N = 128;
   double N_comp = N*1.0;
   double seed [N];  
   int i, j; // for looping
   for (i = 0; i < N; i = i + 1) {
      seed[i] = i / N_comp;
   }
  
   long double complex F [N][N]; 

   for (i = 0; i < N; i = i + 1) {
      for (j = 0; j < N; j = j + 1) {
 //        printf("%1f \n", -1.0*seed[i]*j*(2.0/8.0));
         F[i][j] = euler(-1.0*(i-N_comp/2.0)*j/N_comp);
      }
   }
 
   for (i = 0; i < N; i = i + 1) {
//      printf("start of %d row before divded by N \n", i);
      for (j = 0; j < N; j = j + 1) {
//   printf ("%1f, %1fi\n", crealf(F[i][j]), cimagf(F[i][j]));
      }
//      printf("\n");
   }
   FILE * fp0;
   FILE * fp1;
   FILE * fp2;
   FILE * fp3;
   FILE * fp4;
   fp0 = fopen("data0.txt", "w+");
   fp1 = fopen("data1.txt", "w+");
   fp2 = fopen("data2.txt", "w+");
   fp3 = fopen("data3.txt", "w+");

   double f[N];
   double size = N;    

   printf("start of data point \n", i);
   for (i = 0; i < N; i = i + 1) {
         f[i] = func((i/N_comp));
  //       printf("%1f \n", f[i]);
   }
   long double complex F_special[N*N];
   for (i = 0; i < N; i = i + 1) {
      for (j = 0; j < N; j = j + 1) {
         F_special[i*N+j] = F[i][j];
      }
   }
   long double complex A[N];
   DMV(F_special, A, f, N, N);
   
   printf("start of coefficient \n", i);
   for (i = 0; i < N; i = i + 1) {
//         printf("%1f %1fi\n", crealf(A[i]), cimagf(A[i]));
         fprintf (fp1, "%e \n", crealf(A[i])*crealf(A[i]) + cimagf(A[i])*cimagf(A[i]));
   }
   double actual [256];
   printf("start of actual point \n", i);
   for (i = 0; i < 256; i = i + 1) {
         actual[i] = func((i/256.0));
         fprintf (fp0, "%e \n", actual[i]);
  //       printf("%1f \n", actual[i]);
   }
   long double complex test [256];
   printf("start of test output \n", i);
   for (i = 0; i < 256; i = i + 1) {
        test [i] = approx(A, i/256.0, N);
//         printf("%1f %1fi\n", crealf(test[i]), cimagf(test[i]));
         fprintf (fp2, "%e \n", crealf(test[i]));
         fprintf (fp3, "%e \n", cimagf(test[i]));
   }
/*   
   double mid[N];
   printf("start of mid point \n", i);
   for (i = 0; i < N - 1; i = i + 1) {
         mid[i] = func(((i+0.5)/N_comp));
         printf("%1f \n", mid[i]);
   }
   long double complex test_mid [N];
   printf("start of test mid output \n", i);
   for (i = 0; i < N - 1; i = i + 1) {
        test_mid [i] = approx(A, (i + 0.5)/N_comp, N);
         printf("%1f %1fi\n", crealf(test_mid[i]), cimagf(test_mid[i]));
   }
   
   double mid_2d[N];
   printf("start of mid point second derivative \n", i);
   for (i = 0; i < N - 1; i = i + 1) {
         mid_2d[i] = func_2d(((i+0.5)/N_comp));
         printf("%1f \n", mid_2d[i]);
   }
   long double complex test_mid_2d [N];
   printf("start of test mid output second derivative \n", i);
   for (i = 0; i < N - 1; i = i + 1) {
        test_mid_2d [i] = approx_2d(A, (i + 0.5)/N_comp, N);
         printf("%1f %1fi\n", crealf(test_mid_2d[i]), cimagf(test_mid_2d[i]));
   }
*/
   close (fp0); 
   close (fp1); 
   close (fp2); 
   close (fp3); 
   close (fp4); 
   return 0;
}
