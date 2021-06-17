#ifndef _MONOPOLY_H_
#define _MONOPOLY_H_

struct player_t {
    int active;
    int jail_turns_remaining;
    int position;
    int money;
    int properties[40];
    int jail_cards;
};

struct dice_t {
    int total;
    int doubles;
};

struct tile_t {
    char tile_name[32];
    int buy_price;
    int rent[6];
    int house_cost;
    int num_houses;
    int owner;
};
const struct tile_t default_properties[40];

struct player_t new_player(void); //create a new player with default values
struct dice_t roll_dice(void);

#endif