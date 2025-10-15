//
// Created by Muhammad Maaz on 10/1/25.
//

#include "Card.h"

#include <iostream>
#include <ostream>

Card::Card(char suit, int value) {
    this->suit = suit;      // suit set to inputted suit
    this->value = value;    // value set to inputted value
    this->isFaceUp = false; // isFaceUp set to false (facedown)
}

void Card::flip() {
    this->isFaceUp = !this->isFaceUp; // changes isFaceUp value;
}

char Card::getSuit() const {
    return this->suit;      // returns suit
}

int Card::getValue() const {
    return this->value;     // returns value
}

bool Card::getFaceUp() const {
    return this->isFaceUp; // returns isFaceUp
}

std::string Card::display() const {
    if (!this->isFaceUp) {
        return "X";     // card is face down
    }

    std::string valueStr;
    switch (this->getValue()) {
        case 1:
            valueStr = "A"; // Ace
            break;
        case 11:
            valueStr = "J"; // Jack
            break;
        case 12:
            valueStr = "Q"; // Queen
            break;
        case 13:
            valueStr = "K"; // King
            break;
        default:
            valueStr = std::to_string(this->getValue());    // 2-10
    }

    return valueStr + this->getSuit(); // "10H" or "AS"
}
