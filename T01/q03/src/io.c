#include <stdio.h>
#include <stdio_ext.h>

#include "../include/io.h"
#include "../include/array.h"

int printOutput(Array *array, char *key) {
  printf("Saida %screscente:\n", (key[1] == 'r' ? "de": ""));
  arrayPrint(array);
}

int inputValue(Array **array) {
  int value = 0;
  int scanf_value = 0;
  if(scanf("%d", &value) < 1) {
    fflush(stdin);
    __fpurge(stdin);
    return 1;
  }
  if (value >= -1) {
    return (*array)->push(array, value);
  } else {
    return 1;
  }
}

int arrayPrint(Array *self) {
  int i;
  for (i = 0; i < self->length; i++) {
    printf("%d ", self->get(self, i));
  }
  printf("\n");
}
