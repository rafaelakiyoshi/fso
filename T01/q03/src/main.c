#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/io.h"
#include "../include/array.h"

int main (int argc, char *argv[]) {
  char *key = NULL;
  Array *array;

  init_array(&array);

  if (argc > 1) {
    for (int i = 1; i < argc; i ++) {
      if (strcmp(argv[i], "-r")|| strcmp(argv[i], "-d")) {
        key = argv[i];
      }
    }
  }
  if (key == NULL) {
    key = (char*) malloc(sizeof(char) * 2);
    strcpy(key, "-d");
  }

  while(inputValue(&array));
  array->sort(&array, key[1]);
  printOutput(array, key);

  return 0;
}
