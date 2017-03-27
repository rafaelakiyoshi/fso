#include <stdio.h>

#include "../include/io.h"
#include "../include/polygon.h"

int insertDots(Quadrilateral **self) {
  double x_val, y_val;
  int i, scanf_value = 0;

  for (i = 0; i < (*self)->maxDots; i++) {
    scanf_value = scanf("%lf%lf", &x_val, &y_val);
    if (scanf_value < 2) {
      printf("Dado informado NaN. Abortando..\n");
      return 1;
    }
    (*self)->push(self, newDot(x_val, y_val));
  }
  return 0;
}

void convexOutput(int isConvex) {
  printf("Quadrilatero %sconvexo.\n", (isConvex ? "" : "não "));
}

void areaOutput(double area) {
  printf("Area: %.0lf.\n", area);
}
