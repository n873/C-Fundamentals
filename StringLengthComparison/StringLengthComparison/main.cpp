//
//  main.cpp
//  StringLengthComparison
//
//  Created by Nathan Alard on 2019/06/10.
//  Copyright © 2019 Nathan Alard. All rights reserved.

#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Welcome to word compare" << endl;
    
    bool tryAgain = true;
    
    while(tryAgain) {
        cout << "Enter your first word...." << endl;
        string firstWord;
        cin >> firstWord;
        
        cout << endl << "Enter your second word...." << endl;
        string secondWord;
        cin >> secondWord;
        
        cout << endl << "Your numbers are being measured...." << endl;
        auto firstWordLength = firstWord.length();
        auto secondWordLength = secondWord.length();
        
        if(secondWordLength == firstWordLength)
            cout << secondWord << " is equal length to " << firstWord;
        else if(secondWordLength > firstWordLength)
            cout << secondWord << " is longer than " << firstWord << " by " << secondWordLength - firstWordLength << " more characters";
        else cout << firstWord << " is longer than " << secondWord << " by " <<  firstWordLength - secondWordLength << " more characters";
        
        cout << endl << endl << "Try again?....y to continue" << endl << endl;
        string userInput;
        cin >> userInput;
        if(userInput != "y") tryAgain = false;
    }
    return 0;
}
