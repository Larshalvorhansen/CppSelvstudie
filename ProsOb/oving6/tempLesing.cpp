#include "tempLesing.h"

istream& operator>>(istream& is, Temps& t){
        is >> t.max >> t.min; 
        return is;
    }

vector<Temps> readTemps(string filename){
    ifstream inf{filename};

    if(!inf){
        cerr << "Could not find file of name: " << filename;
    }

    Temps t;
    vector<Temps> tempsV;

    while(inf>>t){ //varer så lenge det står noe i Temps
        tempsV.push_back(t);
    }
    return(tempsV);
}

void tempStats(vector<Temps> T){
    float maks = -300;
    float min = 300;
    int indeksMin;
    int indeksMax;
    for(int i = 0; i < T.size(); i++){
        if(T[i].max > maks){
            maks = T[i].max;
            indeksMax = i;
        }
        if(T[i].min < min){
            min = T[i].min;
            indeksMin = i;
        }
    }
    cout << "Dag " << indeksMax+1 << " hadde høyest temperatur. Da var temperaturen " << maks << endl;
    cout << "Dag " << indeksMin+1 << " hadde lavest temperatur. Da var temperaturen " << min << endl;
}