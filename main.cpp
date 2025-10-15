//
// Created by Muhammad Maaz on 10/1/25.
//

#include "Game.h"
#include <iostream>
#include <string>

// uncomment #define PRINTOFF in Game.h when
// running large simulations

int main() {

    bool largeSimulation = false;
    char choice;

    std::cout << "Do you want to simulato a large number of games? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        largeSimulation = true;
    }

    bool printEnabled = !largeSimulation;

    int totalGames = 0;
    char suit = 'S';
    int value;

    if (largeSimulation) {

        totalGames = 100000;
        suit = 'S';
        value = 1;

        int wins = 0;

        for (int gameNum = 1; gameNum <= totalGames; gameNum++) {
            Game game;

            bool success = game.play(suit, value);

            if (success) wins ++;

        }
        double probability = static_cast<double>(wins) / static_cast<double>(totalGames);
        std::cout << "\nTotal games: " << totalGames << "\n";
        std::cout << "Total wins: " << wins << "\n";
        std::cout << "Estimated probability of winning: " << probability * 100 << "%\n";


    } else {
        // prompt user for how many games to play
        std::cout << "Enter the number of games to simulate: ";
        std::cin >> totalGames;

        // validate input
        if (totalGames <= 0) {
            std::cout << "Number of games must be greater than 0!\n";
            return 1;
        }

        // prompt user for starting card for each game
        std::string startCard;
        std::cout << "Enter starting card for each game (4H, AS): ";
        std::cin >> startCard;

        // validate input
        if (startCard.length() == 2) {
            char valChar = startCard[0];
            switch (valChar) {
                case 'A': value = 1; break;
                case 'J': value = 11; break;
                case 'Q': value = 12; break;
                case 'K': value = 13; break;
                default: value = valChar - '0'; break;
            }
            suit = startCard[1];
        } else if (startCard.length() == 3 && startCard[0] == '1'
            && startCard[1] == '0') {
            value = 10;
            suit = startCard[2];
        } else {
            std::cout << "Invalid card input!\n";
            return 1;
        }

        // simulate each game and calculate win percentage
        int wins = 0;   // counter for games won

        for (int gameNum = 1; gameNum <= totalGames; gameNum++) {
            Game game;      // create new game
            if (printEnabled) {
                std::cout << "Game #" << gameNum << ": " << std::endl;
            }

            bool success = game.play(suit, value);

            if (printEnabled) {
                std::cout << "Result: " << (success ? "SUCCESS" : "FAIL") << std::endl;
            }

            if (success) wins++;

        }




        double probability = static_cast<double>(wins) / static_cast<double>(totalGames);
        std::cout << "\nTotal games: " << totalGames << "\n";
        std::cout << "Total wins: " << wins << "\n";
        std::cout << "Estimated probability of winning: " << probability * 100 << "\n";
    }

    return 0;
}