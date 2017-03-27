#include <stddef.h>
#include <stdlib.h>

#include "../include/polygon.h"

int init_quadrilateral(Quadrilateral **self) {
  *self = (Quadrilateral*) malloc(sizeof(Quadrilateral));
  (*self)->numOfDots = 0;
  (*self)->maxDots = 4;
  (*self)->dots = NULL;

  (*self)->push = quadrilateral_push;
  
  return 1;
}

int quadrilateral_push(Quadrilateral **self, Dot *dot) {
  if (dot != NULL) {
    (*self)->dots = realloc((*self)->dots, sizeof(Dot) * ((*self)->numOfDots + 1));
    (*self)->dots[(*self)->numOfDots] = *dot;
    (*self)->numOfDots += 1;

    return 1;
  } else {
    return 0;
  }
}

Dot *newDot(double x, double y) {
  Dot *tmp = (Dot*) malloc(sizeof(Dot));
  tmp->x = x;
  tmp->y = y;

  return tmp;
}
