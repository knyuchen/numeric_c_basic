#include <stdio.h>
#include <math.h>
typedef struct {
   enum {EMPTY, AVAIL, FULL} state;
   int input;
   int output;
} fsm_data;

void init_fsm (fsm_data* fsm_in) {
   printf("\nInitializing \n \n");
   fsm_in->state = EMPTY;
   fsm_in->input = 0;
   fsm_in->output = 0;
}


void print_fsm (fsm_data fsm_in) {
   printf("-------------------\n");
   if (fsm_in.state == EMPTY) {
      printf("FSM state is EMPTY \n");
   }
   else if (fsm_in.state == AVAIL) {
      printf("FSM state is AVAIL \n");
   }
   else if (fsm_in.state == FULL) {
      printf("FSM state is FULL \n");
   }
   printf("output is %d \n", fsm_in.output);
   printf("-------------------\n\n");
}

int take_input () {
  int input = 10;
  while (input == 10) { // make sure input is valid
  printf ("input 1 for u, -1 for d, 0 for stop, 2 for reset \n");
  scanf("%d", &input);
  if (input == 0) {
     printf ("Valid Input: Stop \n \n");
  }
  else if (input == 1) {
     printf ("Valid Input: u \n \n");
  }
  else if (input == -1) {
     printf ("Valid Input: d \n \n");
  }
  else if (input == 2) {
     printf ("Valid Input: Reset \n \n");
  }
  else {
     input = 10;
     printf ("Invalid Input: try again \n");
  }
  }
  return input;
}

void fsm_step (fsm_data* fsm_in) {
   #define MAX    6
   if (fsm_in->input == 2) {
      init_fsm(fsm_in);
   }
   else {
   switch (fsm_in->state) {
      case EMPTY:
         if (fsm_in->input == 1) {
            fsm_in->output = 1;
            fsm_in->state = AVAIL;
         }
         else {
            printf("can't do d, already EMPTY \n");
         }
         break;
      case AVAIL:
         if (fsm_in->input == 1) {
            fsm_in->output = fsm_in->output + 1;
         }
         else {
            fsm_in->output = fsm_in->output - 1;
         }
         if (fsm_in->output == 0) {
            fsm_in->state = EMPTY;
         }
         else if (fsm_in->output == MAX) {
            fsm_in->state = FULL;
         } 
         break;
      case FULL:
         if (fsm_in->input == -1) {
            fsm_in->output = MAX-1;
            fsm_in->state = AVAIL;
         }
         else {
            printf("can't do u, already FULL \n");
         }
         break;
   }
   }   
}

int main () {
   fsm_data* fsm_ptr;
   fsm_data  fsm;
   fsm_ptr = &fsm;
   init_fsm (fsm_ptr);
   print_fsm(fsm);
   int current_input = 10;
   while (current_input != 0){  // make sure stop function is working
      current_input = take_input();
      if (current_input != 0) {
         fsm.input = current_input;
         fsm_step(fsm_ptr);
      }
      print_fsm(fsm);
   }
   return 0;
}
