#pragma once
#include "std_lib_facilities.h"

class Animal{
    protected:
        string name;
        int age;
    public:
        Animal(string name = "", int age = 0);
        virtual ~Animal(){}
        virtual string toString(string name, int age) = 0; //når det står = 0 blir det pure viritual
        //virtual string toString(string name, int age)=0; slik?
};

class Cat : public Animal{
    public:
    Cat(string name = "", int age = 0);
    string toString(string name, int age);
};

class Dog: public Animal{
    public:
    Dog(string name = "", int age = 0);
    string toString(string name, int age);
};

void testAnimal();