#include <stdio.h>
#include <stdlib.h>
#include "../include/libseno.h"

int main (int argc, char *argv[]) {

  if (argc < 3) {
    exit(1);
  }
  char func = argv[1][1];
  double rad = strtod(argv[2], NULL);

  if(func == 's') {
    printf("seno (%.2lf) = %.3lf\n", ((int)(rad * 100)/100.0) , ((int)(seno(rad) * 1000)) / 1000.0);
  }
  else if (func == 'a') {
    printf("arc_seno (%.2lf) = %.2lf\n", ((int)(rad * 100)/100.0), arc_seno(rad));
  }

  return 0;
}
