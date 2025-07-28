#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNum = rand() % 100 + 1;
    int guess;

    cout << "Guess the number (between 1 and 100):" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < secretNum) {
            cout << "Too low!" << endl;
        } else if (guess > secretNum) {
            cout << "Too high!" << endl;
        } else {
            cout << " You guessed the number!" << endl;
            break;
        }
    }

    return 0;
}
