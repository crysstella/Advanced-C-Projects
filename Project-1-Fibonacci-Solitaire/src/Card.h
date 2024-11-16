#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card{
    private:
        char rank;
        char suit;
        bool face_up;

    public:
        Card();
        Card(char r, char s);
        void setCard(char r, char s);
        int getValue();
        void display();
};

#endif