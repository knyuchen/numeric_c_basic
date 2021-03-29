#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double actual (double in, double t) {
   double real_in = in*M_PI/25.0;
   double out = 4.0*sin(real_in)*exp(-1.0*t) + 2.0*sin(3.0*real_in)*exp(-9.0*t)+sin(10*real_in)*exp(-100.0*t);
   return out;
}


int main () {
   // dt is around 0.063165
   #define ROUND 40
   #define target 2.5
   int i, j;
   double exact[100];
   double dt = 4.0*16.0*M_PI*M_PI/10000.0;
   double round = ROUND*1.0;
   double TARGET = target;  
   double dx = 4.0*M_PI/100.0;
   double dx_sq = dx*dx;
   printf("dt is %1f, target is %1f\n", dt, TARGET);

   /*
     storage and parameter for forward
   */
   double FT_base[102];
   double FT_tmp[102];
   double Fa = -1.0*3;
   double Fb = 2.0;
   int FT_point = 100;
   /*
     storage and parameter for backward
   */
   double base[99];
   double dummy[99];  // negative of last column
   double output[99];
   int point = 99;
   double a = 5.0;
   double b = -1.0*2;
   double xn = 0;
/*
   open some files
 */
   FILE * fp0;
   FILE * fp1;
   fp0 = fopen("exact.txt", "w+");
   fp1 = fopen("output.txt", "w+");
/*
   end of don't touch
*/ 
/*
   prepare initial at t = 0
 */
   for (i = 0; i < 99; i = i + 1) {
      base[i] = actual(i, 0);
      exact[i] = actual(i, TARGET);
      dummy[i] = 0;
   }
   exact[99] = actual(99, TARGET);
   xn = actual (99, 0);
   dummy[0] = -1.0*b;
   dummy[98] = -1.0*b;
/*
   create L U matrix from original matrix
*/
   double B[point];
   double A[point];
   double C[point];
   B[0] = 0;
   C[point-1] = 0;
   A[0] = a;  
   for (i = 0; i < point-1; i = i + 1) {
      C[i] = b;
   } 
   for (i = 1; i < point; i = i + 1) {
      B[i] = b / A[i-1];
      A[i] = a - B[i]*C[i-1]; 
   }
/*
   solve dummy (only once)
 */
   double dummy_y[point];
   double dummy_tmp;
   dummy_y[0] = dummy[0];
   for (i = 1; i < point; i = i + 1) {
      dummy_tmp = dummy_y[i-1]*B[i];
      dummy_y[i]= (dummy[i]-dummy_tmp);  
   } 
   double dummy_x[point];
   dummy_x[point-1] = dummy_y[point-1]/A[point-1];
   for (i = 2; i < point+1; i = i + 1) {
      dummy_tmp = dummy_x[point-i+1]*C[point-i];
      dummy_x[point-i] = (dummy_y[point-i]-dummy_tmp)/A[point-i];
   }

/*
   start of loop
 */

for (j = 0; j < ROUND; j = j + 1) {
/*
   copy data from base to FT_base
 */

   for (i = 0; i < FT_point-1; i = i + 1) {
      FT_base[i+1] = base[i];
   }
   FT_base[FT_point] = xn;
   FT_base[0] = FT_base[FT_point];
   FT_base[FT_point+1] = FT_base[1];

/*
   do forward 
 */
   for (i = 0; i < 100; i = i + 1) {
      FT_tmp[i+1] = Fb*FT_base[i]+Fa*FT_base[i+1]+Fb*FT_base[i+2];
   }     
         FT_tmp[0] = FT_tmp[100];
         FT_tmp[101] = FT_tmp[1];

/*
   copy data from FT_tmp to base
 */
   for (i = 0; i < point; i = i + 1) {
      base[i] = FT_tmp[i+1];
   }
   xn = FT_tmp[100];
/*
   Solve Ly=b
 */
//for (j = 0; j < ROUND; j = j + 1) { 
   double y[point];
   double tmp;
   y[0] = base[0];
   for (i = 1; i < point; i = i + 1) {
      tmp = y[i-1]*B[i];
      y[i]= (base[i]-tmp);  
   } 
  
/*
   Solve Ux=y
 */

   double x[point];
   x[point-1] = y[point-1]/A[point-1];
   for (i = 2; i < point+1; i = i + 1) {
      tmp = x[point-i+1]*C[point-i];
      x[point-i] = (y[point-i]-tmp)/A[point-i];
   }
/*
   get final new base
 */
   xn = (xn - b*(x[0] + x[98]))/(a+b*(dummy_x[0] + dummy_x[98]));
//   printf("xn = %1f \n", xn);
   for (i = 0;i < 99; i = i + 1) {
      base[i] = x[i] + xn*dummy_x[i];
   }
}
/*
   calculate L2 norm
 */
   double l2_norm = 0;
   double norm_tmp = 0;
   for (i = 0; i < 99; i = i + 1) {
      norm_tmp = (exact[i]-base[i])*(exact[i]-base[i]);
      l2_norm = l2_norm + norm_tmp;
   }
   norm_tmp = (exact[99] - xn)*(exact[99] - xn);
   l2_norm = l2_norm + norm_tmp;
   l2_norm = l2_norm/100.0;
   l2_norm = sqrt(l2_norm);
   printf ("l2 norm is %1f \n", l2_norm);
/*
  print result
*/
   for (i = 0; i < 99; i = i + 1) {
      fprintf (fp0, "%e \n", exact[i]);
      fprintf (fp1, "%e \n", base[i]);
//      printf ("%d, numeric = %1f, exact = %1f \n", i, base[i], exact[i]);
   }
//   printf ("%d, numeric = %1f, exact = %1f \n", point, xn, exact[99]);
      fprintf (fp0, "%e \n", exact[99]);
      fprintf (fp1, "%e \n", xn);
   close (fp0); 
   close (fp1); 
   return 0;

}
