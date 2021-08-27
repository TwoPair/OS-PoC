// gcc semaphore.c -o semaphore -pthread

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/* If TASK_NUM is 1, this code will be a binary semaphore. It's same as mutex.
 * Or, if TASK_NUM is largger than 1, the code is a counting semaphore.
 * The important meaning of semaphore is that it can takes more than two threads
 * whereas mutex cannot do that.
 */
#define TASK_NUM 5

int sum = 0; // a shared variable

sem_t sem;

void *counter(void *);

int main() {
  pthread_t tid[5];
  sem_init(&sem, 0, TASK_NUM);
  for (int i = 0; i < 5; i++)
    pthread_create(&tid[i], NULL, counter, NULL);
  for (int i = 0; i < 5; i++)
    pthread_join(tid[i], NULL);
  printf("sum = %d\n", sum);
}

void *counter(void *param) {
  for (int k = 0; k < 10000; k++) {
    /* entry section */
    sem_wait(&sem);

    /* critical section */
    sum++;

    /* exit section */
    sem_post(&sem);

    /* remainder section */
  }
  pthread_exit(0);
}