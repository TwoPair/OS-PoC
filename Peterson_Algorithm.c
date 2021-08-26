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

#define true 1
#define false 0

int sum = 0;

int turn;
int flag[2];

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("sum = %d\n", sum);
}