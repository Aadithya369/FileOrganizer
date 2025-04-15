#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

void *increment(void *arg);
void *watch(void *arg);

pthread_mutex_t mymutex;
pthread_cond_t w_cond;
int count = 0;

int main() {
    pthread_t tid1, tid2, tid3;

    // Initialize mutex and condition variable
    pthread_mutex_init(&mymutex, NULL);
    pthread_cond_init(&w_cond, NULL);

    // Create threads
    pthread_create(&tid1, NULL, watch, NULL);
    pthread_create(&tid2, NULL, increment, NULL);
    pthread_create(&tid3, NULL, increment, NULL);

    // Wait for threads to complete
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&mymutex);
    pthread_cond_destroy(&w_cond);

    printf("Main thread is done!\n");
    return 0;
}

void *increment(void *arg) {
    while (1) {
        pthread_mutex_lock(&mymutex);

        if (count >= 10) {
            pthread_mutex_unlock(&mymutex);
            break;
        }

        count++;
        printf("count = %d\n", count);

        if (count == 10) {
            pthread_cond_signal(&w_cond); // Signal watch thread
        }

        pthread_mutex_unlock(&mymutex);
        sleep(1); // Simulate work
    }
    return NULL;
}

void *watch(void *arg) {
    pthread_mutex_lock(&mymutex);

    while (count < 10) {
        pthread_cond_wait(&w_cond, &mymutex); // Wait for signal
    }

    printf("Watch is DONE...\n");
    pthread_mutex_unlock(&mymutex);
    return NULL;
}
