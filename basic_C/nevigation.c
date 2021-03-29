#include <stdio.h>
#include <math.h>

void fly (double latA, double latB, double longA, double longB) {
   
   double radian;
   radian = M_PI/180.0;
   
   printf("Starting Point : Latitude %1f, Longtitude %1f \n" , latA, longA);
   printf("Destination    : Latitude %1f, Longtitude %1f \n" , latB, longB);
   
   if (latA > 90 || latA < -90 || latB > 90 || latB < -90 || longA >180 || longA < -180 || longB > 180 || longB < -180) {
      printf("Error: Invalid Input \n\n");
   }

   else if (latA == latB && longA == longB) {
      printf("Destination is the same as starting point. \n\n");
   }

   else {
      double a;
      a = pow(sin((latB-latA)*radian*0.5), 2) + cos(latA*radian)*cos(latB*radian)*pow(sin((longB-longA)*radian*0.5), 2);
      double R = 3440.0;
      double y = sqrt(a);
      double x = sqrt(1-a);

      double d;

      if (x == 0) {
         d = 2*R*M_PI/2.0;
      }
      else {
         d = 2*R*atan2(y,x);
      }
  
      double deg;

      y = sin((longB-longA)*radian)*cos(latB*radian);
      x = cos(latA*radian)*sin(latB*radian) - sin(latA*radian)*cos(latB*radian)*cos((longA-longB)*radian); 
  
      if (x == 0) {
         if (y > 0) {
            deg = radian*M_PI/2.0;
         }
         else {
            deg = radian*-1*M_PI/2.0;
         }
      }
      else {
         deg = atan2(y,x)/radian;
         if (deg < 0) {
            deg = deg + 360;
         }
      }
      printf("Fly heading %1f degrees for %1f nautical miles \n\n", deg, d);
   }
}


int main () {
   double latA_in, latB_in, longA_in, longB_in;
/*
   latA_in = 20.0;
   longA_in = 30.0;
   latB_in = 20.0;
   longB_in = 50.0;
   fly(latA_in, latB_in, longA_in, longB_in);

   latA_in = 30.0;
   longA_in = 40.0;
   latB_in = 50.0;
   longB_in = 40.0;
   fly(latA_in, latB_in, longA_in, longB_in);

   latA_in = 60.0;
   longA_in = 70.0;
   latB_in = 60.0;
   longB_in = 70.0;
   fly(latA_in, latB_in, longA_in, longB_in);

   latA_in = 200.0;
   longA_in = 70.0;
   latB_in = -100.0;
   longB_in = 80.0;
   fly(latA_in, latB_in, longA_in, longB_in);

   latA_in = -12.0;
   longA_in = 120.0;
   latB_in = 23.0;
   longB_in = -45.0;
   fly(latA_in, latB_in, longA_in, longB_in);

   latA_in = 90.0;
   longA_in = 20.0;
   latB_in = 40.0;
   longB_in = 25.0;
   fly(latA_in, latB_in, longA_in, longB_in);
*/   
   return 0;
}
