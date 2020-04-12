#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_CUST_QUEUE 5
#define MAX_LOAVES 10
#define N_CUSTOMERS 10
#define WAIT_TIME 1000000

sem_t cust_queue;
sem_t loaves;
sem_t busy;
sem_t payment;
sem_t receipt;

void* bake(void* arg) {
  for (int i = 0; i < MAX_LOAVES; i++) {
    sem_wait(&busy);

    sem_post(&loaves);
    fprintf(stderr, "Some more sweet bread for sale.\n");

    sem_post(&busy);
  }
}

void* checkout(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&payment);
    sem_wait(&busy);

    sem_post(&receipt);
    fprintf(stderr, "Bread for that bread received. Receipt given.\n");

    sem_post(&busy);
  }
}

void* enter(void* id) {
  sem_wait(&cust_queue);
  fprintf(stderr, "Customer %d has begun his bread journey.\n", id);

  sem_wait(&loaves);

  fprintf(stderr, "Customer %d has that fresh, delicious loaf.", id);
  usleep(WAIT_TIME);

  sem_post(&payment);
  fprintf(stderr, "Customer %d gave some bread to get bread.\n", id);

  sem_wait(&receipt);
  fprintf(stderr, "Customer %d got his receipt.\n", id);

  sem_post(&cust_queue);
  fprintf(stderr,
          "Customer %d has fulfilled his bread journey and left the store.\n",
          id);
}

int main(int argc, char** argv) {
  pthread_t b_bake, b_checkout;
  pthread_t customers[N_CUSTOMERS];

  fprintf(stderr, "Bakery starting up...\n");

  // create the necessary semaphores
  sem_init(&cust_queue, 0, MAX_CUST_QUEUE);
  sem_init(&loaves, 0, 0);
  sem_init(&busy, 0, 1);
  sem_init(&payment, 0, 0);
  sem_init(&receipt, 0, 0);

  // create necessary threads
  pthread_create(&b_bake, NULL, bake, NULL);
  pthread_create(&b_checkout, NULL, checkout, NULL);
  
  for (int i = 0; i < N_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, enter, i+1);
  }

  pthread_exit(NULL);
  return 0;
}