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

struct card_t {
    char name[32];
    int in_deck;
    int index;
};
const struct card_t default_chance[16];
const struct card_t default_chest[16];
struct card_t draw_card(struct card_t* deck);
void chance_action(struct player_t* player, struct card_t card);
void chest_action(struct player_t *player, struct card_t card);

struct player_t new_player(void); //create a new player with default values
struct dice_t roll_dice(void);

#endif