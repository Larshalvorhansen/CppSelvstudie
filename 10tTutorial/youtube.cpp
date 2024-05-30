#include <iostream>
#include <cmath>
using namespace std;

double power(double base, int exponent)
{
    double result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result = result * base;
    }
    return result;
}

void print_pow(double base, int exponent)
{
    double my_power = power(base,exponent);
    cout << base << " raised to the " << exponent << " power is: " << my_power << "." << endl;
}

int main()
{
    int base, exponent;
    cout << "Insert base ";
    cin >> base;
    cout << "Insert exponent ";
    cin >> exponent;
    print_pow(base, exponent);
}
