#include <stdio.h>

#include "../include/io.h"
#include "../include/array.h"

int printOutput(Array *array, char *order) {
  printf("Saida %s:\n", order);
  array->print(array);
}

int inputValue(Array **array) {
  int value = 0;
  scanf("%d", &value);
  return (*array)->push(array, value);
}
