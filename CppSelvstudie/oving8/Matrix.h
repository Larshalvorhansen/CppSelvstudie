#pragma once
#include "std_lib_facilities.h"

class Matrix{
    public:
        double rows;
        double collumns;
        Matrix(int nRows, int nColumns);
        explicit Matrix(int nRows);
};

