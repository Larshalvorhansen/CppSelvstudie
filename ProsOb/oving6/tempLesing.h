#pragma once
#include "std_lib_facilities.h"

class Temp{
    map<float,float> data;
    private:
        float max;
        float min;
    public:
        friend istream& operator>>(istream& is, Temp& t);
}
    map<float, float> temp(string fileName);