#pragma once
#include "std_lib_facilities.h"

double acclY();
 
double velY(double initVelocity, double time);

double posX(double initPosition, double initVelocity, double time);

double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double fligthTime(double initVelocity);

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

double getUserInputTheta();

double getUserUnputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);

double getVelocityY(double theta, double absVelocity);

vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

bool checkIfDistanceToTargetIsCorrect();

void playTargetPractice();