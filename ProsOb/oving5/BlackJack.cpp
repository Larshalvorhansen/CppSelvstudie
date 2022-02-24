#include "BlackJack.h"
#include "Card.h"
#include "CardDeck.h"

bool BlackJack::isAce(Card c){
    if(c.getRank()=="ace"){return(true);}
    else{return(false);}
}

int BlackJack::getCardValue(Card c){
    string valueS = rankToString(c.getRank());
    int value = 0;
    if(valueS == "two"){value = 2;}
    if(valueS == "three"){value = 3;}
    if(valueS == "four"){value = 4;}o
    if(valueS == "five"){value = 5;}
    if(valueS == "six"){value = 6;}
    if(valueS == "seven"){value = 7;}
    if(valueS == "eight"){value = 8;}
    if(valueS == "nine"){value = 9;}
    if(valueS == "ten"){value = 10;}
    if(valueS == "jack"){value = 11;}
    if(valueS == "queen"){value = 12;}
    if(valueS == "king"){value = 13;}
    if(valueS == "ace"){value = 11;}
    return(value);
}

int  BlackJack::getHandScore(vector<Card>Hand){
    int handScore = 0;
    for(int i = 0; i<=Hand.size i++){
        handScore += getCardValue(Card[i]);
    }
    return(handScore);
}

bool BlackJack::askPlayerCard(){
    string svar = "";
    cout << "Ønsker du å ta in et nytt kort? skriv ja eller nei" << endl;
    cin >> svar;
    if(tolower(svar)=="ja"){return true;}else{return false;}
}

void BlackJack::drawPlayerCard(){
    vector<Card> player;
    player.push_back(CardDeck::drawCard);
}