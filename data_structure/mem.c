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

int mem_recursive (intlist* l, int a){
   int monitor;
   if (l->tail == NULL) {
      if (l->head == a) {
        return 1;
      }
      else {
        return 0;
      }
   }
   else {
      if (l->head == a) {
        monitor = mem_recursive(l->tail, a) + 1;
      }
      else {
        monitor = mem_recursive(l->tail, a) + 0;
      }
   }
   if (monitor > 0) {
      monitor = 1;
   }
   return monitor;
}

int mem_loop (intlist* l, int a){
   int monitor = 0;
   intlist* tmp;
   tmp = l;
   while (tmp-> tail != NULL) {
      tmp = tmp->tail;
      if (tmp -> head == a) {
         monitor = monitor + 1;
      }
   }
   if (monitor > 0) {
      monitor = 1;
   }
   return monitor;
}
int mem(intlist* l, int a) {
    int k = 0;
    if (l == NULL) {
       printf ("NULL list \n");
    }
    else {
//    k = mem_loop(l, a);
  k = mem_recursive(l, a);
    }
   return k;
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
   int monitor;
   
   monitor = mem (l, 7);
//   monitor = mem (l, 9);

   if (monitor == 1) {
      printf("element is in list \n");
   }
   else {
      printf("element is not in list \n");
   }

   free_list(l);
   return 0;
}
