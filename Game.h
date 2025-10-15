//
// Created by Muhammad Maaz on 10/1/25.
//

#ifndef CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H
#define CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H

#include "Deck.h"

//#define PRINTOFF

/**
 * @class Game
 * @note controls the solitaire game logic. Creates a deck, and shuffles.
 * after selecting a card, will simulate the game and return if you
 * won or lost the game.
 */
class Game {
private:
    Deck deck;      // the deck used for the game
public:
    /**
     * @note  default constructor: initializes deck and shuffles it
     */
    Game();

    /**
     * @note attempt to play the card specified by suit and value
     * @param chosenSuit
     * @param chosenValue
     * @return true if the move was successful, false if not
     */
    bool play(char chosenSuit, int chosenValue);

    /**
     * @note display the current state of the deck
     */
    void displayDeck() const;

    /**
     * @note checks if all cards in the deck are face up (win condition)
     * @return true if all cards are face up, false if not
     */
    bool checkWin() const;

};


#endif //CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H