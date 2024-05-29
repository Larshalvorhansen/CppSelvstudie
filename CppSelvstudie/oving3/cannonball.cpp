#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"

double acclY(){
    double aY = -9.81;
    return(aY);
}

double velY(double initVelocity, double time){
    double iVY = initVelocity + acclY() * time;
    return(iVY);
}

double posX(double initPosition, double initVelocity, double time){
    double pX = initPosition + initVelocity * time;
    cout << pX << endl;
    return(pX);
}//her har jeg bare med acclY fordi det er den eneske akselerasjonen som virker på ballen

double posY(double initPosition, double initVelocity, double time){
    double pY = initPosition + initVelocity * time + (acclY()*time*time)/2;
    return(pY);
}

void printTime(double time){
    int hour = floor(time/(60*60));
    int minutes = floor((time-hour*60*60)/60);
    int remainingSeconds = time-hour*60*60-minutes*60;
    cout << hour << " time " << minutes << " minutt" << " og " << remainingSeconds << " sekund " << endl;
}

double fligthTime(double initVelocity){
    double fTime = (-2*initVelocity)/acclY();
    return(fTime);
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if(compareOperand <= toOperand+maxError && compareOperand >= toOperand-maxError){
        cout << name << " within errormargin" << endl;
        cout << compareOperand << '\t' << toOperand << endl;
    }
    else{
        cout << name << " OUTSIDE ERRORMARGIN" << endl;
        cout << compareOperand << '\t' << toOperand << endl;
    }
}

double getUserInputTheta(){
    double vinkel = 0.0;
    cout << "skriv inn en vinkel her" << endl;
    cin >> vinkel;
    return(vinkel);
}

double getUserUnputAbsVelocity(){
    double absoluttfart = 0.0;
    cout << "skriv inn en absoluttfart her" << endl;
    cin >> absoluttfart;
    return(absoluttfart);
}

double degToRad(double deg){
    double rad = deg*3.14159/180;
    return(rad);
}

double getVelocityX(double theta, double absVelocity){
    double vX = cos(degToRad(theta)) * absVelocity;
    return(vX);
}

double getVelocityY(double theta, double absVelocity){
    double vY = sin(degToRad(theta)) * absVelocity;
    return(vY);
}

vector<double> getVelocityVector(double theta, double absVelocity){
    double vX = getVelocityX(theta, absVelocity);
    double vY = getVelocityY(theta, absVelocity);
    vector<double> vVec {vX, vY};
    return vVec;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double distance = fligthTime(velocityY)*velocityX;
    return(distance);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double avvik = abs(distanceToTarget - getDistanceTraveled(velocityX,velocityY));
    cout << avvik << "  " << distanceToTarget << endl;
    return(avvik, distanceToTarget);
}

bool checkIfDistanceToTargetIsCorrect(){
    double error = targetPractice(0,0,0);
    if(error == 0) {
        return true;
    }
    return false;
}//funksjonen var ikke så bra fordi den returnerte bare hvis det ikke var en error. Hvis det bar en error så returnerte den ingenting dermed la kjeg til "return false"

void playTargetPractice(){
    int blinkPlassering = randomWithLimits(1000,100);
    int vinkel = 0;
    int startfart = 0;
    
    for(int i = 0; i<=10; i++){
        cout << "Oppgi vinkel" << endl;
        cin >> vinkel;
        cout << "Oppgi startfart" << endl;
        cin >> startfart;
        int avstandDratt = getDistanceTraveled(getVelocityX(vinkel,startfart),getVelocityY(vinkel,startfart));
        cout << "avstandDratt" << avstandDratt << endl;
        int avstandFraBlink = abs(avstandDratt-blinkPlassering);
        cout << "avstandFraBlink" << avstandFraBlink << endl;
        if(avstandFraBlink<=5){
            cout << "grattulerer du traff" << endl;
            break;
        }
        else if(avstandFraBlink >= 5){
            cout << "Prøv igjen. Du har " << 10-i << " forsøk igjen." << endl;
        }
    }
}

void cannonBallViz(double targetPosition, int fieldLength,
double velocityX,double velocityY,
int timeSteps);