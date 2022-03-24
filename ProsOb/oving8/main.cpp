//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "stdlib.h"
#include "string"
#include "stdio.h"
#include "cassert"
#include "memory"
#include "std_lib_facilities.h"
#include "matrix.h"
#include "intermezzo.h"


//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

void fillInFibonacciNumbers(int *resultm, int length)
{
	int x1 = 0;
	int x2 = 1;
	int x3 = 0;
	for (int i = 0; i < length; i++)
	{
		resultm[i] = x1;
		x3 = x2;
		x2 = x1 + x2;
		x1 = x3;
	}
}

void printArray(int *arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ", ";
	}
}

void delete_matrix(int *matrix)
{
	delete[]matrix;
}

void createFibonacci()
{
	int antallTall;
	cout << "Hvor mange fibonaccitall ønsker du å genrere? " << '\n';
	cin >> antallTall;
	int *potet = new int[antallTall];
	fillInFibonacciNumbers(potet, antallTall);
	printArray(potet, antallTall);
	delete_matrix(potet);
}

int *create_matrix(int rows, int columns)
{
	int *Matrix = new int[rows * columns]{};
	return Matrix;
}

void test()
{
	cout << "test" << endl;
}

void test2()
{
	int i, n;											 // lager i og n
	int *p;												 // definerere pointeren p
	cout << "How many numbers would you like to type? "; // spør om input
	cin >> i;											 // legger inn input inni i
	p = new (nothrow) int[i];							 // Lager en liste med ints?
	for (n = 0; n < i; n++)
	{ // løkke som skriver inn tall i p for hvert element i
		cout << "Enter number: ";
		cin >> p[n];
	}
	cout << "You have entered: ";
	for (n = 0; n < i; n++) // løkke som skriver ut tall i p for hvert element i
		cout << p[n] << ", ";
	delete[] p; // sletter minnet til p
}

int main()
{
	cout << "Hello, World!\n";
	// test();
	// fillInFibonacciNumbers(10);
	// int x = 2;
	// cout << &x << endl;
	createFibonacci();
	// test2();
	//  delete_matrix();
}

//------------------------------------------------------------------------------'