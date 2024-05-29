#pragma once
#include "CardDeck.h"

class Blackjack{
    private:
        CardDeck deck;
        vector<Card> playerHand;
        vector<Card> dealerHand;
        int playerHandSum;
        int dealerHandSum;
    public:
        bool isAce(Card c);
        int getCardValue(Card c);
        int getHandScore();
};