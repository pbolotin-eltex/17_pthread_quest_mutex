#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define THREADS_COUNT 1000
#define CYCLE_LIMIT 1000000

/* Threads will use this function */
void* func(void* par);

/* Threads can use this function too 
 * (uncomment where phtread_create is used, but comment line with func)
 * This version will be much more faster, because of the size of critical section */
void* func_alt(void* par);

/* This is variable that will be incremented by the different threads*/
int A = 0;

/* The only one mutex in the program */
/* Initialize mutex using macros */
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main() {
    /* Variable for the thread IDs */
    pthread_t tid[THREADS_COUNT];
    
    int i;
    /* Main thread starts threads */
    for(i = 0; i < THREADS_COUNT; i++) {
        pthread_create(&tid[i], NULL, func, NULL);
        /*pthread_create(&tid[i], NULL, func_alt, NULL);*/
    }
    /* Here main thread wait for the ending of other threads */
    for(i = 0; i < THREADS_COUNT; i++) {
        pthread_join(tid[i], NULL);
    }
    /* And will print result that has var A after incrementation by threads */
    printf("Result: %d\n", A);
    
    int destroy_result = pthread_mutex_destroy(&mut);
    if(0 != destroy_result) { 
        /* In linux this is just checking - mutex is unlocked? */
        perror("Mutex locked? Can it be so?\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void* func(void* par) {
    int tmp;
    int i;
    for(i = 0; i < CYCLE_LIMIT; i++) {
        pthread_mutex_lock(&mut);
        {/* Critical section is began */
            tmp = A;
            tmp++;
            A = tmp;
        }/* Critical section is ended */
        pthread_mutex_unlock(&mut);
    }
    pthread_exit(0);
    return (void*)0;
}

void* func_alt(void* par) {
    int tmp;
    int i;
    pthread_mutex_lock(&mut);
    {/* Critical section is began */
        for(i = 0; i < CYCLE_LIMIT; i++) {
            
                tmp = A;
                tmp++;
                A = tmp;
            
        }
    }/* Critical section is ended */
    pthread_mutex_unlock(&mut);
    pthread_exit(0);
    return (void*)0;
}
