#include <stdio.h>

typedef enum faciem {PASS, LEFT, RIGHT, CENTER} faces;
faces die [] = {LEFT, RIGHT, CENTER, PASS, PASS, PASS};

char *philosophers[] = {"Immanuel Kant ",
                        "Martin Heidegger",
                        "David Hume",
                        "Georg Wilhelm Friedrich Hegel",
                        "Arthur Schopenhauer",
                        "Ludwig Wittgenstein",
                        "Karl Wilhelm Friedrich Schlegel",
                        "Friedrich Nietzsche",
                        "Socrates",
                        "John Stuart Mill",
                        "Plato",
                        "Aristotle",
                        "Thomas Hobbes",
                        "Rene Descartes"};

uint8_t left(uint8_t pos, uint8_t players);
uint8_t right(uint8_t pos, uint8_t players);

int main() {
    return 0;
}

/* Functions left and right provided by Darrel Long */

/*
* Returns the position of the player to the left.
*
* pos:     The position of the current player.
* players: The number of players in the game.
*/
static inline uint8_t left(uint8_t pos, uint8_t players) {
	return ((pos + players -1) % players);
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
