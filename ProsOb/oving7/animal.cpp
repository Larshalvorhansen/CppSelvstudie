#include "animal.h"

string Animal::toString(string name, int age){
    return("Animal: " + name + to_string(age));
}

string Cat::toString(string name, int age){
    Cat cat(name,age);
    return("Cat: " + name + to_string(age));
}

string Dog::toString(string name, int age){
    Dog dog(name,age);
    return("Dog: " + name + to_string(age));
}

void testAnimal(){
    Cat myCat{"jørghen", 10};
    std::vector<std::unique_ptr<Animal>>;
}

Cat::Cat(string name, int age): Animal{name, age}{}
Dog::Dog(string name, int age): Animal{name, age}{}

