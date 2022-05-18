#include "utilities.h"
#include "tests.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int &startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

void swapNumbers(int a, int b){
    int c;
    c = a;
    b = a;
    b = c;
    //Referance hermer etter variabelet som det refererer til. 
    //DVS hvis det andre variabelet endrer seg så endrer også referansen seg.
}

void printStudent(Student student){
    cout << "Name: " << student.name << "\nStudy program: " << student.studyProgram << "\nAge: " << student.age << "\n";
}

bool isInProgram(Student student, string studie){
    if(student.studyProgram==studie){
        return true;
    }
    else{
        return false;
    }
}

string randomizeString(int lengde, char ovreGrense, char nedreGrense){
    string j; 
    for (int i = 0; i < lengde; i++){
        if(ovreGrense<=nedreGrense){
            j+= rand() % abs(nedreGrense-ovreGrense) + ovreGrense;
        }
        else{
            j+= rand() % abs(nedreGrense-ovreGrense) + nedreGrense;
        }
    }
    return j;
}

int countChar(string streng, char bokstav){
    int count = 0;
    for (int i = 0; i < streng.length(); i++)
    {
        if (streng[i]==bokstav)
        {
            count++;
        }
    }
    return count;
}