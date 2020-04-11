#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int MAX_QUEUE_DEPTH = 5;

sem_t cust_queue;

int main(int argc, char** argv) {

  sem_init(&cust_queue, 0, MAX_QUEUE_DEPTH);
  printf("Bakery starting up...\n");

  return 0;
}