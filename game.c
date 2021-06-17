#include "monopoly.h"
#include "game.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

float results[40] = {0};

void *play_monopoly(void *results_lock) {
    srand((unsigned) ((pthread_self() << 16) + time(NULL)));
    float tile_landings[40] = {0};

    int game;
    for (game = 0; game < GAMES_PER_THREAD; game++) {
        struct player_t players[NUM_PLAYERS];

        int i;
        for (i = 0; i < NUM_PLAYERS; i++) players[i] = new_player();

        struct tile_t properties[40];
        memcpy(properties, default_properties, sizeof(default_properties));
        
        int round;
        for (round = 0; round < MAX_ROUNDS_PER_GAME; round++) {
            int player;
            for (player = 0; player < NUM_PLAYERS; player++) {
                struct dice_t roll;
                int doubles = 0;
                do {
                    roll = roll_dice();
                    doubles += roll.doubles;
                    if (doubles >= 3) {
                        players[player].position = 10;
                        if (INCLUDE_SEND_TO_JAIL) tile_landings[10]++;
                        break;
                    }
                    players[player].position = (players[player].position + roll.total) % 40;
                    tile_landings[players[player].position]++;
                } while (roll.doubles);
                
            }
        }
    }

    pthread_mutex_lock((pthread_mutex_t)results_lock);
    int i;
    for (i = 0; i < 40; i++){
        tile_landings[i] /= GAMES_PER_THREAD;
        results[i] += tile_landings[i];
    }
    threads_open--;
    pthread_mutex_unlock((pthread_mutex_t)results_lock);
    pthread_exit(NULL);
    return NULL;
}