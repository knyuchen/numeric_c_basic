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

intlist* list_copy (intlist* l){
   intlist * copy_head = NULL;
   intlist ** p_copy_head = &copy_head;
   intlist* tmp = l;  // sliding helper at original
   intlist* tmp2 = l;  // helping place holder 
//   while (tmp-> tail != NULL) {
   do {
      tmp = tmp2;
      cons_end(tmp->head, p_copy_head);
      if (tmp -> tail != NULL) { 
         tmp2 = tmp->tail;
      }
   } while (tmp -> tail != NULL);
   return copy_head;
}


int main () {
/*
   Initialize a list  of 3, 7, 8
 */
   intlist* l = cons(3, cons(7, cons(8, NULL)));

   intlist* copy =  NULL;
   
   copy = list_copy (l);

   printf ("%d \n", copy-> head);
   printf ("%d \n", copy-> tail ->head);
   printf ("%d \n", copy-> tail -> tail -> head);

   return 0;
}
