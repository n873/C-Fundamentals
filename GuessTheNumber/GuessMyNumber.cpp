#include <iostream>
#include <stdlib.h>
using namespace std;

void PromptUserToGuess();
string NewGuess();
bool GuessedRight(int newGuess,int randomNumber);
void YouGuessedRight(int guessTryCount, int randomNumber);
string WelcomeUser();

int main() {
    string userName = "";
    userName = WelcomeUser();
    bool continueGuessing = true;
    int randomNumber;
    
    while(continueGuessing) {
        randomNumber = rand() % 10;
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
                cout << " in " << guessTryCount << " " << guessOrGuessesForMessage << endl;
                break;
            } else {
                string tooLowTooHighMessage;
                if(newGuessNumber < randomNumber) tooLowTooHighMessage = "too low"; 
                else tooLowTooHighMessage = "too high";
                cout << "Oops you've guessed " << tooLowTooHighMessage << ", you have " << 3-guessTryCount << " ";
                cout << guessOrGuessesForMessage << " left." << endl << endl;
            }
            guessTryCount++;
        }
        cout << endl << "Do you want to try again?" << endl;
        cout << "Enter y to continue or anything to exit..." << endl;
        
        string userResponse;
        cin >> userResponse;
        if(userResponse != "y") continueGuessing = false;
        cout << endl << "*****************************************************" << endl << endl;
    }
    cout << "Thanks for playing " << userName << "!" << endl;
    return 0;
}

string WelcomeUser() {
    string userName;
    cout<< "Welcome to Guess the number!" << endl << "Whats your name? ";
    cin >> userName;
    cout << endl << endl;
    cout << "Hey " << userName << " Lets start guessing...." << endl << endl;
    return userName;
}

bool GuessedRight(int guess, int numberToGuess) {
    if (guess == numberToGuess)
        return true;
    else return false;
}

string NewGuess() {
    string guess;
    cin >> guess;
    return guess;
}

void PromptUserToGuess() {
    cout << "Enter your Guess below: ie. 0 - 10..." << endl << "You got 3 guesses, good luck!" << endl << endl;
}
