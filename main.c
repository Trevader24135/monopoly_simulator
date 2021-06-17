#include <stdio.h>
#include <pthread.h>
#include "game.h"

static pthread_mutex_t results_lock = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, play_monopoly, &results_lock);
        threads_open++;
    }
    
    while (threads_open > 0);

    for (i = 0; i < 40; i++){
        results[i] /= NUM_THREADS;
        printf("%s: %f\n", tile_names[i],results[i]);
    }
}