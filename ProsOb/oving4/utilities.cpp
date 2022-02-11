#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

void swapNumbers(int a, int b){
    int c = a;
    a = b;
    b = c;
    cout << "a = " << a << " b = " << b << endl;
}

void printStudent(Student student){
    string navn = student.name;
    string studieprogram = student.studyProgram;
    int alder = student.age;
    cout << navn << '\t' << studieprogram << '\t' << alder << endl;
    // cout << "Skriv studieprogram til student: " << endl;
    // cin >> Student.studyProgram
    // cout << "Skriv alder på student: " << endl;
    // cin >> Student.age
    // cout << Student.name << " " << Student.studyProgram << Student.age << endl;
};

bool isInProgram(Student student, string studieprogramm){
    string studyProgram = student.studyProgram;
    if(studyProgram == studieprogramm){
        return(true);
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
        return(false);
    }
    cout << "test" << endl;
}

string randomizeString(int antallTegn, char ovreChar, char nedreChar){
    int range = abs(ovreChar - nedreChar)+1;
    string streng = "";
    for(int i = 0; i <= antallTegn; i++){
        streng += (nedreChar + (rand() % range));
    }
    cout << streng << endl;
    string grades = streng;
    return(streng);
}

// int countChar(string word, char letter){
//     int charCount = 0;
//     for(int i=0;i<word.length();i++){
//         if(word[i]==letter){
//             charCount++;
//         }
//     }
//     return(charCount);
// }

string readInputToString(char ovreChar, char nedreChar){
    string streng = "";
    cout << "Skriv inn en streng med fire tegn mellom " << nedreChar << " og " << ovreChar << "." << endl;
    cin >> streng;
    int n = streng.length();
    for(int i = 0; i < n; i++){
        char t = tolower(streng[i]);
        if(t > tolower(ovreChar) || t < tolower(nedreChar)){
            cout << "Du har en eller flere bokstaver utenfor grensen. Prøv igjen." << endl;
            break;
        }
    }
    return(streng);
}

int countChar(string streng, char c){
    int antallForekomster = 0;
    for(int i = 0; i < streng.length(); i++){
        char t = streng[i];
        if(t==c){
            antallForekomster++;
        }
    }
    cout << antallForekomster << endl;
    return(antallForekomster);
}