#pragma once
#include "std_lib_facilities.h"

class Spectroscopy{
    map<double, double> data;
public:
    friend istream& operator>>(istream& is, Spectroscopy& s);
    void printElements(map<string, double> elements);
};