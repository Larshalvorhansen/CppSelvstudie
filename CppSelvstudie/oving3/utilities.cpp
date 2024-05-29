#include "cannonball.h"

int randomWithLimits(int upper, int lower){
    srand(time(0));
    int limRand = (rand() % abs((upper-lower)) + lower);   //info om hvordan jeg gjorde dette er fra cplusplus.com
    cout << limRand << endl;
    // if(limRand >= lower && limRand <= upper){
    // }
}

