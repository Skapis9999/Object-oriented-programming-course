#ifndef CREATIVITYCOMPETITION_H_INCLUDED
#define CREATIVITYCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "ExcursionAward.h"
#include <string>
#include "Team.h"

using namespace std;

/*Κλάση CreativeCompetition. Υλοποίηση όσων χρειάζονται για μια διαγωνιστική μέρα δημιουργικότητας στον διαγωνισμό του masterchef.
Αποτελεί παράγωγη κλάση της competition για αυτο έχει όλες τι μεταβλητές από την βασική κλάση. Περιέχει ένα αντικείμενο excursionAward
τύπου ExcursionAward καθώς και έναν static string πίνακα με τα 10 στοιχεία που περιέχει τα 10 τυχαία υλικά που θα χρησιμοποιηθούν*/
class CreativityCompetition: public Competition{
    ExcursionAward excursionAward;
    static string ingredients[10];

public:
    CreativityCompetition();
    CreativityCompetition(unsigned int i, string name, ExcursionAward eA);
    ~CreativityCompetition() {cout << "Creativity Competition has Ended\n";} //Destructor

    //get/set                                                               //Δεν κρίθηκαν απαραίτητοι και παραλήφθησαν καθώς δόθηκε η δυνατότητα απο την εκφώνηση

    void status();
    void compete(Team &team1, Team &team2);
};
#endif // CREATIVITYCOMPETITION_H_INCLUDED
