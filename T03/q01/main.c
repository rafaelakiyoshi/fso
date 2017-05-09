#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <pthread.h>
#include <signal.h>
#include <limits.h>
#include <string.h>

#define NUM_THREADS 3
#define MAX_BUFFER 50

typedef struct _data {
  int buffer[MAX_BUFFER];
  int max_num;
  int min_num;
  int counter_prod;
  int counter_cons;
}Data;

Data data;
char output_file[256];

void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */
void signalHandler(int);
void write_output(char *, char *);

pthread_t threads[NUM_THREADS];   //Thread array
pthread_mutex_t mutexdata;
pthread_cond_t cond_cons;

int main(int argc, char *argv[]) {
  pthread_attr_t attr; //Set of thread attributes
  struct sigaction act; // Action for signal
  long i;
  void *status;
  FILE * file;
  char output_msg[256];
  /* init data */
  data.counter_prod = 0;
  data.counter_cons = 0;
  data.max_num = INT_MIN;
  data.min_num = INT_MAX;

  if (argc > 1) {
    strcpy(output_file, argv[1]);
  } else {
    strcpy(output_file, "output");
  }

  /* rewrites file */
  file = fopen(output_file, "w");
  fclose(file);


  srand(time(NULL));
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_mutex_init(&mutexdata, NULL);
  pthread_cond_init(&cond_cons, NULL);

  act.sa_handler = signalHandler;
  sigaction(SIGINT, &act, NULL);



  /* Create the producer threads */
    pthread_create(&threads[0], &attr, producer, NULL);
  /* Create the consumer threads */
  for(i = 0; i < 2; i++) {
    /* Create the thread */
    pthread_create(&threads[i+1], &attr, consumer, (void *)i);
  }

  for(i = 0; i < NUM_THREADS; i++) {
    /* Waiting for threads*/
    pthread_join(threads[i], &status);
  }

  /* Controller output */
  sprintf(output_msg, "[aviso]: Maior numero gerado: %d\n[aviso]: Menor numero gerado: %d\n[aviso]: Maior ocupacao de buffer: %d\n[aviso]: Aplicacao encerrada.\n", data.max_num, data.min_num, data.counter_prod);
  printf("%s", output_msg);
  write_output(output_file, output_msg);
  /* Free thread attribute */
  pthread_attr_destroy(&attr);
  /* clean mutex */
  pthread_mutex_destroy(&mutexdata);

  /* Exit the program */
  return 0;
}

void signalHandler(int dummy) {
  int i;
  char output_msg[256];
  sprintf(output_msg, "[aviso]: Termino solicitado. Aguardando threads...\n");
  printf("%s", output_msg);
  write_output(output_file, output_msg);
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_cancel(threads[i]);
  }
}

/* Producer Thread */
void *producer(void *param) {
  int random_number;
  char output_msg[256];
  while(1) {
    random_number = (rand() % (INT_MAX/2 - INT_MIN/2) + INT_MIN/2) + (rand() % (INT_MAX/2 - INT_MIN/2) + INT_MIN/2);
    sprintf(output_msg, "[producao]: Numero gerado: %d\n", random_number);
    printf("%s", output_msg);
    write_output(output_file, output_msg);
    data.buffer[data.counter_prod % MAX_BUFFER] = random_number;
    data.counter_prod += 1;

    if (random_number > data.max_num) {
      data.max_num = random_number;
    }
    if (random_number < data.min_num) {
      data.min_num = random_number;
    }
    pthread_cond_signal(&cond_cons);
    usleep(100000);
  }
  pthread_exit(NULL);
}

/* Consumer Thread */
void *consumer(void *arg) {
  int t_id = 'a' + ((long)arg);
  char output_msg[265];
  while(1) {
    pthread_mutex_lock(&mutexdata);
    pthread_cond_wait(&cond_cons, &mutexdata);
    sprintf(output_msg, "[consumo %c]: Numero lido: %d\n", t_id, data.buffer[data.counter_cons % MAX_BUFFER]);
    printf("%s", output_msg);
    write_output(output_file, output_msg);
    data.counter_cons += 1;
    pthread_mutex_unlock(&mutexdata);
    usleep(150000);
  }
  pthread_exit(NULL);
}

void write_output(char *output_file, char *output_msg) {
  FILE * file = fopen(output_file, "a");
  fprintf(file, "%s", output_msg);
  fclose(file);
}
