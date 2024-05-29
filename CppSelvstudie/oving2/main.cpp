#include "std_lib_facilities.h"
// #include "Graph.h" 
// #include "AnimationWindow.h" 
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

/*double calculateBalance(int rente, int antalAar){
    
    //return()
}*/

int pytagoras(int a, int b){
    AnimationWindow win{100, 100, 500, 500, "Pythagoras"};

    Point point1 = {100,100};
    Point point3 = {100,200};
    Point point2 = {300,200};

    win.draw_triangle(point1, point2, point3, Color::red);

    win.draw_quad(point1, Point{0,100}, Point{0,200}, point3, Color::green);
    win.draw_quad(point3, Point{100,400}, Point{300,400}, point2, Color::blue);
    win.draw_quad(Point{100,100}, point1, Point{400,100}, point2, Color::blue);

    win.wait_for_close();
    return(sqrt(pow(a,2)+pow(b,2)));
}

int calculateBalance(double innskudd, double rente, int aar){
    cout << "År" << '\t' << "Saldo" << endl;
    vector<double> t(aar); // 10 int av verdien 0
    for(int i = 0; i < aar; i++){
        t[i] = innskudd * (pow((1.0+rente/100.0),aar));
        cout << aar << '\t' << t[i] << '\n';
    }
}

int calculateBalanceWithoutVectors(int innskudd, int rente, int aar){
    for(int i = 0; i <= aar; i++){
        int sum = innskudd * (pow((1.0+rente/100.0),i));
        cout << sum << endl;
    }
}

int main(){
    // int sumOfOneAndTwo = add(1, 2);
    // cout << "1 + 2 = " << sumOfOneAndTwo << "\n";
    // cout << "2 + 2 = " << add(2, 2) << "\n";
    //inputIntegerAndPrintProduct();
    //inputAndPrintInteger();
    //inputIntegersAndPrintSum();
    //isOdd();
    //printHumanReadableTime(3662);
    //solveQuadraticEquation();
    //pytagoras(1,2); //Fungerte i starten men får nå verken utskrift eller feilmelding, men heller en redirect til @_cxa_throw linje tre
    //calculateBalanceWithoutVectors(10000,2,5);
    //calculateBalance(10000,2,5);
    // for(int i = 0; i<=5; i++){
    //     cout << pow((1.0+2.0/100.0),i) << endl;
    // }
    // vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (int i = 0; i <= v.size(); i++) {
    //     cout << v[i] << endl;
    // }
}

/*Oppgave 6c)
Feilein skjer noen ganger fordi man ikke har inkludert string (#include <string>) øverst i programmet

Oppgave 6d) jeg får ingen feilmelding og utskriften er 1, 2, 3, 4, 5, 6, 7, 8, 9, 0.

/* Teori
d) jeg brukte inputAndPrintInteger fordi jeg hadde ikke funksjonen; inputInteger.
*/

/* Spørsmål til studass
Hvorfor funker ikke flertall greia i HumanReadableTime greia?
*/

