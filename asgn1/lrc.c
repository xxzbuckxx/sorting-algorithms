#include "philos.h" // array of philosopher names (char arrays)

#include <stdint.h> // extended integer library
#include <stdio.h> // input output library
#include <stdlib.h> // used for EXIT_FAILURE macro

/* Die Enumeration */
typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
faces die[] = { LEFT, RIGHT, CENTER, PASS, PASS, PASS };

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

/* roll function taken from Proff Long  */

/*
 * Returns random number from 0 to n
 *
 * n: upper limit of random (not inclusive)
*/
static inline uint8_t roll(uint8_t n) {
    return (random() % n);
}

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

    srandom(seed); //Set random seed

    printf("Enter the number of players between 2 and 14 inclusive: ");

    if ((scanf("%d", &numplayers) < 1) || numplayers < 2 || numplayers > 14) {
        printf("The number of philosophers must be 2-14! >:(\n");
        exit(EXIT_FAILURE);
    }

    /* Create array of players */
    uint8_t i;
    uint8_t players[numplayers];

    for (i = 0; i < numplayers; i++) {
        /* name pointer of struct pointing to beginning of character arr */
        players[i] = 3;
    }

    /* Simulate game */
    uint8_t inplayers = numplayers;
    uint8_t pot = 0;

    /* Since random number is generated from 0 - RAND_MAX then to choose a
     * random value from 1-6 the range of random numbers must be divided by 6 */
    while (inplayers > 1) {
        for (uint8_t p = 0; p < numplayers && inplayers > 1; p++) {

            if (players[p] == 0) {
                continue;
            }

            printf("%s rolls...", philosophers[p]);

            uint8_t roles = players[p];
            for (uint8_t m = 0; m < roles && m < 3; m++) {

                uint8_t face = die[roll(6)];

                if (face == PASS) {
                    printf(" gets a pass");
                    continue;
                }

                players[p]--;

                switch (face) {
                case LEFT: {
                    uint8_t target = left(p, numplayers);
                    printf(" gives $1 to %s", philosophers[target]);

                    if (players[target]++ == 0) {
                        inplayers++;
                    }
                } break;
                case RIGHT: {
                    uint8_t target = right(p, numplayers);
                    printf(" gives $1 to %s", philosophers[target]);

                    if (players[target]++ == 0) {
                        inplayers++;
                    }
                } break;
                case CENTER:
                    printf(" puts $1 in the pot");
                    pot++;
                    break;
                }

                if (players[p] <= 0) {
                    inplayers--;
                }

                if (inplayers == 1) {
                    break;
                }
            }

            printf("\n");
        }
    }

    for (uint8_t i = 0; i < numplayers; i++) {
        if (players[i] > 1) {
            printf("%s wins the $%d pot with $%d left in in the bank!\n", philosophers[i], pot,
                players[i]);
            break;
        }
    }

    return 0;
}
