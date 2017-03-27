#include <math.h>

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

int isConvex(Quadrilateral * quad) {
  int sign = 0, i;
  for (i = 0; i < 4; i++ ) {
     double dx1 = quad->dots[(i+1) % 4].x - quad->dots[ i%4 ].x;
     double dy1 = quad->dots[(i+1) % 4].y - quad->dots[ i%4 ].y;
     double dx2 = quad->dots[(i+2) % 4].x - quad->dots[ (i+1)% 4].x;
     double dy2 = quad->dots[(i+2) % 4].y - quad->dots[ (i+1)% 4].y;
     double z = dx1*dy2 - dy1*dx2;

     if ( i == 0 )
        sign = z > 0;
     else if ( sign != ( z > 0 ))
        return 0;
  }
  return 1;
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
}
