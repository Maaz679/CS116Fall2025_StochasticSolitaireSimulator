//
// Created by Muhammad Maaz on 10/1/25.
//

#ifndef CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H
#define CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H
#include <vector>
#include <Card.h>

class Deck {
private:
    std::vector<std::vector<Card>> rows;

public:
    Deck();
    void shuffle();
    Card& getCard(char suit, int value);
    void display() const;
};


#endif //CS116FALL2025_STOCHASTICSOLITAIRESIMULATOR_DECK_H