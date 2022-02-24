#include "Card.h"

string suitToString(Suit s){
    string strengType = "";
    int intType{static_cast<int>(s)};
    switch(intType){
        case int(Suit::clubs): //Kan bruke denne måten for å konvertere til int
            strengType = "Clubs";
            break;
        case static_cast<int>(Suit::diamonds): //Men denne er bedre
            strengType = "Diamonds";
            break;
        case static_cast<int>(Suit::hearts):
            strengType = "Hearts";
            break;
        case static_cast<int>(Suit::spades):
            strengType = "Spades";
            break;
    }
    //cout << strengType << endl;
    return(strengType);
}
// two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}
string rankToString(Rank r){
    string strengType = "";
    int intType {static_cast<int>(r)};
    switch(intType){
        case int(Rank::two):
            strengType = "two";
            break;
        case static_cast<int>(Rank::three):
            strengType = "three";
            break;
        case 4:
            strengType = "four";
            break;
        case 5:
            strengType = "five";
            break;
        case 6:
            strengType = "six";
            break;
        case 7:
            strengType = "seven";
            break;
        case 8:
            strengType = "eight";
            break;
        case 9:
            strengType = "nine";
            break;
        case 10:
            strengType = "ten";
            break;
        case 11:
            strengType = "jack";
            break;
        case 12:
            strengType = "queen";
            break;
        case 13:
            strengType = "king";
            break;
        case 14:
            strengType = "ace";
            break;
    }
    //cout << strengType << endl;
    return(strengType);
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}{}

string Card::getSuit(){
    return(suitToString(s));
}

string Card::getRank(){
    return(rankToString(r));
}

string Card::toString(){
    string verdi = rankToString(r);
    string type = suitToString(s);
    string verdiOgType = verdi + " of " + type;
    return(verdiOgType);
}
