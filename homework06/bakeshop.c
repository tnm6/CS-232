/**
 * homework06
 * Busy Bake Shop exercise using pthreads and semaphores
 * 
 * CS-232, Calvin University, Professor Victor Norman
 * @author  Nathan Meyer
 * @date    4/11/2020
 */

#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_CUST_QUEUE 5  // only 5 customers in store at a time
#define N_CUSTOMERS 10
#define WAIT_TIME 1000000

sem_t cust_queue; // how many customers are in the store
sem_t bread;      // how many bread loaves are ready
sem_t b_busy;     // if the baker is busy or not
sem_t c_busy;     // if checkout is busy w/customer or not
sem_t payment;    // if payment is ready or not
sem_t receipt;    // if receipt is ready or not

void* bake(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&b_busy);

    fprintf(stderr, "BAKER: No time like the present to bake that bread.\n");
    usleep(WAIT_TIME);
    sem_post(&bread);
    fprintf(stderr, "BAKER: Some more scrumptious bread has been baked.\n");

    sem_post(&b_busy);
    usleep(WAIT_TIME);
  }

  fprintf(stderr, "BAKER: Bread has been thoroughly baked.\n");
}

void* checkout(void* arg) {
  for (int i = 0; i < N_CUSTOMERS; i++) {
    sem_wait(&payment); // only continue if payment is ready
    sem_wait(&b_busy);

    fprintf(stderr,
            "BAKER: Processing payment. Washing hands.\n");
    usleep(WAIT_TIME);

    sem_post(&receipt);
    fprintf(stderr, "BAKER: Receipt given, hopefully uncontaminated.\n");

    sem_post(&b_busy);
    usleep(WAIT_TIME);
  }
}

void* enter(void* id) {
  unsigned long myID = (unsigned long) id;

  sem_wait(&cust_queue);
  fprintf(stderr, 
          "CUSTOMER %lu: I begin my bread journey. Mask on. Entering store.\n",
          myID);

  sem_wait(&bread);
  fprintf(stderr, "CUSTOMER %lu: I got that fresh, delicious loaf.\n", myID);
  
  usleep(WAIT_TIME);

  sem_wait(&c_busy);
  sem_post(&payment);
  fprintf(stderr, "CUSTOMER %lu: I gave some bread to get bread.\n", myID);

  sem_wait(&receipt);
  fprintf(stderr, "CUSTOMER %lu: I got my receipt.\n", myID);
  sem_post(&c_busy);

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
  sem_init(&cust_queue, 0, MAX_CUST_QUEUE); // only 5 customers at a time
  sem_init(&b_busy, 0, 1);    // unlocked (not busy) at start
  sem_init(&c_busy, 0, 1);
  sem_init(&bread, 0, 0);
  sem_init(&payment, 0, 0);
  sem_init(&receipt, 0, 0);

  // create and execute threads
  pthread_create(&b_bake, NULL, bake, NULL);
  pthread_create(&b_checkout, NULL, checkout, NULL);
  for (i = 0; i < N_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, enter, (void*) i+1);
  }

  // only exit when all threads are done
  pthread_exit(NULL);
}