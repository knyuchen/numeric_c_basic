#include <stdio.h>
#include <math.h>

void print_addr (int x) {
   printf ("%p \n\n", &x);

}


int main () {
   int a = 3;

   printf ("%p \n\n", &a);

   print_addr(a);   

   return 0;
}
