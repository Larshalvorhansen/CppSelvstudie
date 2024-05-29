#include "intermezzo.h"
#include "std_lib_facilities.h"
// 3a: Alle dummy-objektene vil først få verdien 4, så 3, så 5 fordi de referer til samme minneadresse. Deror skrives først 4, så 5.

void dummyTest(){
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c=a;
    cout << "a: " << *a.num << "\n";
    cout << "b: " << *b.num << "\n";
    cout << "c: " << *c.num << "\n";

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << "\n";
    cout << "b: " << *b.num << "\n";
    cout << "c: " << *c.num << "\n";
}

Dummy::Dummy(const Dummy &dummy){
    num = new int{*dummy.num};
}

// Dummy::operator = (Dummy &dummy){
//     num = new int{*dummy.num};
//     return *this;
// }