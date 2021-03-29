#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct intlist_t {
   int    head;
   struct intlist_t* tail;
} intlist;

intlist* cons(int v, intlist* l){  
   intlist* res = NULL;  
   res = malloc(sizeof(intlist));  
   res->head = v;  
   res->tail = l;  
   return res;
}

int list_length_recursive (intlist* l){
   int monitor;
   if (l == NULL) {
      monitor = 0;
   }
   else {
   if (l->tail == NULL) {
      return 1;
   }
   else {
      monitor = list_length_recursive(l->tail) + 1;
   }
   }
   return monitor;
}

int list_length_loop (intlist* l){
   int monitor = 1;
   intlist* tmp;
   tmp = l;
   if (tmp == NULL) {
      monitor = 0;
   }
   else {
   while (tmp-> tail != NULL) {
      tmp = tmp->tail;
      monitor = monitor + 1;
   }
   }
   return monitor;
}

int list_length (intlist* l){
   int length;
//   length = list_length_loop(l);
   length = list_length_recursive(l);
   return length;
}
void free_list(intlist* l) {  
   // frees a list  
   intlist* tmp;  
   while (l != NULL) {    
      tmp = l;    
      l = l->tail;    
      free(tmp);  
   }
}

int main () {
/*
   Initialize a list  of 3, 7, 8
 */
   intlist* l = cons(3, cons(7, cons(8, NULL)));

//   intlist* l = NULL;
/*
   test 
*/
   int monitor;
   
   monitor = list_length (l);
   if (monitor == 0) {
      printf("NULL list \n");
   }
   else {
      printf ("length is %d \n", monitor);
   }
/*
  free memory
*/
   free_list(l);

   return 0;
}
