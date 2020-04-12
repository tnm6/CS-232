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

    fprintf(stderr, "BAKER: No time like the present to bake that bread.\n");
    usleep(WAIT_TIME);
    sem_post(&loaves);
    fprintf(stderr, "BAKER: Some more scrumptious bread has been baked.\n");

    sem_post(&busy);
    usleep(WAIT_TIME);
  }

  fprintf(stderr, "BAKER: Bread has been thoroughly baked.\n");
}

void* checkout(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&payment);
    sem_wait(&busy);

    fprintf(stderr,
            "BAKER: Processing payment. Washing hands.\n");
    usleep(WAIT_TIME);

    sem_post(&receipt);
    fprintf(stderr, "BAKER: Receipt given, hopefully uncontaminated.\n");
    usleep(WAIT_TIME);

    sem_post(&busy);
  }
}

void* enter(void* id) {
  unsigned long myID = (unsigned long) id;

  sem_wait(&cust_queue);
  fprintf(stderr, 
          "CUSTOMER %lu: I begin my bread journey. Mask on. Entering store.\n",
          myID);

  sem_wait(&loaves);
  fprintf(stderr, "CUSTOMER %lu: I got that fresh, delicious loaf.\n", myID);
  
  usleep(WAIT_TIME);

  sem_post(&payment);
  fprintf(stderr, "CUSTOMER %lu: I gave some bread to get bread.\n", myID);

  sem_wait(&receipt);
  fprintf(stderr, "CUSTOMER %lu: I got my receipt.\n", myID);

  sem_post(&cust_queue);
  fprintf(stderr,
          "CUSTOMER %lu: I've fulfilled my bread journey. Back to isolation.\n",
          myID);
}

int main(int argc, char** argv) {
  unsigned long i;
  pthread_t b_bake, b_checkout;     // Baker threads
  pthread_t customers[N_CUSTOMERS]; // Customer threads

  fprintf(stderr, "Bakery starting up. Why don't we do curbside delivery?\n");

  // create the necessary semaphores
  sem_init(&cust_queue, 0, MAX_CUST_QUEUE);
  sem_init(&loaves, 0, 0);
  sem_init(&busy, 0, 1);
  sem_init(&payment, 0, 0);
  sem_init(&receipt, 0, 0);

  // create necessary threads
  pthread_create(&b_bake, NULL, bake, NULL);
  pthread_create(&b_checkout, NULL, checkout, NULL);
  for (i = 0; i < N_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, enter, (void*) i+1);
  }

  pthread_exit(NULL);
}