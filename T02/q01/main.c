#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>

#define MAX_TIME 30
#define BUFFER 256

int child_process(char*);
int fork_children(int);
double time_diff(struct timeval, struct timeval);

int main (int argc, char *argv[]) {
  struct timeval timeout, time_start, time_end, lazy_end, active_end;
  double timestamp, lazy_timestamp;
  pid_t lazy_pid, active_pid;
  int lazy_fd[2], active_fd[2], ret, random;
  char lazy_msg[BUFFER], active_msg[BUFFER],input[BUFFER];
  char buffer[BUFFER];
  fd_set set;
  int lazy_msg_num = 1;
  srand(time(NULL));

  timeout.tv_sec = 5;
  timeout.tv_usec = 0;
  gettimeofday(&time_start, NULL);
  // Comando para pegar tempo a partir do clock, há outras possibilidades
  // ------
  // time_start = clock();
  //
  // while(timestamp < 30) {
  //   time_end = clock();
  // 	timestamp = (double) (time_end-time_start)/CLOCKS_PER_SEC;
  // }
  // printf("0:%2.3f\n", timestamp);

  // fork_children(1);

  // Criando pipe para conversa com filho preguicoso
  if(pipe(lazy_fd) == -1) {
    printf("Pipe failed\n");
    exit(1);
  }

  // forkando filho preguicoso
  lazy_pid = fork();
  if (lazy_pid < 0) {
    exit(1);
  } else if (lazy_pid == 0) { // processo filho preguicoso
    close(lazy_fd[0]);

    do {
      sleep(rand()%3);

      gettimeofday(&lazy_end, NULL);
    	lazy_timestamp = time_diff(lazy_end, time_start);

      sprintf(lazy_msg, "0:%02.3lf: Mensagem %02d do filho dorminhoco", lazy_timestamp, lazy_msg_num);
      write(lazy_fd[1], lazy_msg, sizeof(lazy_msg));
      lazy_msg_num++;
    }while(lazy_timestamp < 30);
  // fim filho preguicoso
  } else { // processo pai
    close(lazy_fd[1]);

    if(pipe(active_fd) == -1) {
      printf("Pipe failed\n");
      exit(1);
    }

    // forkando filho ativo
    active_pid = fork();
    if (active_pid < 0) {
      exit(1);
    } else if (active_pid == 0) { // processo filho ativo
      close(active_fd[0]);
      double active_timestamp;

      while(scanf("%s", input) && active_timestamp < 30) {
        gettimeofday(&active_end, 0);
      	active_timestamp = time_diff(active_end, time_start);
        printf("active_timestamp: %lf\n", active_timestamp);
        sprintf(active_msg, "0:%lf: Mensagem %02d do usuario: <%s>\n", active_timestamp, lazy_msg_num, input);
        write(active_fd[1], active_msg, sizeof(active_msg));
        lazy_msg_num++;
      }
    } else { //processo pai
      close(active_fd[1]);

      do {
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        FD_ZERO(&set);
        FD_SET(lazy_fd[0], &set);
        FD_SET(active_fd[0], &set);
        ret = select(active_fd[0] + 1, &set, NULL, NULL, &timeout);
        if (ret > 0) {
          gettimeofday(&time_end, NULL);
          timestamp = time_diff(time_end, time_start);
          if (FD_ISSET(lazy_fd[0], &set)) {
            if(read(lazy_fd[0], buffer, sizeof(buffer))) {
              printf("0:%02.3lf: %s\n", timestamp, buffer);
            }
          }
          if (FD_ISSET(active_fd[0], &set)) {
            if(read(active_fd[0], buffer, sizeof(buffer))) {
              printf("0:%02.3lf: %s\n", timestamp, buffer);
            }
          }
        }
      } while (ret != 0 && timestamp < 30);
      wait(NULL);
    }
  }

  return 0;
}

double time_diff(struct timeval t1, struct timeval t0)
{
    return (double)(t1.tv_sec - t0.tv_sec) + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
