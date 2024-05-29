#include "skrivTilFil.h"

void writeToFile(){
    string write;
    cout << "What do you want to write to file?" << endl;
    ofstream fil;
    fil.open("boat.txt");
    cin >> write;
    while (write!="quit")
    {
        fil << write+"\n";
        cin >> write;
    }
    fil.close();
}

void readAndWrite(){
    ifstream fil2;
    fil2.open("boat.txt");
    fil2.close();
    
}