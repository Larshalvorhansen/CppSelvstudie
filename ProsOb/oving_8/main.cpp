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

void fillInFibonacciNumbers(int* result, int length){
	for (int i = 0; i < length; i++){
		if (i==0)
		{
			result[i] = 0;
		}else if (i == 1)
		{
			result[i] = 1;
		}else
		{
			result[i] = result[i-1]+result[i-2];
		}
	}
}

void printArray(int* arr, int length){
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << "\n";
	}
}


void createFibonacci(){
	int length;
	cout << "How many numbers do you want generated? \n";
	cin  >> length;

	int* newArr = new int[length] {};

	fillInFibonacciNumbers(newArr, length);
	printArray(newArr, length);

	delete[] newArr;
	newArr = nullptr;
}


//------------------------------------------------------------------------------
int main(){
	createFibonacci();
	Matrix A(3, 2);
	cout << A;
	Matrix B(2);
	B.set(0, 0, 1);
	B.set(0, 1, 2);
	B.set(1, 0, 3);
	B.set(1, 1, 4);	
	Matrix C(2);
	cout << C;
	cout << B;
	cout << B.get(1, 1);
	cout << "\n";
	cout << A;
	dummyTest();
}

//------------------------------------------------------------------------------
