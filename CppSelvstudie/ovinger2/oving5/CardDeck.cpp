#include "CardDeck.h"

CardDeck::CardDeck() {
	for (auto r : rankToStringMap) {
		for (auto s : suitToStringMap) {
			Card c{s.first, r.first};
			cards.push_back(c);
			// Alternativt:
			// cards.emplace_back(s.first, r.first)
		}
	}
}

void CardDeck::swap(int a, int b){
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;
}

void CardDeck::print(){
    for(auto i : cards){
        cout << i.toString() << endl;
    }
}

void CardDeck::shuffle(){
    for (int i = 0; i < 52*4; i++){
        swap(rand() % 52,rand() % 52);
    }
}

Card CardDeck::drawCard(){
    if (cards.size()>0){
        Card c = cards[cards.size()-1];
        cards.pop_back();
        return c;
    }
    else{error("Carddeck empty");};
}