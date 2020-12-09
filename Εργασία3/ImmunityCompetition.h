#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "ImmunityAward.h"
#include "Team.h"

using namespace std;

/*Κλάση ImmunityCompetition. Υλοποίηση όσων χρειάζονται για μια διαγωνιστική μέρα ασυλίας στον διαγωνισμό του masterchef.
Αποτελεί παράγωγη κλάση της competition για αυτο έχει όλες τι μεταβλητές από την βασική κλάση. Περιέχει ένα αντικείμενο
 immunityAward τύπου ImmunityAward που αντιστοιχεί στο βραβείο του ImmunityCompetition*/
class ImmunityCompetition: public Competition
{
    ImmunityAward immunityAward;

public:
    ImmunityCompetition() {}
    ImmunityCompetition(unsigned int i, string n, ImmunityAward iA);
    ~ImmunityCompetition(){cout<<"Immunity Competition has ended"<<endl;}                       //destructor


    int getVotesOfImmunityAward()           {return immunityAward.getVotes();}                  //getters για τις μεταβλητές τις συνάρτησης
    string getNameOfImmunityAward()         {return immunityAward.getName();}
    bool getSoloOfImmunityAward()           {return immunityAward.getSolo();}

    void setVotesOfImmunityAward(int v)           {immunityAward.setVotes(v);}                  //setters για τις μεταβλητές τις συνάρτησης
    void setNameOfImmunityAward(string n)         {immunityAward.setName(n);}
    void setSoloOfImmunityAward(bool s)           {immunityAward.setSolo(s);}

    void status();

    void compete(Team &team);


};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
