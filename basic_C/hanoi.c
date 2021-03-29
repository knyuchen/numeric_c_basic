#include <stdio.h>
#include <math.h>


void hanoi_shuffle (int n, char start, char help, char end) {
   if (n == 1) {
      printf ("Make a move from %c to %c. \n", start, end);
   }
   else {
      hanoi_shuffle(n-1, start, end, help); // move top n-1
      printf ("Make a move from %c to %c. \n", start, end); // move n
      hanoi_shuffle(n-1, help, start, end); // move top n-1
   }
      
}

void hanoi (int n) {
  if (n < 1) {
     printf ("no disk at all \n");
  }
  else {
     printf ("************************\n");
     printf ("*Hanoi Tower for %d disk* \n", n);
     printf ("************************\n");
     hanoi_shuffle (n, 'A', 'B', 'C');
  }
} 


int main () {
   hanoi(3);
//   hanoi(0);
//   hanoi(-2);
  
//   hanoi(6);
   return 0;
}
