#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main () {
   # define POINT 12
   # define MUL   2
   # define ROUND 10
   int point = POINT;
   int kk;
   FILE * fp0;
   FILE * fp1;
   FILE * fp2;
   fp0 = fopen("dr.txt", "w+");
   fp1 = fopen("l2_norm.txt", "w+");
   fp2 = fopen("time.txt", "w+");
   for (kk = 0; kk < ROUND; kk = kk + 1) {  
/*
   clock stuff
 */
//  clock_t start_t, end_t, total_t;
  struct timeval begin, end;
/*
   start of don't touch
*/   
   double point_comp = point*1.0;
   double Ri = 0.5;
   double Ro = 1.0;
   double u  = 0.00001;
   double pz = -2.5;
   double k  = pz/u;
   double dr = (Ro - Ri) / (point_comp + 1.0);
   double dr_sq = dr*dr;
/*
   end of don't touch
*/ 
//   start_t = clock();
   gettimeofday(&begin, 0);
/*
   define original matrix
*/   
   double a[point];
   double b[point];
   double c[point];
   // boundaries of a b c
   b[0] = 0;
   c[point-1] = 0;   
   int i;
   double j;
   double r;
   for (i = 1; i < point; i = i + 1) {
      j = (i+1)*1.0;
      r = dr*j+Ri;
      b[i] = (1.0 - dr/(2*r)) / dr_sq; 
   } 
   for (i = 0; i < point; i = i + 1) {
      a[i] = (-2.0)*(1.0) / dr_sq; 
   }  
   for (i = 0; i < point-1; i = i + 1) {
      j = (i+1)*1.0;
      r = dr*j+Ri;
      c[i] = (1.0 + dr/(2*r)) / dr_sq; 
   }
/*
   create L U matrix from original matrix
*/
   double B[point];
   double A[point];
   double C[point];
   B[0] = 0;
   C[point-1] = 0;
   A[0] = a[0];  
   for (i = 0; i < point-1; i = i + 1) {
      C[i] = c[i];
   } 
   for (i = 1; i < point; i = i + 1) {
      B[i] = b[i] / A[i-1] ;
      A[i] = a[i] - B[i]*C[i-1]; 
   } 
/*
   Solve Ly=b
 */ 
   double y[point];
   double tmp;
   y[0] = k;
   for (i = 1; i < point; i = i + 1) {
      tmp = y[i-1]*B[i];
      y[i]= (k-tmp);  
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
//   end_t = clock();
   gettimeofday(&end, 0);
   long seconds = end.tv_sec - begin.tv_sec;
   long mseconds = end.tv_usec - begin.tv_usec;
   double passed = seconds + 0.000001*mseconds;
//   total_t = (double) (end_t - start_t);
/*
   exact solution
 */
   double c2 = k/4.0;
   double c1 = c2*(Ro*Ro - Ri*Ri)/(log(Ri)-log(Ro));
   double c0 = c2*(Ri*Ri*log(Ro) - Ro*Ro*log(Ri))/(log(Ri)-log(Ro));
   double exact[point];
   for (i = 0; i < point; i = i + 1) {
      j = (i+1)*1.0;
      r = dr*j+Ri;
      exact[i] = c2*r*r + c1*log(r) + c0;
   }
/*
   print result
 */
   for (i = 0; i < point; i = i + 1) {
  //    printf("datapoint %d, exact is %1f, numeric is %1f \n", i+1, exact[i], x[i]);
   }

/*
   calculate L2 norm
 */
   double l2_norm = 0;
   for (i = 0; i < point; i = i + 1) {
      tmp = (exact[i]-x[i])*(exact[i]-x[i]);
      l2_norm = l2_norm + tmp;
   }
   l2_norm = l2_norm/point_comp;
   l2_norm = sqrt(l2_norm);
//   printf ("point is %d, execution time is %1f \n", point, total_t);
//   printf ("point is %d, execution time is %1f \n", point, passed);
//   printf ("dr is %1f, l2 norm is %1f \n", dr, l2_norm);
   fprintf (fp0, "%e \n", dr);
   fprintf (fp1, "%e \n", l2_norm);
   fprintf (fp2, "%e \n", passed);
   point = point*MUL; 
   }
   close (fp0); 
   close (fp1); 
   close (fp2); 
   return 0;
}
