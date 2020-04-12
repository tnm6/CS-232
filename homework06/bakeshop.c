#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_CUST_QUEUE 5
#define N_CUSTOMERS 10
#define WAIT_TIME 1000000

sem_t cust_queue;
sem_t loaves;
sem_t busy;
sem_t payment;
sem_t receipt;

void* bake(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&busy);

    fprintf(stderr, "No time like the present to bake that bread.\n");
    usleep(WAIT_TIME);
    sem_post(&loaves);
    fprintf(stderr, "Some more scrumptious bread has been baked.\n");

    sem_post(&busy);
    usleep(WAIT_TIME);
  }

  fprintf(stderr, "Baker has finished baking that dough.\n");
}

void* checkout(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&payment);
    sem_wait(&busy);

    fprintf(stderr,
            "Time is money, but money takes time: processing payment.\n");
    usleep(WAIT_TIME);

    sem_post(&receipt);
    fprintf(stderr, "Bread for that bread received. Receipt given.\n");

    sem_post(&busy);
  }
}

void* enter(void* id) {
  unsigned long myID = (unsigned long) id;
  sem_wait(&cust_queue);
  fprintf(stderr, "Customer %lu has begun his bread journey.\n", myID);

  sem_wait(&loaves);

  fprintf(stderr, "Customer %lu has that fresh, delicious loaf.\n", myID);
  usleep(WAIT_TIME);

  sem_post(&payment);
  fprintf(stderr, "Customer %lu gave some bread to get bread.\n", myID);

  sem_wait(&receipt);
  fprintf(stderr, "Customer %lu got his receipt.\n", myID);

  sem_post(&cust_queue);
  fprintf(stderr,
          "Customer %lu has fulfilled his bread journey and left the store.\n",
          myID);
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
  
  for (unsigned long i = 0; i < N_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, enter, (void*) i+1);
  }

  pthread_exit(NULL);
  return 0;
}