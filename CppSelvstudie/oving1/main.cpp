//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

//#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

#include <iostream>
#include <cmath>
//#include "Graph.h" 
//#include "AnimationWindow.h" 
using namespace std;

int add(int a, int b){
    return a + b;
}

void inputIntegerAndPrintProduct(){
    int x = 0;
    int y = 0;

    cout << "Skriv inn to heltall: ";
    cin >> x;
    cin >> y;
    
    int product = x * y;
    cout << x << " * " << y << " = " << product << "\n";
}

int inputAndPrintInteger(){
    int a = 0;
    cout << "Skriv et tall " << endl; 
    cin >> a;
    cout << "Ditt tall er " << a << endl ;
    return a;
}

int inputIntegersAndPrintSum(){
    int a = inputAndPrintInteger();
    int b = inputAndPrintInteger();
    cout << "Summen er " << add(a,b) << endl;
}

bool isOdd(){
    int a = inputAndPrintInteger();
    if(a % 2 == 0){
        cout << "false";
        return true;
    }
    else{
        cout << "true";
        return false;
    }
}

int printHumanReadableTime(int sekunder){
    int timer = floor(sekunder/(60*60));
    int minutter = floor((sekunder-timer*60*60)/60);
    int restSekunder = sekunder-timer*60*60-minutter*60;
    string ftT, ftM, ftS= "";
    if(timer > 1){
        string ftT = "r";
    }
    if(minutter > 1){
        string ftM = "r";
    }
    if(restSekunder > 1){
        string ftS = "r";
    }
    cout << timer << " time " << ftT << minutter << " minutt" << ftM << " og " << restSekunder << " sekund " << ftS << endl;
}

int discriminant(double a, double b, double c){
    return(b*b-(4*a*c));
}

double printRealRoots(double a, double b, double c){
    if(discriminant(a, b, c) < 0){
        cout << "Ingen reelle løsninger" << endl;
    }
    else if (discriminant(a, b, c)){
        cout << "Løsningene blir: " << "x=" << (-b+sqrt(discriminant(a,b,c)))/(2*a) << endl;
        cout << "og " << "x=" << (-b-sqrt(discriminant(a,b,c)))/(2*a) << endl;
    }
    else if (discriminant(a,b,c) == 0){
        cout << "Løsningen blir: " << "x=" << -b/(2*a) << endl;
    }
}

double solveQuadraticEquation(){
    double a,b,c = 0;
    cout << "skriv tre desimaltall her. Først a, så b, så c. "; 
    cin >> a;
    cin >> b;
    cin >> c;
    printRealRoots(a,b,c);
}

/* Forstod ikke helt dette med å skrive ut til vindu
double pytagoras(){

}
AnimationWindow win{100,100, w, h, "Pythagoras"};
win.wait_for_close();
*/



int calculateBalance(int inskudd, int rente, int antalAar){
    return(pow(inskudd*(1+rente/100),antalAar));
    cout << (pow(inskudd*(1+rente/100),antalAar)) << endl;
    //return();
}

int main(){
    //int sumOfOneAndTwo = add(1, 2);
    //cout << "1 + 2 = " << sumOfOneAndTwo << "\n";
    //cout << "2 + 2 = " << add(2, 2) << "\n";
    //inputIntegerAndPrintProduct();
    //inputAndPrintInteger();
    //inputIntegersAndPrintSum();
    //isOdd();
    //printHumanReadableTime(3662);
    //solveQuadraticEquation();
    calculateBalance(5,4,2);
}

/* Teori
d) jeg brukte inputAndPrintInteger fordi jeg hadde ikke funksjonen; inputInteger.
*/

/* Spørsmål til studass
Hvorfor funker ikke flertall greia i HumanReadableTime greia?

*/

//------------------------------------------------------------------------------
