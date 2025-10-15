//
// Created by Muhammad Maaz on 10/1/25.
//

#include "Deck.h"
#include <iostream>
#include <iomanip>

Deck::Deck() {
    // initialize 4 suits x 13 cards
    char suits[4] = {'S', 'H', 'C', 'D'};  // creates an array of suits
    rows.resize(4);      // creates 4 inner vectors, one for each suit
    for (int s = 0; s < 4; s++) {       // start of loop over the suits
        for (int v = 0; v < 13; v++) {  // loops over all card values
            // adds a new card to end of vector for the current suit
            rows[s].emplace_back(suits[s], v + 1); // v = {1-13}
        }   // end of inner loop
    }   // end of outer loop
}

void Deck::shuffle() {
    // time(nullptr) returns current time in seconds since epoch in time_t type
    // static_cast<unsigned> converts time_t to an unsigned int
    // srand converts an unsigned int to create a "seed"
    // altogether, will create unique shuffle order for different runtimes
    std::srand(static_cast<unsigned>(time(nullptr)));

    // create a flat vector of every card
    std::vector<Card> unshuffledDeck;   // vector to store 52 cards in a single list
    for (int s = 0; s < 4; s++) {       // loop through each suit index (0-3)
        for (int v = 0; v < 13; v++) {  // loop through each card value index (0-12)
            unshuffledDeck.push_back(rows[s][v]);   // add the cars at [s][v] to the flat list
        }
    }

    // create a vector of pointers to select positions for each card
    std::vector<Card*> shuffledDeck(52, nullptr); // 52 empty positions
    for (int i = 0; i < 52; i++) {  // loop over each of the 52 crds
        int index = rand() % 52;    // generate a random index between 0-51

        // while the position at index is already taken, move to the next one
        while (shuffledDeck[index] != nullptr) {
            index = (index + 1) % 52;   // increment index and wrap around if needed
        }

        shuffledDeck[index] = &unshuffledDeck[i]; // place a pointer to this card into the empty positon
    }

    // rebuild the deck, this time shuffled (4 suits x 13 cards)
    int position = 0;       // index tracker
    for (int s = 0; s < 4; s++) {   // loop through each suit
        rows[s].clear();        // clear old cards
        for (int v = 0; v < 13; v++) {      // loop through the 13 positions in each suit
            rows[s].push_back(*shuffledDeck[position]); // add the shuffled card to this slot
            position ++;        // move to the next shuffled card
        }
    }
}

void Deck::displayDeck(char highlightSuit, int highlightValue) const {
    char suits[4] = {'S', 'H', 'C', 'D'};
    for (int s = 0; s < 4; s++) {

        std::cout << suits[s] << " ";
        for (int v = 0; v < 13; v++) {
            const Card& card = rows[s][v];
            std::string cardStr = card.display();

            if (highlightSuit != '\0' && card.getFaceUp() && card.getSuit() == highlightSuit
                && card.getValue() == highlightValue) {
                cardStr += "*";
            }

            std::cout << std::setw(4) << cardStr;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Card& Deck::chooseCard(char suit, int position) {
    int rowIndex;
    switch (suit) {
        case 'S': rowIndex = 0; break;
        case 'H': rowIndex = 1; break;
        case 'C': rowIndex = 2; break;
        case 'D': rowIndex = 3; break;
        default: rowIndex = 0; break;
    }

    if (position < 1) position = 1;
    if (position > 13) position = 13;

    return rows[rowIndex][position - 1];
}

bool Deck::isAllFaceUp() const {
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 13; v++) {
            if (!rows[s][v].getFaceUp()) {
                return false;
            }
        }
    }
    return true;
}
