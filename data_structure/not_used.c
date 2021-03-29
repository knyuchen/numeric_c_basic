#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct intlist_t {
// Linked list data structure
  int head;
  struct intlist_t* tail;
} intlist;

void print_list(intlist* l) {
  intlist* l1 = l;
  printf("[ ");
  while(l1 != NULL) {
    printf("%d ", l1->head);
    l1 = l1->tail;
  }
  printf("]\n");
}

intlist* cons(int v, intlist* l){
  // adds an element at the beginning of list l
  // does not modify l
  intlist* res = NULL;
  res = malloc(sizeof(intlist));
  res->head = v;
  res->tail = l;
  return res;
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

void rev_aux(intlist* l1, intlist** l2) {
  // pours l1 into l2, in place, returning (rev(l1) @ l2)
  if(l1 != NULL) {
    *l2 = cons(l1->head, *l2);
    rev_aux(l1->tail, l2);
  }
}
intlist* rev(intlist* l) {
  // reverses a list, functional
  intlist* res = NULL;
  rev_aux(l, &res);
  return res;
}

void cons_end(int v, intlist** l) {
  // adds an element at the end of list l
  // l is modified in place
  intlist* l1 = *l;
  if(*l == NULL) {
    *l = cons(v, NULL);
  } else {
    while(l1->tail != NULL) {
      l1 = l1->tail;
    }
    l1->tail = cons(v, NULL);
  }
}

typedef struct queue_content {
   intlist* begin;
   intlist* end;
} queue;

void free_queue (queue* q) {
   free_list(q->begin);
   free_list(q->end);
   free(q);
}

queue empty (void) {
   queue*  q_ptr;
   q_ptr = malloc (sizeof(queue));
   q_ptr->begin = NULL;
   q_ptr->end   = NULL;
   return *q_ptr;  
}

void print_queue (queue q) {
   intlist* print_begin = q.begin;
   intlist* print_end = rev(q.end);
   printf("[ ");
   while(print_begin != NULL) {
     printf("%d ", print_begin->head);
     print_begin = print_begin->tail;
   }
   while(print_end != NULL) {
     printf("%d ", print_end->head);
     print_end = print_end->tail;
   }
   printf("]\n");
//   free_list(print_begin); 
//   free_list(print_end); 
   
}
queue enqueue_help (int i, queue q) {
   queue q2;
   if (q.begin == NULL && q.end == NULL) {
      q2.begin = cons(i, q.begin);
   }
   else {
      q2.end = cons(i, q.end); 
   }
   return q2;
}
void enqueue (int i, queue q) {
/*
   if (q.begin == NULL && q.end == NULL) {
      q.begin = cons(i, q.begin);
   }
   else {
      q.end = cons(i, q.end); 
   }
*/
   q = enqueue_help(i, q);
}

int dequeue (queue q) {
   if (q.begin == NULL) {
      if (q.end == NULL) {
         return -1;
      }
      else {
         q.begin = rev(q.end);
         free_list(q.end);
         q.end = NULL;
         intlist* tmp = q.begin;
         q.begin = q.begin->tail;
         int out = tmp->head;
         return out;
      }
   }
   else {
      intlist* tmp = q.begin;
      q.begin = q.begin->tail;
      int out = tmp->head;
      return out;
   }
}

int main () {
/*
 initialize an empty queue
*/

  queue* q_pt = malloc(sizeof(queue));
  *q_pt = empty();

/*
  enqueue some content & print
*/ 

  int i;
  for (i = 0; i < 5; i = i + 1) {
    enqueue(i, *q_pt);
    print_queue(*q_pt);
  }

/*
  dequeue some content & print
 */

  int out;
  for (i = 0; i < 5; i = i + 1) {
    out = dequeue(*q_pt);
    printf("%d \n", out);
    print_queue(*q_pt);
  }


/*
 free queue
*/
   free_queue(q_pt);
   return 0;
}
