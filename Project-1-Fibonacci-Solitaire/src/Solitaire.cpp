#include "Card.cpp"
#include "Deck.cpp"

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Check if a number belongs to fibonacci sequence.
 * @param num a number need to be checked
 * 
 */
bool isFibo(int num) {
    if (num == 1) {
        return true;
    }

    int sum = 1;
    int i = 1;
    while (sum <= num) {
        int j = sum;
        sum += i;
        i = j;
        if (sum == num) {
            return true;
        }
    }
    return false;
    

}

int main() {
    //Root of random number.
    srand(time(NULL));

    cout << "Welcome to Fibonacci Solitaire!" << endl;
    int input = 0;
    int games = 0;
    Deck deck;

    while (input != 5) {
        cout << endl;
        cout << "1) New Deck" << endl;
        cout << "2) Display Deck" << endl;
        cout << "3) Shuffle Deck" << endl;
        cout << "4) Play Solitaire" << endl;
        cout << "5) Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> input;
        if (cin && (input > 0) && (input < 6)) {
            bool fibo = false;
            int pile = 0;
            int sum = 0;

            switch (input) {
            case 1:
                deck.refreshDeck();
                cout << "A new deck is created." << endl;
                break;
            case 2:
                cout << "The deck is displaying..." << endl;
                deck.display();
                cout << endl;
                break;
            case 3:
                deck.shuffle();
                cout << "The deck was shuffled." << endl;
                break;
            case 4:
                //PLAY GAME
                cout << "Playing Fibonacci Solitaire !!!\n\n";

                while (!fibo) {
                    //Drawing a top card
                    Card card;
                    card = deck.deal();
                    cout << setw(1) << left << "|";
                    card.display();

                    sum += card.getValue();

                    if (isFibo(sum)) {
                        cout << "|  Fibo: " << sum << endl;
                        sum = 0;
                        pile++;
                        if (deck.isEmpty()) {
                            cout << "Winner in " << pile << " pile(s)!" << endl;
                            //Stop the game
                            fibo = true;

                            //Display game played to win
                            games++;
                            cout << endl << "Games played to be a winner: " << games << endl;
                        }
                    }
                    else {
                        if (deck.isEmpty()) {
                            cout << "|";
                            cout << "\nLast hand value: " << sum << endl;
                            cout << "Loser in " << pile << " pile(s)!" << endl;
                            games++;
                            break;
                        }
                    }

                }
                break;

            default:
                cout << "Game stopped." << endl;
                break;
            }
        }else{
            cout << "You entered invalid input! Please enter again: " << endl;
            cin.clear();
            cin.ignore();
            input = 0;
        }
    }

    return 0;
}