#include "Card.h"

string suitToString(enum Suit){
    string strengType = "";
    int intType {static_cast<int>(Suit::clubs)};
    switch(intType){
        case 0:
            strengType = "Clubs";
            break;
        case 1:
            strengType = "Diamonds";
            break;
        case 2:
            strengType = "Hearts";
            break;
        case 3:
            strengType = "Spades";
            break;
    }
    cout << strengType << endl;
    return(strengType);
}
// two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace}
string rankToString(enum Rank){
    string strengType = "";
    int intType {static_cast<int>(Rank::jack)};
    switch(intType){
        case 2:
            strengType = "two";
            break;
        case 3:
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
    cout << strengType << endl;
    return(strengType);
}