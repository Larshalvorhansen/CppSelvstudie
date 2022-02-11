//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main(){
    int choice = -1;
    while (choice != 0){
        cout << "0) Avslutt \n"
             << "1) testCallByValue\n";
        cout << "Angi valg (0-11): ";

        cin >> choice;
        cout << '\n';

		Student Per{"Per","Emil",23};
		Student Nils{"Nils","Fysmat",22};
        switch (choice){
			case 0:
				break;
			case 1:
				testCallByValue(5,2,10,25);
				break;
			case 2:
				testCallByReferance(5,2,10,25);
				break;
			case 4:
				printStudent(Per);
				break;
			case 5:
				isInProgram(Nils, "Fysmat");
				break;
			case 6:
				swapNumbers(3,5);
				break;
			case 7:
				randomizeString(50,122,65);
				break;
			case 8:
				testString("Hei", 66);
				break;
			case 9:
				readInputToString(70,65);
				break;
			case 10:
				countChar("HHHHahfdbaaaHei",97);
				break;
			case 11:
				playMastermind();
				break;
		}
	}
}

//------------------------------------------------------------------------------
/*
Oppgave 1a) 25 blir verdien for v0
Oppgave 1e) Har vel ikke noe å si om den bruker ref eller ikke ettersom det går helt fint med et nytt variabel c
Oppgave 2e) utilities.h skal/trenger ikke inkluderes i main når main inkluderer rests.h som igjen inkluderer utilities.h.
også burde det stå "#pragma once" i h filen

Spørsmål til studas:
Hvordan og hvorfor er det nyttig å implementere referanse i testCallByRef?
*/

