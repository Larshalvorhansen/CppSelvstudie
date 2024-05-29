#include "Car.h"

bool Car::hasFreeSeats(int freeSeats) const
{
    if (freeSeats > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}