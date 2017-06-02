#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/libseno.h"

int main (int argc, char *argv[]) {
  char func = 's';
  double rad = 0;
  if (argc < 3) {
    exit(1);
  }
  func = argv[1][1];
  rad = strtod(argv[2], NULL);

  if(func == 's') {
    printf("seno (%.2lf) = %.2lf\n", floor(rad*100.0f) / 100.0f , floor(seno(rad) * 100.0f) / 100.0f);
  }
  else if (func == 'a') {
    printf("arc_seno (%.2lf) = %.2lf\n", floor(rad*100.0f) / 100.0f , floor(arc_seno(rad) * 100.0f) / 100.0f);
  }

  return 0;
}
