#pragma once
#include "std_lib_facilities.h"
#include "tests.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int a, int b);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(struct Student);

bool isInProgram(Student student, string studie);

string randomizeString(int lengde, char ovreGrense, char nedreGrense);

int countChar(string streng, char bokstav);