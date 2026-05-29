# Stochastic Solitaire Simulator | C++

A Monte Carlo simulator for a solitaire card game, written in C++. Runs up to 100,000 game iterations from a specified starting card and estimates the win probability.

## Features

- Single game mode with step-by-step output
- Bulk simulation mode (up to 100,000 games) for probability estimation
- Configurable starting card (e.g. `AS` for Ace of Spades, `4H` for Four of Hearts)
- Win rate calculated as a percentage across all simulations

## Build

Requires CMake and a C++ compiler.

```bash
mkdir build && cd build
cmake ..
make
./CS116Fall2025_StochasticSolitaireSimulator
```

## Usage

On launch, choose between single/small simulation or bulk mode:

```
Do you want to simulate a large number of games? (y/n):
```

In small mode, enter the number of games and a starting card:

```
Enter the number of games to simulate: 1000
Enter starting card for each game (4H, AS): AS
```

In large mode, the simulator runs 100,000 games automatically starting from Ace of Spades and prints the estimated win probability.

## How It Works

The project uses three classes:

| Class | Responsibility |
|---|---|
| `Card` | Represents a single playing card with suit and value |
| `Deck` | Manages the full 52-card deck, shuffling, and card state |
| `Game` | Controls game logic: initializes a shuffled deck, plays from the chosen card, checks win condition |

Each simulation creates a new `Game` instance with a freshly shuffled deck, plays from the specified starting card, and records success or failure. Aggregating thousands of results gives a stable probability estimate.

## Class: CS116 Data Structures and Algorithms, SJSU Fall 2025
