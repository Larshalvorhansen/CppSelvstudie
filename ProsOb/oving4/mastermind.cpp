#include "mastermind.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void playMastermind(){
    //constexpr er brukt her fordi vi skal ha en konstant funksjon og ikke et konstant variabel
    constexpr int size = 4;
    constexpr int letters = 6;
    int forsok = 0;

    string code = "";
    string guess = "";
    code = randomizeString(4,65+(letters-1),65);
    while (guess != code || forsok <= 10){
        guess = readInputToString(65+(letters-1),65);
        int svartKnott = checkCharactersAndPosition(code,guess);
        int hvitKnot = checkCharacters(code,guess);
        cout << "Antall hvite knotter: " << hvitKnot << ". Antall svarte knotter: " << svartKnott << endl;
        forsok ++;
        if(svartKnott == letters-1){
            break;
        }
    }
    if(forsok <= 10){
        cout << "Grattulerer du har gjetttet riktig!" << endl;
    }
    else{
        cout << "Du er deverre tom for forsøk. Bedre lykke neste gang" << endl;
    }
}

int checkCharactersAndPosition(string code, string guess){
    int teller = 0;
    for(int i = 0; i <= 4; i++){
        if(code[i]==guess[i]){
            teller++;
        }
    }
    return(teller);
}

int checkCharacters(string code, string guess){
    int teller = 0;
    for(int i = 0; i <= 4; i++){
        if(code[i] == guess[1] || code[i] == guess[2] || code[i] == guess[3] || code[i] == guess[4]){
            teller++; 
        }
    }
    return(teller);
}

/*
ADFA
AGDS
*/