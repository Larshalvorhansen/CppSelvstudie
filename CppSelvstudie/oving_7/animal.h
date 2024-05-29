#include "std_lib_facilities.h"
//protected kan brukes av subklasser
class Animal{
    protected:
        string name;
        int age; 
    public:
        virtual string toString();
        virtual~Animal() {}
        Animal(int age, string name): name{name}, age{age}{}
};

class Cat :public Animal
{
public:
    string toString() override;
    Cat(int age, string name): Animal{age, name}{}
};

class Dog : public Animal
{
public:
    string toString() override;
    Dog(int age, string name): Animal{age, name}{}
};

void testAnimal();