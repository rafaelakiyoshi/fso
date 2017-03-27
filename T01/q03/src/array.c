#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/array.h"


int init_array(Array **self) {
  *self = (Array*) malloc(sizeof(Array));
  (*self)->length = 0;
  (*self)->__array__ = NULL;

  (*self)->get = array_get;
  (*self)->push = array_push;
  (*self)->sort = array_sort;
  (*self)->print = array_print;
  return 1;
}

int array_get(Array *self, int pos) {
  if (pos < self->length) {
    return self->__array__[pos];
  } else {
    return -1;
  }
}

//Metodo de inserção de valores no vetor
int array_push(Array **self, int value) {
  if (value >= 0) {
    (*self)->__array__ = realloc((*self)->__array__, sizeof(int) * ((*self)->length + 1));
    (*self)->__array__[(*self)->length] = value;
    (*self)->length += 1;
    return 1;
  } else {
    return 0;
  }
}

//Metodo de ordenação selection sort a partir de chave -r ou -d
int array_sort(Array **self, char key) {
  int index_min;
  int aux;

  for (int i = 0; i < (*self)->length; i++) {
    index_min = i;
    for (int j = i + 1; j < (*self)->length; j++) {
      if ( array_sortCondition(key, (*self)->__array__[j], (*self)->__array__ [index_min])) {
        index_min = j;
      }
    }
    if (index_min != i) {
      aux = (*self)->__array__[index_min];
      (*self)->__array__[index_min] = (*self)->__array__[i];
      (*self)->__array__[i] = aux;
    }
  }

  return 1;
}

//Condição de ordenação crescente ou decrescente a partir de chave -r ou -d
int array_sortCondition(char key, int valueA, int valueB) {
  if (key == 'r') {
    //Decrescente
    return valueA > valueB;
  } else {
    //Crescente
    return valueA < valueB;
  }
}

int array_print(Array *self) {
  for (int i = 0; i < self->length; i++) {
    printf("%d ", self->get(self, i));
  }
  printf("\n");
}
