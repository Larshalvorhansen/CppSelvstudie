#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    for (auto c : contracts)
    {
        if (c.getId() == id)
            return c;
    }
    // The task assumes valid input.
    // Error handling is therefore not neccesary to complete the task, but included here for good measure.
    throw runtime_error("Id does not exist in database");
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    int count = 0;
    for (auto c : contracts)
    {
        if (c.getInsuranceType() == type)
        {
            count++;
        }
    }
    return count;
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    int highestId = 0;
    for (auto c : contracts)//setter iden til den høyeste i contacts
    {
        if (c.getId() > highestId)
        {
            highestId = c.getId();
        }
    }
    // It is stated in the assignment that the contracts should be sorted ascending by id.
    // Checking only the last element in "contracts" would therefore also be correct.

    highestId++; //legger til en så denne iden blir den høyeste. 
    contracts.push_back({holderName, insType, value, highestId}); //Setter inn en ny kontakt i contacts
    return highestId;
}

void ContractDataBase::saveContracts(string filename)
{
    ofstream outFile{filename}; //Definerer hvilken fil som er outfile?
    if (!outFile)
    {
        throw runtime_error("Couldn't open file: " + filename);
    }

    string output;
    for (auto c : contracts) //lager en kjempelang streng av alle tingene i contacts
    {
        output += c.getHolder() + ',';
        output += insuranceTypeToString(c.getInsuranceType()) + ',';
        output += to_string(c.getValue()) + ',';
        output += to_string(c.getId()) + ',';
        output += c.getInsuranceText() + '\n';
    }
    outFile << output; //setter denne strengen inn i filen
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        throw runtime_error("Couldn't open file: " + filename);
    }

    string line;
    while (getline(inFile, line)) //forstår ikke helt hvordan denne kan være i en while.
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
