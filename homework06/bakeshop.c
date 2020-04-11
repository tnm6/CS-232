#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_CUST_QUEUE 5
#define MAX_LOAVES 10
#define N_CUSTOMERS 10

sem_t cust_queue;
sem_t loaves;
sem_t busy;

void* bake(void* arg) {
  sem_wait(&busy);

  printf()

  sem_post(&busy);
}

void* checkout(void* arg) {
  
}

void* enter(void* arg) {
  sem_wait(&cust_queue);

  printf("Customer ")
}

int main(int argc, char** argv) {
  pthread_t b_bake, b_checkout;
  pthread_t customers[N_CUSTOMERS];

  printf("Bakery starting up...\n");

  // create the necessary semaphores
  sem_init(&cust_queue, 0, MAX_CUST_QUEUE);
  sem_init(&loaves, 0, MAX_LOAVES);
  sem_init(&busy, 0, 1);

  // create necessary threads
  pthread_create(&b_bake, NULL, bake, NULL);
  pthread_create(&b_checkout, NULL, checkout, NULL);
  
  for (int i = 0; i < N_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, enter, NULL);
  }

  pthread_exit(NULL);
  return 0;
}