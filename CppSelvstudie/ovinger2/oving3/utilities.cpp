#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithinLimits(int upperLimit, int lowerLimit){
	return rand() % (upperLimit-lowerLimit) + lowerLimit;
}