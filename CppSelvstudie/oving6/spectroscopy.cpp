#include "spectroscopy.h"

istream& operator>>(istream& is, Spectroscopy& s){
    double energy;
    double intensity;
    while(is >> energy >> intensity){
        s.data.insert({energy, intensity});
    }
    return is;
}

void Spectroscopy::printElements(map<string, double> elements){
    for (auto element : elements){
        cout << element.first << ": " << data.at(element.second) << endl;
    }
}