#pragma once
#include "std_lib_facilities.h"
#include "CardDeck.h"

class BlackJack{
    private:
        CardDeck deck;
        Card playerHand, dealerHand;
        int playerHandSum, dealerHandSum;
    public:
        bool isAce(Card c);
        int getCardValue(Card c);
        int getHandScore(vector<Card>Hand);
        bool askPlayerCard();
        void drawPlayerCard();
        void drawDealerCard();
};