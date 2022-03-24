#pragma once
#include "std_lib_facilities.h"

struct Temps{
    float max;
    float min;
};
    //public:
        // friend istream& operator>>(istream& is, Temps& t);
        // vector<string> readTemps(string filnavn);
        // vector tempStats();

    istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemps(string filename);

void tempStats(vector<Temps> T);
