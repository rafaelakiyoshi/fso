#include <stdio.h>

#include "../include/polygon.h"
#include "../include/io.h"

int main(int argc, char *argv[]) {
  Quadrilateral *quad;

  init_quadrilateral(&quad);

  insertDots(&quad);

  return 0;
}
