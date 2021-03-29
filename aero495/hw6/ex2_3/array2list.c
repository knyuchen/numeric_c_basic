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
intlist* array2list_loop (int arr[], int size){
   intlist* l = NULL;  // sliding helper at original
   if (size == 1) {
      l=cons(arr[size-1], l);
   }
   else {
      l = array2list_loop(arr, size-1);
   }
   return l; 
}

intlist* array2list_recursive (int arr[], int size){
   intlist* l = NULL;  // sliding helper at original
   int i;
   for (i = 0; i < size; i = i + 1) {
      l = cons(arr[size-i-1], l);
   }
   return l; 
}

int main () {
/*
   Initialize a list  of 3, 7, 8
 */
//   intlist* l = cons(3, cons(7, cons(8, NULL)));
   int entry = 3;
   int* array  = malloc(entry*sizeof(int));
   array[0] = 3;
   array[1] = 7;
   array[2] = 8;
 
//   intlist* copy = array2list_loop(array, entry);  
   intlist* copy = array2list_recursive(array, entry);  

   printf ("%d \n", copy-> head);
   printf ("%d \n", copy-> tail ->head);
   printf ("%d \n", copy-> tail -> tail -> head);

   return 0;
}
