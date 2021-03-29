#include <stdio.h>
#include <math.h>
typedef struct {
   enum {STATE0, STATE1, STATE2} state;
   int input;
   int output;
} fsm_data;

void init_fsm (fsm_data* fsm_in) {
   printf("\nInitializing \n \n");
   fsm_in->state = STATE0;
   fsm_in->input = 0;
   fsm_in->output = 0;
}


void print_fsm (fsm_data fsm_in) {
   printf("-------------------\n");
   if (fsm_in.state == STATE0) {
      printf("FSM state is STATE0 \n");
   }
   else if (fsm_in.state == STATE1) {
      printf("FSM state is STATE1 \n");
   }
   else if (fsm_in.state == STATE2) {
      printf("FSM state is STATE2 \n");
   }
   printf("output is %d \n", fsm_in.output);
   printf("-------------------\n\n");
}

int take_input () {
  int input = 10;
  while (input == 10) { // make sure input is valid
  printf ("input 3 ~ 6 for valid input,0 for stop, 2 for reset \n");
  scanf("%d", &input);
  if (input == 0) {
     printf ("Valid Input: Stop \n \n");
  }
  else if (input == 2) {
     printf ("Valid Input: Reset \n \n");
  }
  else if (input > 2 && input < 7) {
     printf ("Valid Input: %d \n \n", input);
  }
  else {
     input = 10;
     printf ("Invalid Input: try again \n");
  }
  }
  return input;
}

void fsm_step (fsm_data* fsm_in) {
   if (fsm_in->input == 2) {
      init_fsm(fsm_in);
   }
   else {
   switch (fsm_in->state) {
      case STATE0:
         break;
      case STATE1:
         break;
      case STATE2:
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
