// gcc mutex_lock.c -o mutex_lock -pthread
//
//     [ Mutex Lock ]
// One of Higher-Level software tools
// It's focusing on solving the mutex exclusion.

#include <pthread.h>
#include <stdio.h>

int sum = 0;  // a shared variable

pthread_mutex_t mutex;

void *counter(void *);

int main() {
  pthread_t tid1, tid2;
  pthread_mutex_init(&mutex, NULL);
  pthread_create(&tid1, NULL, counter, NULL);
  pthread_create(&tid2, NULL, counter, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("sum = %d\n", sum);
}

void *counter(void *param) {
  for (int k = 0; k < 10000; k++) {
    /* entry section */
    pthread_mutex_lock(&mutex);  // atomical function

    /* critical section */
    sum++;

    /* exit section */
    pthread_mutex_unlock(&mutex);  // atomical function

    /* remainder section */
  }
  pthread_exit(0);
}