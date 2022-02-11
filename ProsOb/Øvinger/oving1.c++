#include <iostream>
using namespace std;


int maxOfTwo(int a, int b) {
    if(a>b) {
        cout << "A is greater than B" << endl;
        return a;
    }
    else {
        cout << "B is greater to A" << endl;
        return b;
    }
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:" << "\n";
    for (int x = 1; x <= n+1; x++) {
        cout << x << " " << b << "\n";
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << "\n";
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 0; i <= n; i++) {
        totalSum += i*i;
        cout << totalSum << endl;
        return totalSum;
    }
}

int triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below" << endl;
    while(acc < n) {
        acc += num; 
        num ++;
    }
    return num;
}
    
int isPrime(int n) {
    for(int j = 2; j<n; j++) {
        if((n % j) == 0) {
            return(false);
        }
    }
    return(true);
}

int naivePrimeNumberSearch(int n) {
    for(int number = 2; number<=n; number ++) {
        if(isPrime(number)) {
            cout << number << " is a prime" << endl;
        }
    }
}

int findGreatestDivisor(int n) {
    for(int divisor = n-1; divisor >= 0; divisor--) {
        if((n % divisor) == 0) {
            return divisor;
        }
    }
}

int main () {
    cout << "Oppgave a) \n";
    cout << maxOfTwo(2,4) << "\n";

    cout << "Oppgave c) \n";
    cout << fibonacci(30) << "\n";

    cout << "Oppgave d) \n";
    cout << squareNumberSum(14) << "\n";
    
    cout << "Oppgave e) \n";
    cout << triangleNumbersBelow(301) << "\n";
     
    cout << "Oppgave f) \n";
    cout << isPrime(2047) << "\n";
    
    cout << "Oppgave g) \n";
    cout << naivePrimeNumberSearch(284);

    cout << "Oppgave h) \n";
    cout << findGreatestDivisor(70245181); //21856*3214

    if(true>false){
        cout << "hei\n";
    }
} 