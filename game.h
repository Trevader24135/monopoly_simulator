#ifndef _GAME_H_
#define _GAME_H_

#include <pthread.h>

#define NUM_THREADS 12
#define GAMES_PER_THREAD    1000
#define MAX_ROUNDS_PER_GAME 100
#define NUM_PLAYERS 4

void *play_monopoly(void *results_lock);
const char tile_names[40][32];
float results[40];
int threads_open;

#endif