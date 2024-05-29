#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

int main(){
    Rank r = Rank::king;
    Suit s = Suit::spades;
    
    cout << rankToString(r) << endl;
    cout << suitToString(s) << endl;

    Card c{Suit::spades, Rank::ace};
    cout << c.toString() << '\n';

    //CardDeck::print();
}

/*
Teori:

1e)
1. det er mer leselig. 
2. vi får typesikkerhet

*/
