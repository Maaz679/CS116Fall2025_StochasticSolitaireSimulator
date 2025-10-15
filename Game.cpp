//
// Created by Muhammad Maaz on 10/1/25.
//

#include "Game.h"
#include <iostream>

// creates a deck and shuffles
Game::Game() {
    deck.shuffle();
}

// displays current state of the deck
void Game::displayDeck() const {
    deck.displayDeck();
}

bool Game::play(char chosenSuit, int chosenValue) {
    char currentSuit = chosenSuit;
    char currentValue = chosenValue;

    while (true) {
        Card& card = deck.chooseCard(currentSuit, currentValue);

        if (card.getFaceUp()) break;

        card.flip();
#ifndef PRINTOFF
        deck.displayDeck(currentSuit, currentValue);
#endif PRINTOFF
        currentSuit = card.getSuit();
        currentValue = card.getValue();
    }

    return deck.isAllFaceUp();

}

bool Game::checkWin() const {
    return deck.isAllFaceUp();
}

