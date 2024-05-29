#pragma once
#include "std_lib_facilities.h"

class Dummy
{
public:
    int *num;
    Dummy()
    {
        num = new int{0};
    }
    ~Dummy()
    {
        delete num;
    }
};

void dummyTest();