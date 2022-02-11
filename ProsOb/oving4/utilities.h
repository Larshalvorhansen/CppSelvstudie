#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(struct Student);

void swapNumbers(int a, int b);

bool isInProgram(struct Student, string studieprogramm);

string randomizeString(int antallTegn, char ovreChar, char nedreChar);

string readInputToString(char ovreChar, char nedreChar);

int countChar(string streng, char c);