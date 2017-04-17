#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_TIME 30

int child_process(char*);

int main (int argc, char *argv[]) {
  clock_t time_start, time_end;
  double timestamp;
  pid_t pid[2];
  srand(time(NULL));
  int child_type = 0;

  // Comando para pegar tempo a partir do clock, há outras possibilidades
  // ------
  // time_start = clock();
  //
  // while(timestamp < 30) {
  //   time_end = clock();
  // 	timestamp = (double) (time_end-time_start)/CLOCKS_PER_SEC;
  // }
  // printf("0:%2.3f\n", timestamp);

  pid[0] = fork_child(&child_type);

  return 0;
}

int child_process(char *child_type) {
  fprintf(stdout, "%s\n", child_type);
}
