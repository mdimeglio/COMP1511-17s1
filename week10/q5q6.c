
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "trader_bot.h"


/* FROM trader_bot.h
struct bot {
    char            *name;
    int             cash;
    int             fuel;
    struct location *location;
    struct cargo    *cargo;
    int             turns_left;
    int             fuel_tank_capacity;
    int             maximum_move;
    int             maximum_cargo_weight;
    int             maximum_cargo_volume;
};

struct location {
    char                *name;
    int                 type;
    struct commodity    *commodity;
    int                 price;
    int                 quantity;
    struct location     *next;
    struct location     *previous;
    struct bot_list     *bots;
};

struct cargo {
    struct cargo        *next;
    struct commodity    *commodity;
    int                 quantity;
};

struct commodity {
    char   *name; 
    int    weight; 
    int    volume; 
};
*/

// return how many "Mars Bars" the bot's cargo contains
int cargo_mars_bars(struct bot *b) {
    for(struct cargo *cur = b->cargo; cur != NULL; cur = cur->next) {
        if (strcmp(cur->commodity->name, "Mars Bars") == 0) {
            return cur->quantity;
        }
    }
	return 0;
}

// return how many "Mars Bars" for sale at the current location
int mars_bars_for_sale(struct bot *b) {
    struct location *l = b->location;
	if (l->type == LOCATION_SELLER &&
	    l->commodity != NULL &&
	    strcmp(l->commodity->name, "Mars Bars") == 0) {
	    return l->quantity;
	}
	return 0;
}


int main(void) {
	struct commodity dairy_milk = {"Dairy Milk", 5, 10};
	struct commodity mars_bars = {"Mars Bars", 4, 11};
	struct commodity milky_way = {"Milky Way", 7, 12};
	struct commodity kit_kat = {"Kit Kat", 8, 3};

	struct cargo cargo4 = {NULL, &dairy_milk, 3};
	struct cargo cargo3 = {&cargo4, &mars_bars, 5};
	struct cargo cargo2 = {&cargo3, &milky_way, 2};
	struct cargo cargo1 = {&cargo2, &kit_kat, 7};

	struct location CSE = {
		"CSE",
		LOCATION_BUYER,
		&mars_bars,
		500,
		30,
		NULL,
		NULL,
		NULL
	};

	struct location Coles = {
		"Coles",
		LOCATION_SELLER,
		&mars_bars,
		600,
		20,
		&CSE,
		&CSE,
		NULL
	};

	CSE.next = &Coles;
	CSE.previous = &Coles;

	
	struct bot b;

	b.cargo = &cargo1;

	int num_mars = cargo_mars_bars(&b);
	printf("Num mars is %d\n", num_mars);
	assert(num_mars == 5);

	b.location = &CSE;
	num_mars = mars_bars_for_sale(&b);
	printf("Num mars for sale is %d\n", num_mars);
	assert(num_mars == 0);

	b.location = &Coles;
	num_mars = mars_bars_for_sale(&b);
	printf("Num mars for sale is %d\n", num_mars);
	assert(num_mars == 20);

	printf("All tests passed\n");

	return 0;

}

/*
int cargo_mars_bars(struct bot *b) {
    for (struct cargo *c = b->cargo; c != NULL; c = c->next) {
        if (strcmp("Mars Bars", c->commodity->name) == 0) {
            // A commodity  occur at most once in the cargo list
            return c->quantity;
        }
    }
    return 0;
}


int mars_bars_for_sale(struct bot *b) {
    struct location * l = b->location;

    if (l->type == LOCATION_SELLER && strcmp("Mars Bars", l->commodity->name) == 0) {
        return l->quantity;
    } else {
        return 0;
    }
}

*/
