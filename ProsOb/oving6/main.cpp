
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup

// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "courceCatalog.h"
#include "tempLesing.h"

void writeToFile(){
	ofstream outFile {"fil.txt"};
	string Ord;
	cin >> Ord;
	outFile << "Hello world! " + Ord << endl;
	string Ord2;
	cin >> Ord2;
	outFile << "Hello world! " + Ord2 << endl;
	string Ord3;
	cin >> Ord3;
	outFile << "Hello world! " + Ord3 << endl;
	string Ord4;
	cin >> Ord4;
	outFile << "Hello world! " + Ord4 << endl;
}

void readFromFile(){
	ifstream inFile {"fil.txt"};
	ofstream outFile {"tekst.txt"};
	string line;
	int i = 0;

	while(getline(inFile, line)){
		cout << "Linjenummer " << i+1 << line << endl;
		outFile << i+1 << " "<< line << endl;
		i++;
	}

	// if(!is){
	// 	cerr << "Kunne ikke åpne fil" << endl;
	// }
}

void statistikk(){
	ifstream inFile {"grunnlov.txt"};
	string line;
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	int countE = 0;
	int countF = 0;
	int countG = 0;
	int countH = 0;
	int countI = 0;
	int countJ = 0;
	int countK = 0;
	int countL = 0;
	int countM = 0;
	int countN = 0;
	while(getline(inFile, line)){
		cout << line << endl;
		for(int i = 0; i<=line.length(); i++){
			char test = tolower(line[i]);
			if(test=='a'){
				countA++;
				//cout << countA << endl;
			}
			if(test=='b'){
				countB++;
				//cout << countB << endl;
			}
			if(test=='c'){
				countC++;
				//cout << countC << endl;
			}
			if(test=='d'){
				countD++;
				//cout << countD << endl;
			}
			if(test=='e'){
				countE++;
				//cout << countE << endl;
			}
			if(test=='f'){
				countF++;
				//cout << countF << endl;
			}
			if(test=='g'){
				countG++;
				//cout << countG << endl;
			}
			if(test=='h'){
				countH++;
				//cout << countH << endl;
			}
			if(test=='i'){
				countI++;
				//cout << countI << endl;
			}
			if(test=='j'){
				countJ++;
				//cout << countJ << endl;
			}
			if(test=='g'){
				countG++;
				//cout << countG << endl;
			}
			if(test=='h'){
				countH++;
				//cout << countH << endl;
			}
			if(test=='i'){
				countI++;
				//cout << countI << endl;
			}
			if(test=='j'){
				countJ++;
				//cout << countJ << endl;
			}
			if(test=='k'){
				countK++;
				//cout << countK << endl;
			}
			if(test=='l'){
				countL++;
				//cout << countL << endl;
			}
			if(test=='m'){
				countM++;
				//cout << countM << endl;
			}
			if(test=='n'){
				countN++;
				//cout << countN << endl;
			}
		}
	}
	cout << "a: " << countA << endl;
	cout << "b: " << countB << endl;
	cout << "c: " << countC << endl;
	cout << "d: " << countD << endl;
	cout << "e: " << countE << endl;
	cout << "f: " << countF << endl;
	cout << "g: " << countG << endl;
}

void test(){
	cout << "testtest";
}

int main(){
	// writeToFile();
	// readFromFile();
	// test();
	statistikk();
	CourseCatalog::addCourse();
	Temp t;

	ifstream inFile{"temperatures.txt"};
	if (!inFile){
		cerr << "Kunne ikke åpne fil" << endl;
	}

	inFile >> s;
}

// #include "std_lib_facilities.h"
// const map<string, string> capitalsMap {
// 	{"Norway", "Oslo"},
// 	{"Sweden", "Stockholm"},
// 	{"Denmark", "Copenhagen"}
// };
// string getCapital(const string& country) {
// 	return (capitalsMap[country]);
// }
// int main() {
// 	cout << "Capitals:\n";
// 	for (auto& elem : capitalsMap) {
// 		cout << getCapital(elem.first) << endl;
// 	}
// }

/*
Nyttig info
getline(cin, variabelnavn) //Heter hele setningen inn i variabelnavn
istream
ifstream
ostream
ofstream

Teori: 
2b) Det rarådes sterkt å bruke [] for å hente ut fra map. Det er fordi en ueksisten ting inni [] blir lagt til i mappet.
Det er berde å bruke .at for henting og .insert for innsetting. 

3d) operator legger alltid til en ny verdi til og med om ingen key eller value er spesifisert.
Insert prøver å legge til. Når det allerede er en verdi tilstede blir det ikke lagt til noe nytt ettersom map bare har et variabel for hver nøkkel.
*/