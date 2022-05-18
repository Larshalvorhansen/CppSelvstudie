#include "std_lib_facilities.h"

int main(){
    int* ptr;
    int var = 8;
    int var2 = 15;
    ptr = &var;
    cout << ptr << endl;
    ptr = &var2;
    cout << ptr << endl;
    int& ref = var;
    cout << var << endl;
    cout << var2 << endl;
}