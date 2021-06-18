#include "monopoly.h"
#include <stdlib.h>
#include <stdio.h>

const struct card_t default_chance[16] = {
    { .name = "Advance to Boardwalk",               .in_deck = 1,   .index=0},
    { .name = "Advance to Go",                      .in_deck = 1,   .index=1},
    { .name = "Advance to Illinois Avenue",         .in_deck = 1,   .index=2},
    { .name = "Advance to St. Charles Place",       .in_deck = 1,   .index=3},
    { .name = "Advance to the nearest Railroad",    .in_deck = 1,   .index=4},
    { .name = "Advance to the nearest Railroad",    .in_deck = 1,   .index=5},
    { .name = "Advance to nearest Utility",         .in_deck = 1,   .index=6},
    { .name = "Bank pays you dividend of $50",      .in_deck = 1,   .index=7},
    { .name = "Get Out of Jail Free",               .in_deck = 1,   .index=8},
    { .name = "Go back 3 spaces",                   .in_deck = 1,   .index=9},
    { .name = "Go to Jail",                         .in_deck = 1,   .index=10},
    { .name = "general repairs on your property",   .in_deck = 1,   .index=11},
    { .name = "Speeding fine $15",                  .in_deck = 1,   .index=12},
    { .name = "Take a trip to Reading Railroad",    .in_deck = 1,   .index=13},
    { .name = "Pay each player $50",                .in_deck = 1,   .index=14},
    { .name = "Collect $150",                       .in_deck = 1,   .index=15}
};

const struct card_t default_chest[16] = {
    { .name = "Advance to Go",                      .in_deck = 1,   .index=0},
    { .name = "Collect $200",                       .in_deck = 1,   .index=1},
    { .name = "Pay $50",                            .in_deck = 1,   .index=2},
    { .name = "Pay $50",                            .in_deck = 1,   .index=3},
    { .name = "you get $50",                        .in_deck = 1,   .index=4},
    { .name = "Get Out of Jail Free",               .in_deck = 1,   .index=5},
    { .name = "Go to Jail",                         .in_deck = 1,   .index=6},
    { .name = "Receive $100",                       .in_deck = 1,   .index=7},
    { .name = "Collect $100",                       .in_deck = 1,   .index=8},
    { .name = "You inherit $100",                   .in_deck = 1,   .index=9},
    { .name = "Collect $20",                        .in_deck = 1,   .index=10},
    { .name = "Collect $10 from every player",      .in_deck = 1,   .index=11},
    { .name = "Pay $100",                           .in_deck = 1,   .index=12},
    { .name = "Receive $25",                        .in_deck = 1,   .index=13},
    { .name = "Pay $40 per house $115 per hotel",   .in_deck = 1,   .index=14},
    { .name = "Collect $10",                        .in_deck = 1,   .index=15}
};

struct card_t draw_card(struct card_t* deck) {
    int card;
    do {
        card = rand() % 16;
    } while (deck[card].in_deck != 1);
    deck[card].in_deck = 0;

    int cards_in_deck = 0;
    int i;
    for (i = 0; i < 16; i++) {
        cards_in_deck += deck[i].in_deck;
    }
    if (cards_in_deck == 0) {
        for (i = 0; i < 16; i++) {
            deck[i].in_deck = 1;
        }
    }
    return deck[card];
}

void chance_action(struct player_t *player, struct card_t card) {
    switch (card.index) {
        case 0:     //advance to boardwalk
            player->position = 39;
            break;
        case 1:     //advance to go
            player->position = 0;
            break;
        case 2:     //Advance to Illinois Avenue
            player->position = 24;
            break;
        case 3:     //Advance to St. Charles Place
            player->position = 11;
            break;
        case 4:     //Advance to the nearest Railroad
        case 5:     //Advance to the nearest Railroad
            
            break;
        case 6:     //Advance to nearest Utility
            
            break;
        case 7:     //Bank pays you dividend of $50
            player->money += 50;
            break;
        case 8:     //Get Out of Jail Free
            player->jail_cards += 1;
            break;
        case 9:     //Go back 3 spaces
            player->position -= 3;
            break;
        case 10:     //Go to Jail
            player->position = 10;
            break;
        case 11:     //general repairs on your property
            
            break;
        case 12:     //Speeding fine $15
            player->money -= 15;
            break;
        case 13:     //Take a trip to Reading Railroad
            player->position = 5;
            break;
        case 14:     //Pay each player $50
            
            break;
        case 15:     //Collect $150
            player->money += 150;
            break;
        default:
            break;
    }
}

void chest_action(struct player_t *player, struct card_t card) {
    switch (card.index) {
        case 0:     //Advance to Go
            player->position = 0;
            break;
        case 1:     //Collect $200
            player->money += 200;
            break;
        case 2:     //Pay $50
        case 3:
            player->money -= 50;
            break;
        case 4:     //you get $50"
            player->money += 50;
            break;
        case 5:     //Get Out of Jail Free
            player->jail_cards += 1;
            break;
        case 6:     //Go to Jail
            player->jail_cards += 1;
            break;
        case 7:     //Receive $100 and Collect $100 and You inherit $100
        case 8:
        case 9:
            player->money += 100;
            break;
        case 10:     //Collect $20
            player->money += 20;
            break;
        case 11:     //Collect $10 from every player
            
            break;
        case 12:     //Pay $100
            player->money -= 100;
            break;
        case 13:     //Receive $25
            player->money += 25;
            break;
        case 14:     //Pay $40 per house $115 per hotel
            
            break;
        case 15:     //Collect $10
            player->money += 10;
            break;
        default:
            break;
    }
}