cmake_minimum_required(VERSION 4.0)
project(CS116Fall2025_StochasticSolitaireSimulator)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(CS116Fall2025_StochasticSolitaireSimulator
        main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Game.cpp
        Game.h)
