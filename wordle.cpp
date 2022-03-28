#include "wordle.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


int wordleGame()
{
    bool wordleGameWon = false;
    int attempts = 0;
    string input;
    string word = "POWERS";
    cout << "Wordle Puzzle" << endl;
    cout << "Please enter a 6 letter word" << endl << "You have 6 attempts" << endl;
    while(!wordleGameWon && attempts < 6){
        attempts++;
        cout << "Input Word: ";
        cin >> input;
        std::for_each(input.begin(), input.end(), [](char & c){
            c = ::toupper(c);
        });
        cout << endl;
        for (int i = 0; i < 6; i++){
            if(input.at(i) == word.at(i)){
                cout << "Letter at Position " << i+1 << " is correct" << endl;
            } else if (word.find(input.at(i)) != std::string::npos) {
                cout << "Word contains letter but is in incorrect position" << endl;
            } else {
                cout << "Letter not found" << endl;
            }
        }
        if(word == input){
            wordleGameWon = true;
            cout << "Wordle game won, the word was " << word << endl;
            return 0;
        }
        cout << "Wordle game lost" << endl;
    }
    return 0;
}
