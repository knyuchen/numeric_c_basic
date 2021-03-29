#include <stdio.h>
#include <math.h>

int preflight (void) {

   float pilot, front;
   float rear1, rear2;
   float bag1, bag2;
   float fuel;
   
   printf("Please enter the pilot's weight in lbs. \n");
   scanf("%f", &pilot);
   printf("Your entered Pilot's weight is %f \n\n", pilot);
   if (pilot == 0 || pilot < 0) {
      return -1;
   }

   printf("Please enter the front seat passenger's weight in lbs. \n");
   scanf("%f", &front);
   printf("Your entered Front seat passenger's weight is %f \n\n", front);
   if (front < 0) {
      return -1;
   }
   
   printf("Please enter the first rear seat passenger's weight in lbs. \n");
   scanf("%f", &rear1);
   printf("Your entered First rear seat passenger's weight is %f \n\n", rear1);
   if (rear1 < 0) {
      return -1;
   }

   printf("Please enter the other rear seat passenger's weight in lbs. \n");
   scanf("%f", &rear2);
   printf("Your entered Other rear seat passenger's weight is %f \n\n", rear2);
   if (rear2 < 0) {
      return -1;
   }

   printf("Please enter the first baggage area's weight in lbs. \n");
   scanf("%f", &bag1);
   printf("Your entered First baggage area's weight is %f \n\n", bag1);
   if (bag1 < 0) {
      return -1;
   }

   printf("Please enter the second baggage area's weight in lbs. \n");
   scanf("%f", &bag2);
   printf("Your entered second baggage area's weight is %f \n\n", bag2);
   if (bag2 < 0) {
      return -1;
   }
   
   printf("Please enter Fuel Load in gallons. \n");
   scanf("%f", &fuel);
   printf("Your entered Fuel Load is %f \n\n", fuel);
   if (fuel < 0 || fuel == 0 || fuel > 48) {
      return -1;
   }

   float airframe = 1431;
   float airframe_cog = 36.21;

   float front_arm = 37;
   float rear_arm = 73;
   float bag1_arm = 95;
   float bag2_arm = 123;
   float fuel_arm = 48;


   float total_weight = pilot + front + rear1 + rear2 + bag1 + bag2 + fuel*6 + airframe;
   float total_moment = (pilot+front)*front_arm + (rear1+rear2)*rear_arm + bag1*bag1_arm + bag2+bag2_arm + fuel*6*fuel_arm + airframe*airframe_cog;
   float total_cog    = total_moment / total_weight;

   float expected_weight = total_cog*100 - 1560;
  

 
   printf("Your total weight (including airframe) is %f \n\n", total_weight);
   printf("Your total moment (including airframe) is %f \n\n", total_moment);
   printf("Your center of gravity is %f \n\n", total_cog);

   int weight_error = 0;
   if   (total_weight > 2300 || total_weight < 1500) {
      weight_error = 1;
   }

   int cog_error;
   if ((total_weight > expected_weight && total_cog < 38.6) || total_cog > 47.3 || total_cog < 35) {
      cog_error = 1;
   }


   if (weight_error == 1) {
      if (cog_error == 1) {
         printf("You cannot fly because weight and moment are outside the operating envelope. \n\n");
         return 0;
      }
      printf("You cannot fly because weight is outside the operating envelope. \n\n");
      return 0;
   }
   else if (cog_error == 1) {
      printf("You cannot fly because moment is outside the operating envelope. \n\n");
      return 0;
   }
   else {
      printf("This plane is ready to fly. \n\n");
      return 1;
   }


}


int main () {
   int result;

   result = preflight();


   if (result == -1) {
      printf("Input Data Error \n\n");
   }

   return 0;
}
