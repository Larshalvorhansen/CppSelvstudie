#include "CardDeck.h"

CardDeck::CardDeck(){
    for(int j = 0; j<= 4; j++){//j er suit
        Suit type = static_cast<Suit>(j);
        for(int i = 2; i <= 14; i++){//i er rank
            Rank verdi = static_cast<Rank>(i);
            Card card {type, verdi};
            cards.push_back(card);
            cout << card.getSuit() << " " << card.getRank() << endl;
        }
    }
}

void CardDeck::swap(int a, int b){
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;
}