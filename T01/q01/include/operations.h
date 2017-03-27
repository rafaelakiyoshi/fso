#include <math.h>

#include "polygon.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H

double determinant(Dot dot1, Dot dot2, Dot dot3);
int isConvex(Quadrilateral * quad);
double area(Quadrilateral* quadrilateral);

#endif
