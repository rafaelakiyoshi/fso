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
  struct timeval timeout, time_start, time_end;
  double timestamp;
  pid_t lazy_pid, active_pid;
  int lazy_fd[2], active_fd[2], ret, random;
  char child_msg[BUFFER],input[BUFFER];
  char buffer[BUFFER];
  fd_set set;
  int child_msg_num = 1;
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

      gettimeofday(&time_end, NULL);
    	timestamp = time_diff(time_end, time_start);

      sprintf(child_msg, "0:%02d.%03d: Mensagem %02d do filho dorminhoco", (int)timestamp, (int)((timestamp - (int)timestamp)*1000), child_msg_num);
      write(lazy_fd[1], child_msg, sizeof(child_msg));
      child_msg_num++;
    }while(timestamp < 30);
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
      do {

        // descomente o sleep e o strcpy e comente o fscanf para ver como funciona direitinho, é o scanf que ta zuado
        // sleep(9);
        // strcpy(input, "POOOORRA")
        fscanf(stdin, "%s", input);
        gettimeofday(&time_end, NULL);
        timestamp = (double)(time_end.tv_sec - time_start.tv_sec) + ((double)time_end.tv_usec - (double)time_start.tv_usec)/1000000.0f;

        sprintf(child_msg, "0:%02d.%03d: Mensagem %02d do usuario <%s>", (int)timestamp, (int)((timestamp - (int)timestamp)*1000), child_msg_num, input);
        write(active_fd[1], child_msg, sizeof(child_msg));
        child_msg_num++;
      }while(timestamp < 30);
    } else { //processo pai
      close(active_fd[1]);

      do {
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        FD_ZERO(&set);
        FD_SET(lazy_fd[0], &set);
        FD_SET(active_fd[0], &set);
        ret = select(FD_SETSIZE, &set, NULL, NULL, &timeout);

        if (ret > 0) {
          if (FD_ISSET(lazy_fd[0], &set)) {
            if(read(lazy_fd[0], buffer, sizeof(buffer))) {
              gettimeofday(&time_end, NULL);
              timestamp = time_diff(time_end, time_start);
              printf("0:%02d.%03d: %s\n", (int)timestamp, (int)((timestamp - (int)timestamp)*1000), buffer);
            }
          }
          if (FD_ISSET(active_fd[0], &set)) {
            if(read(active_fd[0], buffer, sizeof(buffer))) {
              gettimeofday(&time_end, NULL);
              timestamp = (double)(time_end.tv_sec - time_start.tv_sec) + ((double)time_end.tv_usec - (double)time_start.tv_usec)/1000000.0f;
              printf("0:%02d.%03d: %s\n", (int)timestamp, (int)((timestamp - (int)timestamp)*1000), buffer);
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
