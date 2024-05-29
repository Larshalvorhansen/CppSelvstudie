#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"

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

double flightTime(double initVelocity){
    return (-2*initVelocity)/acclY();
}

double getUserInputTheta(){
    double Theta;
    cout << "Skriv inn en vinkel her "<< endl;
    cin >> Theta;
    return Theta;
}

double getUserInputAbsVelocity(){
    double absVelocity;
    cout << "Skriv inn en fart her "<< endl;
    cin >> absVelocity;
    return absVelocity;
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

double getDistanceTraveled(double velociyX, double velocityY){
    return flightTime(velocityY)*velociyX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return getDistanceTraveled(velocityX,velocityY)-distanceToTarget;
}

void playTargetPractice(){
    int blinkPos = randomWithinLimits(1000,100);
    int j;
    for (int i = 0; i < 10; i++)
    {
        double vinkel = getUserInputTheta();
        double fart = getUserInputAbsVelocity();
        double avstandFraBlink = targetPractice(blinkPos,getVelocityY(vinkel,fart),getVelocityY(vinkel,fart));
        cannonBallViz(blinkPos,1000,getVelocityX(vinkel,fart),getVelocityY(vinkel,fart),100);
        if(abs(avstandFraBlink)<=5){
            cout << "Gratulerer du traff!";
            break;
        }
        else if(avstandFraBlink<0){
            cout << "Skuddet var litt for kort. Avstand fra blink er " << abs(avstandFraBlink) << endl;
        }
        else if(avstandFraBlink>0){
            cout << "Skuddet var litt for langt. Avstand fra blink er " << avstandFraBlink << endl;
        }
        j=i;
    }
    if(j==9){cout << "Du tapte desverre.";}
}