
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_t tid;       //Thread ID
pthread_attr_t attr; //Set of thread attributes

void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */

/* Producer Thread */
void *producer(void *param) {

   while(1) {
      printf("produtor\n");
      sleep(2);
   }
   return NULL;
}

/* Consumer Thread */
void *consumer(void *param) {

   while(1) {
      printf("consumidor\n");
      sleep(2);
   }
   return NULL;
}

int main(int argc, char *argv[]) {
   int i;
   

   /* Create the producer threads */
      pthread_create(&tid,&attr,producer,NULL);

   /* Create the consumer threads */
   for(i = 0; i < 2; i++) {
      /* Create the thread */
      pthread_create(&tid,&attr,consumer,NULL);
   }

   /* Sleep for the specified amount of time in milliseconds */
   sleep(20000);

   /* Exit the program */
   printf("Exit the program\n");
   exit(0);
}
