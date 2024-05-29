#include "cannonball.h"
#include "std_lib_facilities.h"


double acclY(){
    return -9.81;
}

double velY(double initVelocity, double time){
    return initVelocity + acclY()*time;
}

double posX(double initPosition, double initVelocity, double time){
    return initPosition+initVelocity*time;
}

double posY(double initPosition, double initVelocity, double time){
    return initPosition+initVelocity*time+(acclY()*time*time)/2;
}

void printTime(double time){
    int h = floor(time/(60*60));
    int m = floor((time-h*60*60)/60);
    double s = time-h*60*60-m*60;
    cout << "tid: " << h << " timer " << m << " minutter og " << s << "sekunder" << endl;
}

double fligthTime(double initVelocity){
    return (-2*initVelocity)/acclY();
}

double getUserInputTheta(){
    double Theta;
    cout << "Skriv inn en vinkel her "<< endl;
    cin >> Theta;
}

double getUserInputAbsVelocity(){
    double absVelocity;
    cout << "Skriv inn en fart her "<< endl;
    cin >> absVelocity;
}

double degToRad(double deg){
    return (deg/180)*M_PI;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(degToRad(theta));
}
double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(degToRad(theta));
}

// double getVelocityVector(double theta, double absVelocity){
//     getVelocityX(theta, absVelocity);
//     getVelocityY(theta, absVelocity);
// }
//vector<double> getVelocityVector(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity)
{
	vector<double> velocityVector;

	velocityVector.push_back(getVelocityX(theta, absVelocity));
	velocityVector.push_back(getVelocityY(theta, absVelocity));
	return velocityVector;

	// Alternativt:
	// return {
	// 	getVelocityX(theta, absVelocity),
	// 	getVelocityY(theta, absVelocity)
	// };
}