#include <math.h>
#include <stdio.h>

#include "../include/operations.h"
#include "../include/polygon.h"

double determinant(Dot dot1, Dot dot2, Dot dot3) {
  /*
  | x1 y1 1 x1 y1 |
  | x2 y2 1 x2 y2 |
  | x3 y3 1 x3 y3 |
  */
  double x1 = dot1.x;
  double y1 = dot1.y;
  double x2 = dot2.x;
  double y2 = dot2.y;
  double x3 = dot3.x;
  double y3 = dot3.y;
  double determinantRigth = ((x1 * y2 * 1) + (y1 * 1 * x3) + (1 * x2 * y3));
  double determinantLeft = ((y1 * x2 * 1) + (x1 * 1 * y3) + (1 * y2 * x3));
  double determinant = determinantRigth - determinantLeft;
  return determinant;
}

int isConvex() {
  return 1;
}

double perimeter(Quadrilateral* quadrilateral) {

}

double area(Quadrilateral* quad) {
  Dot d1 = quad->dots[0];
  Dot d2 = quad->dots[1];
  Dot d3 = quad->dots[2];
  Dot d4 = quad->dots[3];
  double D1 = determinant(d1, d2, d3);
  double D2 = determinant(d1, d2, d4);
  if(D1<0) D1 = D1*-1;
  if(D2<0) D2 = D2*-1;
  double qArea = (D1 + D2*(1/2));
  printf("Area: %.0lf \n", qArea);

}
