#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "types.h"
#include <math.h>

double distanceBetweenDots(Dot* one, Dot* two); 
bool isConvex(Quadrilateral* quadrilateral);
double perimeter(Quadrilateral* quadrilateral);
double area(Quadrilateral* quadrilateral);
#endif
