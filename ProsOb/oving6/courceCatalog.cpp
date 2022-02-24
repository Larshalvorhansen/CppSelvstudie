#include "std_lib_facilities.h"
#include "courceCatalog.h"

void CourseCatalog::addCourse(){ //legg til et kurs med emnekode og emnenavn.
    string emnekode = "";
    string emnenavn = "";
    cout << "legg til kurs" << endl;
    cout << "Emnekode: " << endl;
    cin >> emnekode;
    cout << "Emnenavn: " << endl;
    cin >> emnenavn;
    fag.insert({emnenavn,emnekode});
} 

void CourseCatalog::removeCourse(){ //fjern et kurs gitt av emnekoden.
    string fjerne = "";
    cout << "skriv inn kursjet du vil fjerne: " << endl;
    cin >> fjerne;
    fag.erase(fjerne);
} 

string CourseCatalog::getCource(){ //finn emnenavnet til et kurs med en gitt emnekode
    string emnenavn;
    cout << "skriv inn emnekode for å finne det tilhørende emnenavnet: ";
    cin >> emnenavn;
    return(fag.key_comp(emnenavn));
} 
