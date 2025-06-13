#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX 100

int counter = 1;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool is_odd_turn = true;

void* print_odd(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (!is_odd_turn && counter <= MAX)
            pthread_cond_wait(&cond, &lock);

        if (counter > MAX) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Odd Thread: %d\n", counter);
        counter++;
        is_odd_turn = false;

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* print_even(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (is_odd_turn && counter <= MAX)
            pthread_cond_wait(&cond, &lock);

        if (counter > MAX) {
            pthread_mutex_unlock(&lock);
            break;
        }

        printf("Even Thread: %d\n", counter);
        counter++;
        is_odd_turn = true;

        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, print_odd, NULL);
    pthread_create(&t2, NULL, print_even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished printing up to %d.\n", MAX);
    return 0;
}

