#include "philos.h" // array of philosopher names (char arrays)

#include <stdint.h> // extended integer library
#include <stdio.h> // input output library
#include <stdlib.h> // used for EXIT_FAILURE macro

/* Die Enumeration */
typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
faces die[] = { LEFT, RIGHT, CENTER, PASS, PASS, PASS };

/* Function Initializations */
static inline uint8_t left(uint8_t pos, uint8_t players);
static inline uint8_t right(uint8_t pos, uint8_t players);

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

/*
 * Main Execution of the Program happens here
 *
 * The program contains 3 main parts:
 *     1. Ask for input
 *     2. Create array of players
 *     3. Simulate game
*/
int main() {

    /* Ask for input */
    int seed = 0;
    int numplayers = 0;

    printf("Enter the seed: ");
    scanf("%d", &seed);

    srandom(seed); //Set seed to of random

    printf("Enter the number of players between 2 and 14 inclusive: ");
    scanf("%d", &numplayers);

    /* Exit with error if improper number of players */
    if (numplayers < 2 || numplayers > 14) {
        printf("The number of philosophers must be 2-14! >:(\n");
        exit(EXIT_FAILURE);
    }

    /* Create array of players */
    int i;
    player players[numplayers];

    for (i = 0; i < numplayers; i++) {
        /* name pointer of struct pointing to beginning of character arr */
        players[i].name = philosophers[i];
        players[i].balance = 3;
    }

    /* Simulate game */
    int inplayers = numplayers;
    int pot = 0;

    /* Since random number is generated from 0 - RAND_MAX then to choose a
     * random value from 1-6 the range of random numbers must be divided by 6 */
    int rdiv = RAND_MAX / 6;

    while (inplayers > 1) {
        int p;
        for (p = 0; p < numplayers; p++) {
            int m;
            for (m = 0; m < players[p].balance; m++) {
                int roll = random();
                if (roll < rdiv) {
                    /* left */
                    players[p].balance--;
                    if (++players[left(p, numplayers)].balance == 1)
                        inplayers++;
                } else if (roll > rdiv && roll <= rdiv * 2) {
                    /* right */
                    players[p].balance--;
                    if (++players[right(p, numplayers)].balance == 1)
                        inplayers++;
                } else if (roll > rdiv * 2 && roll <= rdiv * 3) {
                    /* pot */
                    players[p].balance--;
                    pot++;
                } else {
                    printf("PASS");
                }

                if (players[p].balance <= 0)
                    inplayers--;

                if (inplayers == 1) {
                    printf("Homie won! the $%d pot", pot);
                    return 0;
                }

                for (i = 0; i < numplayers; i++)
                    printf("%s has %d\n", players[i].name, players[i].balance);

                printf("%d\n\n", inplayers);
            }
        }
    }
}

/* Functions left and right provided in Lab doc */

/* 
 * Returns the position of the player to the left.
 *
 * pos:     The position of the current player.
 * players: The number of players in the game.
*/
static inline uint8_t left(uint8_t pos, uint8_t players) {
    return ((pos + players - 1) % players);
}

/*
 * Returns the position of the player to the right.
 *
 * pos:     The position of the current player.
 * players: The number of players in the game.
*/
static inline uint8_t right(uint8_t pos, uint8_t players) {
    return ((pos + 1) % players);
}
