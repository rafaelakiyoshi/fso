#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <math.h>

int main (int argc, char *argv[]) {
  double rad = 0;
  void *module;
  double (*lib_func)(double);
  char *error;
  char func = 's';

  if (argc < 3) {
    exit(1);
  }
  func = argv[1][1];
  rad = strtod(argv[2], NULL);

  module = dlopen ("./lib/libseno.so", RTLD_LAZY);
  if (!module) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  if(func == 's') {
    lib_func = dlsym (module, "seno");
  }
  else if (func == 'a') {
    lib_func = dlsym (module, "arc_seno");
    printf("arc_");
  }
  else {
    exit(1);
  }
  if ((error = dlerror()) != NULL)  {
    fputs(error, stderr);
    exit(1);
  }

  printf("seno (%.2lf) = %.2lf\n", floor(rad*100.0f) / 100.0f , floor((*lib_func)(rad) * 100.0f) / 100.0f);
  dlclose(module);
  return 0;
}
