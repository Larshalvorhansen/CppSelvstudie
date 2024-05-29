#include "mastermind.h"

void playMastermind(){
    constexpr int size = 4;
    constexpr int letters = 6;
    string code = randomizeString(size, 'A', 'A'+letters);
    string guess;
    cout << code << endl;
    cout << "::PLAY MASTERMIND::" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "make a guess" << endl;
        cin >> guess;
        if (guess==code){
            cout << "Congats you won!" << endl;
            break;
        }
        cout << "Rigth position and letter: " << charPos(guess, code) << endl;
        cout << "Only rigth letter: " << pos(guess, code)-charPos(guess, code) << endl;
        if(i==7){
            cout << "You are out of tries. Good luck next time" << endl;
        }
    }
    //cout << code << endl; //test
}

int charPos(string guess, string code){
    int counter = 0;
    for (int i = 0; i < guess.length(); i++)
    {
        if(guess[i]==code[i]){
            counter++;
        }
    }
    return counter;
}

int pos(string guess, string code){
    int counter = 0;
    for (int i = 0; i < guess.length(); i++)
    {
        if(guess[i]==code[0] || guess[i]==code[1] || guess[i]==code[2] || guess[i]==code[3]){
            counter++;
        }
    }
    return counter;
}