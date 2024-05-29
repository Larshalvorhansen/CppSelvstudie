#pragma once
#include "std_lib_facilities.h"

class Person{
    private:
        string name;
        string email;
        unique_ptr<string> car;
    public: 
        Person(string name, string email):name(name),email(email){};
        bool hasAvalibleSeats(unique_ptr<string> car);
};