#include <stdio.h>
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

int main() {
  intlist* l = cons(1, cons(4, cons(5, cons(6, NULL))));
  intlist* l2 = rev(l);
  print_list(l2);
  print_list(l);
}
