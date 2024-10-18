# Game of 21

This is a simple command-line game of 21 (similar to Blackjack) implemented in C++. The player competes against the house, with the goal of getting as close to 21 as possible without exceeding it.

## How to Play

1. The player starts with an initial amount of money (e.g., $101.00).
2. The player places a wager before each round.
3. Both the player and the house roll a die to start the game.
4. The player can choose to "hit" (roll another die) or "stand" (keep their current total).
5. The goal is to have a total value closer to 21 than the house without going over.

### Game Rules
- The player rolls a 14-sided die.
- The house will keep rolling until its total is at least 17.
- If the player goes over 21, they lose the round.
- If the house's total is closer to 21 than the player's without going over, the house wins.
- If both the player and the house have the same total, it's a draw ("push").

## Requirements
- C++ compiler (e.g., g++)

## How to Compile and Run
1. Open a terminal and navigate to the project directory.
2. Compile the code with the following command:
   ```bash
   g++ -o game_of_21 game_of_21.cpp
<img width="368" alt="image" src="https://github.com/user-attachments/assets/167037df-ec7b-4c0a-bd20-2f0d3b71a3ab">

Features
Simple command-line interface
Allows the player to wager and manage their money
Randomized dice rolls using C++'s <random> library
Future Improvements
Add more betting options.
Implement a graphical user interface (GUI).
Introduce additional game modes or rules.
License
This project is open-source and available for modification and distribution under the MIT License.

Author
Julie CoxLambright
