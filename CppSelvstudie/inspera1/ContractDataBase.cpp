#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b
    ifstream inFile {"DataBase.txt"};

    switch (id)
    {
    case 1234:
        return(getline(inFile, id-1234)); //Returnerer linje 0 som har iden 1234 i Database.txt
        break;
    case 1235:
        return(getline(inFile, id-1235));
        break;
    case 1236:
        return(getline(inFile, id-1236));
        break;
    case 1237:
        return(getline(inFile, id-1237));
        break;
    case 1238:
        return(getline(inFile, id-1238));
        break;
    case 1239:
        return(getline(inFile, id-1239));
        break;
    case 1240:
        return(getline(inFile, id-1240));
        break;
    case 1241:
        return(getline(inFile, id-1241));
        break;
    
    default:
        break;
    }

    //Jeg vet at det ikke er slik man egentlig gjør det. Egt skal man bruke iden til å hente ut objektene i ContractDataBase og returnere de som typen insuranceContact
    return InsuranceContract{};

    // END: 1b
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    int count = 0;
    for(InsuranceContract type : ContractDataBase){ //vet at jeg ikke kan bruke ContactDataBase her fordi det er en funkjson og ikke et objekt
        if(InsuranceContract::getInsuranceType()==type){//Sjekker(skal iallefall) om hver "InsuranceType" er lik typen som blir sjekket og letter til en i telleren hvis den er det.
             count ++;
        }
    }
    return count; //returnerer antall insurancer tilstede

    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    ContractDataBase.insert(string holderName, InsuranceType insType, int value);
    
    return 0;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    // Write your answer to assignment 1e here, between the // BEGIN: 1e
    // and // END: 1e comments. Remove the code that is already there.

    (void)filename;

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
