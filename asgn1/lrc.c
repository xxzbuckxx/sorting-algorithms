#include "philos.h" // array of philosopher names (char arrays)

#include <stdint.h> // extended integer library
#include <stdio.h> // input output library
#include <stdlib.h> // used for EXIT_FAILURE macro

// Die Enumeration
typedef enum faciem { PASS, LEFT, RIGHT, CENTER } faces;
faces die[] = { LEFT, RIGHT, CENTER, PASS, PASS, PASS };

// Functions left and right provided in Lab doc

//
// Returns the position of the player to the left.
//
// pos:     The position of the current player.
// players: The number of players in the game.
//
static inline uint8_t left(uint8_t pos, uint8_t players) {
    return ((pos + players - 1) % players);
}

//
// Returns the position of the player to the right.
//
// pos:     The position of the current player.
// players: The number of players in the game.
//
static inline uint8_t right(uint8_t pos, uint8_t players) {
    return ((pos + 1) % players);
}

// roll function taken from Proff Long

//
// Returns random number from 0 to n
//
// n: upper limit of random (not inclusive)
//
static inline uint8_t roll(uint8_t n) {
    return (random() % n);
}

//
// Main Execution of the Program happens here
//
// The program contains 3 main parts:
//     1. Ask for input
//     2. Create array of players
//     3. Simulate game
//
int main() {

    // Ask for input
    int64_t seed;
    int32_t numplayers;

    printf("Enter the seed: ");

    // Ensure seed is positive
    if ((scanf("%ld", &seed) < 1) || seed <= 0) {
        printf("Pseudorandom seed must be greater than 0 (%ld)\n", seed);
        exit(EXIT_FAILURE);
    }

    srandom(seed); // Set random seed

    printf("Enter the number of players between 2 and 14 inclusive: ");

    // Ensure Number of players is within game bands
    if ((scanf("%d", &numplayers) < 1) || numplayers < 2 || numplayers > 14) {
        printf("The number of philosophers must be 2-14! >:(\n");
        exit(EXIT_FAILURE);
    }

    // Create array of players
    uint8_t players[numplayers];

    for (uint8_t i = 0; i < numplayers; i++) {
        players[i] = 3; // Each player starts with 3 dollars
    }

    // Simulate game
    uint8_t inplayers = numplayers;
    uint8_t pot = 0;

    while (inplayers > 1) {
        for (uint8_t p = 0; p < numplayers && inplayers > 1; p++) {

            // Skip players turn if they have no money
            if (players[p] == 0) {
                continue;
            }

            printf("%s rolls...", philosophers[p]);

            // Player gets up to three roles, roles = balance
            uint8_t rolls = players[p] < 3 ? players[p] : 3;

            // Player takes turns
            for (uint8_t m = 0; m < rolls; m++) {

                uint8_t face = die[roll(6)]; // Roll die

                // Skip rest of loop if player rolls a PASS
                if (face == PASS) {
                    printf(" gets a pass");
                    continue;
                }

                players[p]--; // Decrease balance

                switch (face) {
                case LEFT: {
                    uint8_t target = left(p, numplayers);
                    printf(" gives $1 to %s", philosophers[target]);

                    // If player was out and is now in then increase in players
                    if (players[target]++ == 0) {
                        inplayers++;
                    }
                } break;
                case RIGHT: {
                    uint8_t target = right(p, numplayers);
                    printf(" gives $1 to %s", philosophers[target]);

                    // If player was out and is now in then increase in players
                    if (players[target]++ == 0) {
                        inplayers++;
                    }
                } break;
                case CENTER: {
                    printf(" puts $1 in the pot");
                    pot++;
                } break;
                default: break;
                }

                // Current player is not in if balance is less than 0
                if (players[p] <= 0) {
                    inplayers--;
                }

                // Game is over if only one player is in
                if (inplayers == 1) {
                    break;
                }
            }

            printf("\n");
        }
    }

    // Find winner and print
    for (uint8_t i = 0; i < numplayers; i++) {
        if (players[i] >= 1) {
            printf("%s wins the $%d pot with $%d left in in the bank!\n", philosophers[i], pot,
                players[i]);
            break;
        }
    }

    return 0;
}
