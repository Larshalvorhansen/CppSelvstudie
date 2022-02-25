#include "tempLesing.h"

istream& operator>>(istream& is, Temp& s){
    while(is >> min >> max){
        t.data.insert({min,max});
    }
}