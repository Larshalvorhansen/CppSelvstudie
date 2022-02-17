//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	int choice = -1;
    while (choice != 0){
		// Rank r = Rank::king;
		// Suit s = Suit::hearts;
		// string rank = rankToString(r);
		Card c{Suit::spades, Rank::ace};
		cout << c.toString() << '\n';
        cout << "Angi valg: ";
        cin >> choice;
        cout << '\n';
        switch(choice){
			case 1:
				rankToString(Rank::five);
				break;
			case 2:
				suitToString(Suit::clubs);
				break;
				// Person p{20, "Bob"};
				// p.setAge(21);
			case 3:
				CardDeck hei;
				break;
		}
	}
}
//------------------------------------------------------------------------------

/*
Teori: 
	1e) Fordelen med symboler er at de bruker mindre plass 
	og er mer oversiktelige å bruke 
	ettersom de representerer både en verdi og et navn.
*/