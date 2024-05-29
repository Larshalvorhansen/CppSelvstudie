#include "tests.h"

void testCallByValue(int v0, int increment, int iterations, int expectedResult){
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result
         << " expected result: " << expectedResult << endl;
    if(result == expectedResult){
        cout << "Results as ecpected" << endl;
    }
    else{
        cout << "Results not as expected" << endl;
    }
}

void testCallByReferance(int v0, int increment, int iterations, int expectedResult){
    incrementByValueNumTimesRef(v0, increment, iterations);
    int result = v0;
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result
         << " expected result: " << expectedResult << endl;
    if(result == expectedResult){
        cout << "Results as ecpected" << endl;
    }
    else{
        cout << "Results not as expected" << endl;
    }
}

void testString(string word, char letter){
    string grades = randomizeString(8,70,65);
    cout << grades << endl;
    vector<int> gradeCount;
    for(int i = 0; i <= grades.length(); i++){
       //gradeCount.push_back (grades,65+i);
    }
    //cout << gradeCount << endl;
}