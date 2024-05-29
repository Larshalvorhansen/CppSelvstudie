#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int valg=1;
	cout << "Skriv inn et tall for koden du vil kjøre.\nSkriv 0 for å avslutte\n";
	while (valg!=0)
	{
		cin >> valg;
		switch (valg)
		{
			case 1:
				playMastermind();
				break;
			case 2:
				cout << randomizeString(7,'A','J');
				break;
			case 6:
				testCallByValue();
				break;
			case 3: 
				cout << countChar("bolle",'l') << endl;
				break;
			case 4:
				testString();
				break;
			case 5:
				Student Hei {"Lars","Elsys", 21};
				printStudent(Hei);
				cout << isInProgram(Hei,"Indøk");
				break;
		}
	}
}

//------------------------------------------------------------------------------
