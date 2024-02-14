#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class Game {
public:
    void play() {
        srand(time(0));
        int compSecret = rand() % 100 + 1; // Ensure the secret number is between 1 and 100

        int guess;
        do {
            cout << "Enter your guess between 1 and 100: ";
            guess = getValidIntInput();
            if (guess > compSecret) {
                cout << "Your guess is too high.\n";
            } else if (guess < compSecret) {
                cout << "Your guess is too low.\n";
            }
        } while (guess != compSecret);

        cout << "Congratulations! You guessed the correct number: " << compSecret << ".\n";
    }

private:
    int getValidIntInput() {
        int input;
        while (!(cin >> input) || input < 0 || input > 100) {
            cout << "Invalid input. Please enter a number between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return input;
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
