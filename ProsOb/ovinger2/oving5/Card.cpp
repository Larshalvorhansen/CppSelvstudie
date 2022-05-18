#include "Card.h"

string suitToString(Suit s){
    return suitToStringMap.at(s);
}

string rankToString(Rank r){
    return rankToStringMap.at(r);
}

Card::Card(Suit suit,Rank rank): s{suit}, r{rank}{};

Rank Card::getRank() const {
    return r;
}

Suit Card::getSuit() const {
    return s;
}

string Card::toString(){
    if(rankToString(r) + suitToString(s)=="acespades"){
        return "THE ACE OF SPAAADES, THE ACE OF SPAAAADES! ";
    }
    return  "The " + rankToString(r)+ " of " + suitToString(s);
}