#include <stdio.h>

int main (int argc, char *argv[]) {
  printf("# de parametros: %d\n", argc - 1);
  printf("Nome do executavel: %s\n", argv[0]);
  for (int counter = 1; counter < argc; counter++) {
    printf("Parametro #%d: %s\n", counter, argv[counter]);
  }
}
