#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck{
    private:
        vector<Card> cards;
        void swap(int a, int b); //Ligger i private fordi den ikke trenger å hentes fra main
    public:
        CardDeck();
        void print();
        void shuffle();
        Card drawCard();
};