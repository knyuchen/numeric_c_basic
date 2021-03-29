#include <stdio.h>
#include <math.h>
#include <stdlib.h>



double actual (double in, double dt, double dx_sq) {
   double out = exp(-1.0*1.0*dt*in*in/(4.0*dx_sq*M_PI*M_PI));
   return out;
}
double BTCS (double in, double dt, double dx_sq) {
   double out = 1.0/(1.0+2.0*dt*(1.0-cos(in/(2.0*M_PI)))/dx_sq);
   return out;
}
double FTCS (double in, double dt, double dx_sq) {
   double out = 1.0+2.0*dt*(cos(in/(2.0*M_PI))-1.0)/dx_sq;
   return out;
}


int main () {
   double dx_sq = 16*M_PI*M_PI/10000.0;
   double dt = 0.0025;
   FILE * fp0;
   FILE * fp1;
   FILE * fp2;
   FILE * fp3;
   int i;
   double in;
   fp0 = fopen("exact.txt", "w+");
   fp1 = fopen("FTCS.txt", "w+");
   fp2 = fopen("BTCS.txt", "w+");
   fp3 = fopen("grid.txt", "w+");
   for (i = 0; i < 200; i = i + 1) { 
      in = i*1.0*8.0*M_PI/200.0; 
      fprintf (fp0, "%e \n", actual(in, dt, dx_sq));
      fprintf (fp1, "%e \n", FTCS(in, dt, dx_sq));
      fprintf (fp2, "%e \n", BTCS(in, dt, dx_sq));
      fprintf (fp3, "%e \n", in);
   }
   close (fp0); 
   close (fp1); 
   close (fp2); 
   close (fp3); 
   return 0;
}
