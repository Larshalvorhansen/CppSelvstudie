#pragma once
#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus{Trondheim,Ålesund,Gjøvik};

class Meeting{
    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const shared_ptr<Person> leader;
        vector<shared_ptr<Person>> participants;
    public:
        Meeting(int day, int startTime, int endTime, Campus location, string subject, const shared_ptr<Person> leader);
        void addParticipant(std::shared_ptr Person);
        //3e) Når objektet blir slettet ligger fortsatt informasjonen i minne, men pointeren blir fjernet og minnecellene blir sett på som ledig plass
        vector<string> getParticipantList();
};