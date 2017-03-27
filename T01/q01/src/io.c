#include <stdio.h>

#include "../include/io.h"
#include "../include/polygon.h"

int insertDots(Quadrilateral **self) {
  double x_val, y_val;
  int i;

  for (i = 0; i < (*self)->maxDots; i++) {
    scanf("%lf%lf", &x_val, &y_val);
    (*self)->push(self, newDot(x_val, y_val));
  }
}

void convexOutput(int isConvex) {
  printf("Quadrilatero %sconvexo.\n", (isConvex ? "" : "não "));
}

void areaOutput(double area) {
  printf("Area: %.0lf.\n", area);
}
