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
void cons_end(int v, intlist** l) {  
   // adds an element at the end of list l  
   // l is modified in place  
   intlist* l1 = *l;  
   if(*l == NULL) {    
      *l = cons(v, NULL);  
   } 
   else {    
      while(l1->tail != NULL) {      
         l1 = l1->tail;    
      }    
      l1->tail = cons(v, NULL);  
   }
}

int list_length_recursive (intlist* l){
   int monitor;
   if (l->tail == NULL) {
      return 1;
   }
   else {
      monitor = list_length_recursive(l->tail) + 1;
   }
   return monitor;
}
int* list2array (intlist* l){
   int length = list_length_recursive (l);
   int* array = malloc(length*sizeof(int));
   intlist* tmp = l;  // sliding helper at original
   int i;
   for (i = 0; i < length; i = i + 1) {
      array[i] = tmp->head;
      tmp = tmp->tail;
   }
   return array; 
}
int main () {
/*
   Initialize a list  of 3, 7, 8
 */
   intlist* l = cons(3, cons(7, cons(8, NULL)));

   
   int* array = list2array (l);
   int i;

   for (i = 0; i < 3; i = i + 1) {
      printf("%d \n", array[i]);
   }


   return 0;
}
