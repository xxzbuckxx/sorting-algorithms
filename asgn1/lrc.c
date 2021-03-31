#include <stdio.h>      // input output library
#include <stdint.h>     // extended integer library
#include <stdlib.h>     // used for EXIT_FAILURE macro
#include "philos.h"     // names if of array of philosopher character arrays

/* Die Enumeration */
typedef enum faciem {PASS, LEFT, RIGHT, CENTER} faces;
faces die [] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};

/* Function Initializations */
/* static inline uint8_t left(uint8_t pos, uint8_t players); */
/* static inline uint8_t right(uint8_t pos, uint8_t players); */

/*
 * Struct that represents a player
 *
 * *name: a pointer to one of the names in the header file
 * balance: current players balance
*/
typedef struct player {
    char *name;
    int balance;
} player;

int main() {

    /* Get Seed and Number of Players */
    int seed = 0;
    int numplayers = 0;

    printf("Enter the seed: ");
    scanf("%d", &seed);
    
    printf("Enter the number of players between 2 and 14 inclusive: ");
    scanf("%d", &numplayers);

    /* Exit with error if improper number of players */
    if(numplayers < 2 || numplayers > 14) {
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    }

    /* Create array of player structs */
    int i;
    player players[numplayers];

    for(i = 0; i < numplayers; i++) {
        /* name pointer of struct pointing to beginning of character arr */
        players[i].name = philosophers[i];
        players[i].balance = 3;
    }

    /* Main Game Loop */
    while(){

    }

    for(i = 0; i < numplayers; i++)
        printf("%s has %d\n", players[i].name, players[i].balance);

    return 0;
}

/* Functions left and right provided in Lab doc */

/* 
 * Returns the position of the player to the left.
 *
 * pos:     The position of the current player.
 * players: The number of players in the game.
*/
/* static inline uint8_t left(uint8_t pos, uint8_t players) { */
/* 	return ((pos + players -1) % players); */
/* } */

/*
 * Returns the position of the player to the right.
 *
 * pos:     The position of the current player.
 * players: The number of players in the game.
*/
/* static inline uint8_t right(uint8_t pos, uint8_t players) { */
/* 	return ((pos + 1) % players); */
/* } */
