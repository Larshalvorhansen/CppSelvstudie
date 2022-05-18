#include "tests.h"
#include "std_lib_facilities.h"
#include "utilities.h"

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
    if(result==25){
        cout << "funksjonen fungerer\n";
    }
    else{
        cout << "funksjonen fungerer ikke\n";
    }
}

void testCallByReferance(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
    if(result==25){ 
        cout << "funksjonen fungerer\n";
    }
    else{
        cout << "funksjonen fungerer ikke\n";
    }
}

void testString(){
    string grades = "AAABCCCCDEEEEEFFFFFFFFF";
    vector<int> gradeCount(6);
    double sum = 0;
    for (int i = 0; i < 6; i++){
        gradeCount[i]=(countChar(grades,'A'+i));
        cout << static_cast<char>('A'+i) << " " << gradeCount[i] << endl;
        sum += gradeCount[i];
    }
    cout << "gjennomsnitt: " << sum/6 << endl;;
}