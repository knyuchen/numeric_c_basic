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
void free_list(intlist* l) {  
   // frees a list  
   intlist* tmp;  
   while (l != NULL) {    
      tmp = l;    
      l = l->tail;    
      free(tmp);  
   }
}
void print_list_alt(intlist* l) {  
   intlist* l1 = l;  
   printf("[ ");  
   if(l1 == NULL) {  
   } 
   else {    
      while(l1->tail != NULL) {      
         printf("%d ", l1->head);      
         l1 = l1->tail;    
      }    
      printf("%d ", l1->head);  
   }  
   printf("]\n");
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

intlist* list_copy (intlist* l){
   intlist * copy_head = NULL;
   intlist ** p_copy_head = &copy_head;
   intlist* tmp = l;  // sliding helper at original
   intlist* tmp2 = l;  // helping place holder 
   if(l == NULL) {  
   } 
   else {    
   do {
      tmp = tmp2;
      cons_end(tmp->head, p_copy_head);
      if (tmp -> tail != NULL) { 
         tmp2 = tmp->tail;
      }
   } while (tmp -> tail != NULL);
   }
   return copy_head;
}
int* list2array (intlist* l){
   int length = list_length(l);
   if (length == 0) {
      printf ("NULL list\n");
      return NULL;
   }
   else {
   int* array = malloc(length*sizeof(int));
   intlist* tmp = l;  // sliding helper at original
   int i;
   for (i = 0; i < length; i = i + 1) {
      array[i] = tmp->head;
      tmp = tmp->tail;
   }
   return array; 
   }
}
intlist* array2list_recursive (int arr[], int size){
   intlist* l = NULL;  // sliding helper at original
   if (size == 0) {
      l=cons(arr[size], l);
   }
   else {
      l = cons(arr[size], array2list_recursive(arr, size-1));
   }
   return l; 
}

intlist* array2list_loop (int arr[], int size){
   intlist* l = NULL;  // sliding helper at original
   int i;
   for (i = 0; i < size; i = i + 1) {
      l = cons(arr[size-i-1], l);
   }
   return l; 
}
intlist* array2list(int arr[], int size) {
    intlist* k = NULL;
    if (arr == NULL) {
       printf ("NULL array \n");
    }
    else {
    k = array2list_loop(arr, size);
//  k = array2list_recursive(arr, size);
    }
   return k;
}
intlist* cons_end_functional (int v, intlist* l){
   intlist * copy_head = NULL;
   intlist ** p_copy_head = &copy_head;
   intlist* tmp = l;  // sliding helper at original
   intlist* tmp2 = l;  // helping place holder 
   do {
      tmp = tmp2;
      cons_end(tmp->head, p_copy_head);
      if (tmp -> tail != NULL) { 
         tmp2 = tmp->tail;
      }
   } while (tmp -> tail != NULL);
   cons_end (v, p_copy_head);
   return copy_head;
}
int main () {
/*
   Initialize a list  of 3, 7, 8
 */
   #define INITIAL_LIST_SIZE 3
//   intlist* l = cons(3, cons(7, cons(8, NULL)));

   intlist* l = NULL;
   printf ("\nlist is");
   print_list_alt(l);

/*
   test exercise 1 - 1 
*/
   printf ("\n***test exercise 1-1*** \n");
   int length;
   
   printf ("\nlist is");
   print_list_alt(l);
   length = list_length (l);
   if (length == 0) {
      printf("NULL list \n");
   }
   else {
      printf ("length is %d \n", length);
   }
   
/*
   test exercise 1 - 2 
*/
   printf ("\n***test exercise 1-2*** \n");
   printf ("\nlist is");
   print_list_alt(l);
   int monitor;
   int element = 7;
   monitor = mem (l, element);

   if (monitor == 1) {
      printf("element %d is in list \n", element);
   }
   else {
      printf("element %d is not in list \n", element);
   }
/*
   test exercise 2 - 1 
*/
   printf ("\n***test exercise 2-1*** \n");
   printf ("original :");
   print_list_alt(l);
   intlist* copy =  NULL;
   
   copy = list_copy (l);
   printf ("copy :");
   print_list_alt(copy);
   if (l != NULL) {
      printf ("make second one of copy to be 2\n");
      copy->tail->head = 2;
      printf ("original :");
      print_list_alt(l);
      printf ("copy :");
      print_list_alt(copy);
      
      printf ("make first one of original to be 4\n");
      copy->head = 4;
      printf ("original :");
      print_list_alt(l);
      printf ("copy :");
      print_list_alt(copy);
   }
/*
   test exercise 2 - 2 
*/
   printf ("\n***test exercise 2-2*** \n");
   printf ("list :");
   print_list_alt(l);
   int* array = list2array (l);
   int i;
   if (array != NULL) {
   printf ("array: ( ");
   for (i = 0; i < INITIAL_LIST_SIZE; i = i + 1) {
      printf("%d ", array[i]);
   }
   printf (")\n");
   }
   else{ 
   printf ("array: ( ");
   printf (")\n");
   }
   
/*
   test exercise 2 - 3 
*/
   printf ("\n***test exercise 2-3*** \n");
   int entry = INITIAL_LIST_SIZE;
//   int* arr = NULL;

   int* arr  = malloc(entry*sizeof(int));
   arr[0] = 3;
   arr[1] = 7;
   arr[2] = 8;
 
   if (arr != NULL) {
   printf ("array: ( ");
   for (i = 0; i < INITIAL_LIST_SIZE; i = i + 1) {
      printf("%d ", arr[i]);
   }
   printf (")\n");
   }
   else{ 
   printf ("array: ( ");
   printf (")\n");
   }
   intlist* copy_list = array2list(arr, entry);  
   printf ("Result :");
   print_list_alt(copy_list);
/*
   test exercise 3 - 1 
*/
   printf ("\n***test exercise 3-1*** \n");
   printf ("add new element to list\n");

//   intlist * new_extend = NULL;
//   new_extend = cons_end_functional (9, l);
/*   printf ("original :");
   print_list_alt(l);
   printf ("\nnew_extend :");
   print_list_alt(new_extend);
*/
/*
  free memory
*/
   free_list(l);
   free_list(copy);
   free_list(copy_list);
//   free_list(new_extend);
   return 0;
}
