#include "blackjack.h"

bool Blackjack::isAce(Card c){
    if(c.getRank()==Rank::ace){return true;}
    else{return false;}
}

int getCardValue(Card c){
    if(c.getRank()==Rank::ace)          {return 11;}
    else if(c.getRank()==Rank::king)    {return 10;}
    else if(c.getRank()==Rank::queen)   {return 10;}
    else if(c.getRank()==Rank::jack)    {return 10;}
    else if(c.getRank()==Rank::ten)     {return 10;}
    else if(c.getRank()==Rank::nine)    {return 9;}
    else if(c.getRank()==Rank::eight)   {return 8;}
    else if(c.getRank()==Rank::seven)   {return 7;}
    else if(c.getRank()==Rank::six)     {return 6;}
    else if(c.getRank()==Rank::five)    {return 5;}
    else if(c.getRank()==Rank::four)    {return 4;}
    else if(c.getRank()==Rank::three)   {return 3;}
    else if(c.getRank()==Rank::two)     {return 2;}
}
