//
// Created by Muhammad Maaz on 10/1/25.
//

#ifndef CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_CARD_H
#define CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_CARD_H

#include <string>

/**
 * @class Card
 * @notes simulation of a card of specific suit and value
 * @param suit
 * @param value
 * @param isFaceUp
 */
class Card {
private:
    char suit;      // S for Spades, H for Hearts, C for Clubs, D for Diamonds
    int value;      // 1 - 13
    bool isFaceUp;  // true if the card is face up

public:
    /**
     * @note parameterized constructor for Card, face down
     * @param suit must be S, H, C, or D
     * @param value must be between 1 - 13
     */
    Card(char suit, int value);

    /**
     * @note changes isFaceUp value;
     */
    void flip();

    /**
     *
     * @return suit
     */
    char getSuit() const;

    /**
     *
     * @return value
     */
    int getValue() const;

    /**
     *
     * @return isFaceUp
     */
    bool getFaceUp() const;

    /**
     *
     * @return "value""suit"
     */
    std::string display() const;
};


#endif //CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_CARD_H