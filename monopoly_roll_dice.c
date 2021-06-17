#include "monopoly.h"
#include <stdlib.h>

struct dice_t roll_dice(void) {
    int die_one = rand() % 6;
    int die_two = rand() % 6;
    struct dice_t roll = {die_one + die_two + 2, die_one == die_two};
    return roll;
}