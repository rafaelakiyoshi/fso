#include <stdio.h>

#include "../include/polygon.h"
#include "../include/io.h"
#include "../include/operations.h"

int main(int argc, char *argv[]) {
  Quadrilateral *quad;
  init_quadrilateral(&quad);
  insertDots(&quad);
  int convex = isConvex();
  if(convex == 1){
    printf("Quadrilatero convexo.\n");
    area(quad);
  } else {
    printf("Quadrilatero nao convexo.\n");
  }

  return 0;
}
