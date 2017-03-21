#include <stdio.h>
#include <string.h>
#include "../include/io.h"
#include "../include/array.h"

int main (int argc, char *argv[]) {
  char key[2];
  char order[11];
  Array *array;

  init_array(&array);

  if (argc > 1) {
    strcpy(key, argv[1]);
    if (key[1] == 'r') {
      strcpy(order, "decrescente");
    } else {
      strcpy(order, "crescente");
    }
  } else {
    strcpy(order, "crescente");
  }

  while(inputValue(&array));
  array->sort(&array, key[1]);
  printOutput(array, order);

  return 0;
}
