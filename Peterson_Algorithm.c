<<<<<<< HEAD
// gcc .\Peterson_Algorithm.c -o .\Peterson_Algorithm -lpthread
//
//
//              [ The Peterson's Algorithm ]
//
// It's an algorithm for solving CSP(Critical-Section Problem).
// Feature:
//   - theoretically perfect solution
//   - that provides mutual exclusion, progress(no deadlock), and bounded
//   waiting(no starvation)
//   - BUT, it's not feasible to implement in practice,
//   - if you create code the same as the algorithm.

#include <pthread.h>
#include <stdio.h>
=======
//       The Peterson's Algorithm
// 
// It's an algorithm for solving CSP(Critical-Section Problem).
// Feature:
//   - theoretically perfect solution
//   - that provides mutual exclusion, progress(no deadlock), and bounded waiting(no starvation)
//   - BUT, it's not feasible to implement in practice,
//   - if you create code the same as the algorithm.

#include <stdio.h>
#include <pthread.h>
>>>>>>> master

#define true 1
#define false 0

<<<<<<< HEAD
#define SIZE 100000

=======
>>>>>>> master
int sum = 0;

int turn;
int flag[2];

<<<<<<< HEAD
void* producer(void*);
void* consumer(void*);

int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, producer, NULL);
  pthread_create(&tid2, NULL, consumer, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("sum = %d\n", sum);
}

void* producer(void* param) {
  for (int k = 0; k < SIZE; k++) {
    /* entry section */
    flag[0] = true;
    turn = 1;
    while (flag[1] && turn == 1)
      ;

    /* critical section */
    sum++;

    /* exit section */
    flag[0] = false;

    /* remainder section */
  }
  pthread_exit(0);
}

void* consumer(void* param) {
  for (int k = 0; k < SIZE; k++) {
    /* entry section */
    flag[1] = true;
    turn = 0;
    while (flag[0] && turn == 0)
      ;

    /* critical section */
    sum--;

    /* exit section */
    flag[1] = false;

    /* remainder section */
  }
  pthread_exit(0);
=======
int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("sum = %d\n", sum);
>>>>>>> master
}