#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>

using namespace std;

class Deck{
    private:
        Card card[52];
        int topCard;
    public:
        Deck();
        void refreshDeck();
        Card deal();
        void shuffle();
        bool isEmpty();
        void display();
};

#endif