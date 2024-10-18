#include <iostream>
#include <random> 
#include <string> 
using namespace std;

// Function to roll a 14-sided die
int rollDie() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distribution(2, 14);
    return distribution(gen);
}

// Function to get the player's wager
double getWager(double playerMoney) {
    double wager;
    while (true) {
        cout << "Player's money: $" << playerMoney << endl;
        cout << "Enter your wager: $";
        cin >> wager;

        if (wager <= 0 || wager > playerMoney) {
            cout << "Invalid wager. Please enter a valid amount." << endl;
        } else {
            return wager;
        }
    }
}

// Function to play one round of the game
void playRound(double& playerMoney) {
    double wager = getWager(playerMoney);

    // Player's and house's initial rolls
    int playerTotal = rollDie() + rollDie();
    int houseTotal = rollDie();

    cout << "Player's total: " << playerTotal << endl;
    cout << "House's first roll: " << houseTotal << endl;

    while (playerTotal <= 21) {
        string choice;
        cout << "Do you want to 'hit' or 'stand'? ";
        cin >> choice;

        if (choice == "hit") {
            playerTotal += rollDie();
            cout << "Player's total: " << playerTotal << endl;
        } else if (choice == "stand") {
            break;
        } else {
            cout << "Invalid choice. Please enter 'hit' or 'stand'." << endl;
        }
    }

    while (houseTotal < 17) {
        houseTotal += rollDie();
    }

    cout << "House's total: " << houseTotal << endl;

    if (playerTotal > 21 || (houseTotal <= 21 && houseTotal > playerTotal)) {
        playerMoney -= wager;
        cout << "You lose $" << wager << ". Player's money: $" << playerMoney << endl;
    } else if (houseTotal > 21 || playerTotal > houseTotal) {
        playerMoney += wager;
        cout << "You win $" << wager << ". Player's money: $" << playerMoney << endl;
    } else {
        cout << "It's a push. Player's money: $" << playerMoney << endl;
    }
}

int main() {
    double playerMoney = 101.00;

    while (playerMoney > 0) {
        playRound(playerMoney);

        string playAgain;
        cout << "Do you want to play another round? (yes/no) ";
        cin >> playAgain;

        if (playAgain != "yes") {
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
