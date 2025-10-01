//
// Created by Muhammad Maaz on 10/1/25.
//

#ifndef CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H
#define CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H

#include "Deck.h"

class Game {
private:
    Deck deck;
public:
    Game();
    bool play(std::string firstCard);   // returns success or fail
};


#endif //CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_GAME_H