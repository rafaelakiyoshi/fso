#include <stdio.h>

#include "../include/polygon.h"
#include "../include/io.h"

int main(int argc, char *argv[]) {
  Quadrilateral *quad;
  double vectors[4][2];
  double z[4];
  init_quadrilateral(&quad);
  insertDots(&quad);

  return 0;
}
