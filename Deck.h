//
// Created by Muhammad Maaz on 10/1/25.
//

#ifndef CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H
#define CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H

#include <algorithm>    // for shuffle
#include <vector>       // for storing multiple Card objects
#include "Card.h"       // include Card class
#include <random>       // for random number generator

/**
 * @class Deck
 * @note the Deck class stores and manages all 52 cards in 4 rows:
 * S, H, C, D. It provides functions for ini
 */
class Deck {
private:
    std::vector<std::vector<Card>> rows;

public:
    /**
     * @note constructor
     * @brief creates an ordered full deck of cards
     */
    Deck();

    /**
     * @note randomizes the deck
     */
    void shuffle();

    /**
     *
     * @return the card from the deck that is picked
     */
    Card& chooseCard(char suit, int position);

    /**
     * @note displays all the cards in the deck
     */
    void displayDeck(char highlightSuit = '\0', int highlightValue = 0) const;

    /**
     *
     * @return true if the deck is all face up
     */
    bool isAllFaceUp() const;
};


#endif //CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H