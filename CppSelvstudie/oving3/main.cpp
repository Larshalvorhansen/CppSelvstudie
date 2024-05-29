//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
//------------------------------------------------------------------------------'
double maxError = 0.1;
// C++ programs start by executing the function main
int main()
{
	// cout << "Hello, World!\n";
	// testDeviation(posX(0,50,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
	// testDeviation(posY(0.0,25,5.0), 2.375, maxError, "posY(0.0,50.0,5.0)");
	// testDeviation(velY(0.0,50.0), 250.0, maxError, "velY(0.0,50.0,5.0)");
	// testDeviation(fligthTime(3.0), 58.86, maxError, "fligthTime(3.0, 58.86)");
	// testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
	// targetPractice(3.0,3.4,214.0);
	// checkIfDistanceToTargetIsCorrect();
	// srand(unsigned(time(nullptr)));
	// for (int i = 0; i < 100; i++){
	// 	randomWithLimits(60,20);
	// }
	playTargetPractice();
	
}
//------------------------------------------------------------------------------
