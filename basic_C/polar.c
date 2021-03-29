#include <stdio.h>
#include <math.h>

int main () {
   float r_in, degree_in;
   
   printf("Please enter a distance in meters and an angle in degrees. \n");

   scanf("%f %f", &r_in, &degree_in);
   printf ("distance is %f \n", r_in);
   printf ("angle is %f \n", degree_in);

   double radian;
   radian = M_PI/180.0;
   double x, y;
   double c;

   if (r_in < 0) {
      printf ("Error : distance cannot be negative. \n");
   }
   else {

      x = r_in*cos(degree_in*radian);
      y = r_in*sin(degree_in*radian);
      printf ("coordinate is (%f, %f) \n", x, y);
   }


   return 0;
}
