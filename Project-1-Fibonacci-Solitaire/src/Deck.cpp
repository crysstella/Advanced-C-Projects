#include "Deck.h"
#include <time.h>
#include <iomanip>

/**
 * A constructor creates a new deck.
 */
Deck::Deck() {
    topCard = 0;
    card[0] = Card('A', 'S');
    card[1] = Card('A', 'H');
    card[2] = Card('A', 'D');
    card[3] = Card('A', 'C');

    int k = 1;
    int j = 5;
    for (int i = 4; i < 36; i++) {
        switch (k) {
        case 1:
            card[i] = Card('0' + (j - 3), 'S');
            k++;
            break;
        case 2:
            card[i] = Card('0' + (j - 3), 'H');
            k++;
            break;
        case 3:
            card[i] = Card('0' + (j - 3), 'D');
            k++;
            break;
        case 4:
            card[i] = Card('0' + (j - 3), 'C');
            k = 1;
            j++;
            break;
        default:
            break;
        }
    }

    card[36] = Card('T', 'S');
    card[37] = Card('T', 'H');
    card[38] = Card('T', 'D');
    card[39] = Card('T', 'C');

    card[40] = Card('J', 'S');
    card[41] = Card('J', 'H');
    card[42] = Card('J', 'D');
    card[43] = Card('J', 'C');

    card[44] = Card('Q', 'S');
    card[45] = Card('Q', 'H');
    card[46] = Card('Q', 'D');
    card[47] = Card('Q', 'C');

    card[48] = Card('K', 'S');
    card[49] = Card('K', 'H');
    card[50] = Card('K', 'D');
    card[51] = Card('K', 'C');

}

/**
 * Refreshing the deck as a new deck.
 */

void Deck::refreshDeck() {
    topCard = 0;
    card[0].setCard('A', 'S');
    card[1].setCard('A', 'H');
    card[2].setCard('A', 'D');
    card[3].setCard('A', 'C');

    int k = 1;
    int j = 5;
    for (int i = 4; i < 40; i++) {
        switch (k) {
        case 1:
            card[i].setCard('0' + (j - 3), 'S');
            k++;
            break;
        case 2:
            card[i].setCard('0' + (j - 3), 'H');
            k++;
            break;
        case 3:
            card[i].setCard('0' + (j - 3), 'D');
            k++;
            break;
        case 4:
            card[i].setCard('0' + (j - 3), 'C');
            k = 1;
            j++;
            break;
        default:
            break;
        }
    }

    card[40].setCard('J', 'S');
    card[41].setCard('J', 'H');
    card[42].setCard('J', 'D');
    card[43].setCard('J', 'C');

    card[44].setCard('Q', 'S');
    card[45].setCard('Q', 'H');
    card[46].setCard('Q', 'D');
    card[47].setCard('Q', 'C');

    card[48].setCard('K', 'S');
    card[49].setCard('K', 'H');
    card[50].setCard('K', 'D');
    card[51].setCard('K', 'C');

}

/**
 * Drawing a card and keeping track on the deck.
 * 
 * @return a card on top.
 */
Card Deck::deal() {
    return card[topCard++];
}

/**
 * Shuffle the deck.
 */
void Deck::shuffle() {
    // shuffle  1000 times
    for (int i = 0; i < 1000; i++) {
        int x = rand() % 52;
        int y = rand() % 52;

        Card temp;
        temp = card[x];
        card[x] = card[y];
        card[y] = temp;
    }
}

/**
 * Check the deck if it has no card left.
 * 
 * @return true if the deck is empty and vice versa.
 */
bool Deck::isEmpty() {
    if (topCard == 52){
        topCard = 0;
        return true;
    }
    return false;
}

/**
 * Print the deck of 52 cards.
 */
void Deck::display() {
    int cols = 1;
    for (int i = 0; i < 52; i++) {
        if (cols > 13) {
            cols = 1;
            cout << "|" << endl;
        }
        cols++;
        cout << setw(1) << left << "|";
        card[i].display();
    }
    cout << "|";
}
