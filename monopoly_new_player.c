#include "monopoly.h"

struct player_t new_player(void) {
    struct player_t player;
    player.active = 1;
    player.jail_turns_remaining = 0;
    player.position = 0;
    player.money = 1500;
    player.jail_cards = 0;
    
    return player;
}