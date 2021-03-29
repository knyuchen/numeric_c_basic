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
} queue_content;

typedef struct queue {
   queue_content* qc;
} queue;

void free_queue (queue* q) {
   free_list(q->qc->begin);
   free_list(q->qc->end);
   free(q->qc);
   free(q);
}

void enqueue (int i, queue q) {
   if (q.qc->begin == NULL && q.qc->end == NULL) {
      q.qc->begin = cons(i, q.qc->begin); 
   }
   else {
      q.qc->end = cons(i, q.qc->end); 
   }
}

int dequeue (queue q) {
   if (q.qc->begin == NULL) {
      if (q.qc->end == NULL) {
         return -1;
      }
      else {
         q.qc->begin = rev(q.qc->end);
         free_list(q.qc->end);
         q.qc->end = NULL;
         intlist* tmp = q.qc->begin;
         q.qc->begin = q.qc->begin->tail;
         int out = tmp->head;
         return out;
      }
   }
   else {
      intlist* tmp = q.qc->begin;
      q.qc->begin = q.qc->begin->tail;
      int out = tmp->head;
      return out;
   }
}

queue empty () {
   queue q;
   q.qc = malloc (sizeof(queue_content));
   q.qc->begin = NULL;
   q.qc->end   = NULL;
   return q;  
}

void print_queue (queue q) {
   intlist* print_begin = q.qc->begin;
   intlist* print_end = rev(q.qc->end);
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
   free_list(print_begin); 
   free_list(print_end); 
   
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
  printf ("\nstart enqueue \n");
  int i;
  for (i = 0; i < 5; i = i + 1) {
    printf("enqueue %d \n", i);
    enqueue(i, *q_pt);
    print_queue(*q_pt);
  }
/*
  dequeue some content & print
 */
  printf ("\nstart dequeue \n");
  int out;
  for (i = 0; i < 5; i = i + 1) {
    out = dequeue(*q_pt);
    if (out == -1) {
       printf ("empty queue\n");
    }
    else {
    printf("out is %d \n", out);
    print_queue(*q_pt);
    }
  }

/*
  enqueue and then dequeue
*/
  printf ("\nenqueue and dequeue \n");
  for (i = 0; i < 3; i = i + 1) {
    printf("enqueue %d \n", 2*i+3);
    enqueue(2*i + 3, *q_pt);
    print_queue(*q_pt);
    printf("enqueue %d \n", 2*i+4);
    enqueue(2*i + 4, *q_pt);
    print_queue(*q_pt);
    printf("dequeue \n");
    out = dequeue(*q_pt);
    if (out == -1) {
       printf ("empty queue\n");
    }
    else {
    printf("out is %d \n", out);
    print_queue(*q_pt);
    }
    printf("dequeue \n");
    out = dequeue(*q_pt);
    if (out == -1) {
       printf ("empty queue\n");
    }
    else {
    printf("out is %d \n", out);
    print_queue(*q_pt);
    }
  }
/*
  dequeue empty queue
*/
  printf ("\ndequeue empty queue \n");
    out = dequeue(*q_pt);
    if (out == -1) {
       printf ("empty queue\n");
    }
    else {
    printf("out is %d \n", out);
    print_queue(*q_pt);
    }
/*
 free queue
*/
   free_queue(q_pt);
   return 0;
}
