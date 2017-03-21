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

//Metodo de chamada de ordenação a partir da chave -r ou -d
int array_sort(Array **self, char key) {
  if (key == 'r') {
    array_sortDecrescent((*self)->__array__, (*self)->length);
  } else {
    array_sortCrescent((*self)->__array__, (*self)->length);
  }

  return 1;
}

//Ordenação crescente do Array.__array__
int array_sortCrescent(int *array, int size) {
  //bubble sort -- alterar depois pq ta feio
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if ( array[j] > array [j+1]) {
        int tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }

  return 1;
}

//Ordenação decrescente do Array.__array__
int array_sortDecrescent(int *array, int size) {
  //bubble sort -- alterar depois pq ta feio
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if ( array[j] < array [j+1]) {
        int tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
    }
  }

  return 1;
}

int array_print(Array *self) {
  for (int i = 0; i < self->length; i++) {
    printf("%d ", self->get(self, i));
  }
  printf("\n");
}
