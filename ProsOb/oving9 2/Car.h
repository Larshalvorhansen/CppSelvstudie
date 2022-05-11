#pragma once
#include "std_lib_facilities.h"

class Car{
	private:
		int freeSeats;
	public:
		Car(int freeSeats):freeSeats{freeSeats}{};
		bool hasFreeSeats(int freeSeats) const;
		void reserveFreeSeats();
};
