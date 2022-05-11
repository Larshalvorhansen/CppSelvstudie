#pragma once
#include "utilities.h"
#include "std_lib_facilities.h"

double acclY();

double velY(double initVelocity, double time);

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double fligthTime(double initVelocity);

double getUserInputTheta();

double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velociyX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);