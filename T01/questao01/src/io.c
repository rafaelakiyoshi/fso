#include <stdio.h>

#include "../include/io.h"
#include "../include/polygon.h"

int insertDots(Quadrilateral **self) {
  double x_val, y_val;

  for (int i = 0; i < (*self)->maxDots; i++) {
    scanf("%lf%lf", &x_val, &y_val);
    (*self)->push(self, newDot(x_val, y_val));
  }
}
