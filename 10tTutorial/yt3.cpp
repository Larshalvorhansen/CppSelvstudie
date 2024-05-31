#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void play_game()
{
    int random = rand() % 251;
    cout << random << endl;
    cout << "Guess a number: ";
    while (true)
    {
        int guess;
        cin >> guess;
        if(guess == random)
        {
            cout << "you win!\n";
            break;
        } else if(guess < random)
        {
            cout << "Too low\n";
        }
        else
        {
            cout << "Too high\n";
        }
    }
    
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        cout << "0. Quit" << endl << "1. Play Game\n";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thanks for nothing\n";
            return 0;
        case 1:
            cout << "Lets play\n";
            play_game();
            break;
        }
    } while (choice != 0);
}