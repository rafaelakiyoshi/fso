#include <stdio.h>
#include <stdlib.h>

#include "../include/polygon.h"
#include "../include/io.h"
#include "../include/operations.h"

int main(int argc, char *argv[]) {
  Quadrilateral *quad;
  int convex = 0;

  init_quadrilateral(&quad);
  if(insertDots(&quad)) {
    exit(1);
  }
  convex = isConvex(quad);
  convexOutput(convex);
  if(convex == 1) {
    areaOutput(area(quad));
  }


  return 0;
}
