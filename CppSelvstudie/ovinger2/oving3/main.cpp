#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

// void testDeviation(double compareOperand, double toOperand, double maxError, string name){
//     double error = abs(compareOperand-toOperand);
//     if (error>maxError)
//     {
//         cout << "Error exeeds maxError. Error= " << error << "." << endl;
//     }
//     else{
//         cout << "Error is withinn maxError. Error= " << error << "." << endl;
//     }
// }

bool checkIfDistanceToTargetIsCorrect() {
    double error = targetPractice(0,0,0);
    if(error == 0) {return true;}
    else {return false;}
    }

int main(){
    // cout << acclY() << endl;
    // cout << velY(234,234) << endl;
    // cout << posX(32,23,43) << endl;
    // cout << posY(6,4,42) << endl;
    // printTime(13456654.7);
    // cout << fligthTime(3) << endl;
    // testDeviation(34.5,34.543456,0.1,"hei");
    // cout << targetPractice(10,2,30) << endl;
    //checkIfDistanceToTargetIsCorrect();
    srand(unsigned(time(nullptr)));
    playTargetPractice();
}
