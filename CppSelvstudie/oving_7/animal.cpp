#include "animal.h"

string Animal::toString(){
    return("Animal: "+name+" "+to_string(age));
}
string Cat::toString() {
    return("Animal: "+name+" "+to_string(age));
}

string Dog::toString() {
    return("Animal: "+name+" "+to_string(age));
}

void testAnimal(){
    Animal a {31, "Torstein"};
    Cat c {42, "Fredrik"};
    Dog d {12, "Perro"};

    vector<unique_ptr<Animal>> vek;
    vek.emplace_back(new Animal{42, "Fredrik"});
    vek.emplace_back(new Cat {31, "Torstein"});
    vek.emplace_back(new Dog{12, "Perro"});
    for (int i = 0; i < vek.size(); i++){//gjør om elementene i vektoren til string
        
        cout << vek[i]->toString() << endl;
        
    }
}
