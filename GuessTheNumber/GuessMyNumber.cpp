#include <iostream>
#include <stdlib.h>
using namespace std;

void PromptUserToGuess();
string NewGuess();
bool GuessedRight(int newGuess,int randomNumber);
void YouGuessedRight(int guessTryCount, int randomNumber);

int main() {
    string userName = "";
    cout<< "Welcome to Guess the number!" << endl << "Whats your name? ";
    cin >> userName;
    cout << endl << endl;
    cout << "Hey " << userName << " Lets start guessing...." << endl << endl;
    bool continueGuessing = true;
    int randomNumber = rand() % 100;
    
    while(continueGuessing) {
        randomNumber = rand() % 100;
        PromptUserToGuess();
        int guessTryCount = 1;
        string guessOrGuessesForMessage;
        while (guessTryCount <= 3) {
            if(guessTryCount == 1) guessOrGuessesForMessage = "guess"; 
            else guessOrGuessesForMessage = "guesses";

            string newGuess = NewGuess();
            int newGuessNumber = stoi(newGuess);
            if(GuessedRight(newGuessNumber, randomNumber)) {
                cout << "Welldone " << userName << ", You guessed " << randomNumber;
                cout << " in " << guessTryCount << guessOrGuessesForMessage;
                break;
            } else {
                string tooLowTooHighMessage;
                if(newGuessNumber < randomNumber) tooLowTooHighMessage = "too low"; 
                else tooLowTooHighMessage = "too high";
                cout << "Oops you've guessed " << tooLowTooHighMessage << ", you have " << guessTryCount << " ";
                cout << guessOrGuessesForMessage << " left." << endl;
                guessTryCount++;
            }
        }
        cout << "Do you want to try again?" << endl;
        cout << "Enter y to continue or anything to exit..." << endl;
        cout << "*****************************************************" << endl;;
        string userResponse;
        cin >> userResponse;
        if(userResponse != "y") continueGuessing = false;
    }
    return 0;
}

bool GuessedRight(int guess, int numberToGuess) {
    if (guess == numberToGuess)
        return true;
    else return false;
}

string NewGuess() {
    PromptUserToGuess();
    string guess;
    cin >> guess;
    return guess;
}

void PromptUserToGuess() {
    cout << "Enter your below: ie. 0 - 100..." << endl << "You got 3 guesses, good luck!" << endl << endl;
}
