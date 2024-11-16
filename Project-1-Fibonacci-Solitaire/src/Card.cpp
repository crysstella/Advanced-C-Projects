#include "Card.h"
#include <iomanip>

/** 
 * A constructor creates a new card.
 */
Card::Card() {
    //nothing
}

/**
 * An overloaded constructor creates a card with rank and suit.
 * 
 * @param r rank of a card.
 * @param s suit of a card.
 */
Card::Card(char r, char s) {
    rank = r;
    suit = s;
}

/**
 * Assign a new rank and a new suit to a card.
 * 
 * @param r a rank.
 * @param s a suit.
 */
void Card::setCard(char r, char s) {
    rank = r;
    suit = s;
}

/**
 * Retrieve a proper value of a rank.
 * 
 * @return a value of a rank.
 */
int Card::getValue() {
    switch (rank) {
    case 'A': return 1;
    case 'J':
    case 'Q':
    case 'K':
    case 'T':
        return 10;
    default:
        return rank - '0';
    }
}

/**
 * Prints a card's rank and suit.
 */
void Card::display() {
    int rank1 = 0;
    if (rank == 'T') {
        rank1 = 10;
        cout << setw(3) << right << rank1;
    }
    else {
        cout << setw(3) << right << rank;
    }

    switch (suit) {
    case 'S':
        cout << '\6';
        break;
    case 'H':
        cout << '\3';
        break;
    case 'D':
        cout << '\5';
        break;
    case 'C':
        cout << '\4';
        break;
    default:
        break;
    }

}