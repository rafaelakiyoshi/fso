#include <math.h>

#include "polygon.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H

double distanceBetweenDots(Dot* one, Dot* two);
int isConvex(Quadrilateral* quadrilateral);
double perimeter(Quadrilateral* quadrilateral);
double area(Quadrilateral* quadrilateral);

#endif
