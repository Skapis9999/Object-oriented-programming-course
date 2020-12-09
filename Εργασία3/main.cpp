/*Μέρος της εργασίας των:
    Κωφοκώτσιου Ηλία    ΑΕΜ 9380  Τηλέφωνο 6944316621 email ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου     ΑΕΜ 9378  Τηλέφωνο 6933251534 email skapetis@ece.auth.gr
    */
#include "Team.h"
#include "CreativityCompetition.h"
#include "ExcursionAward.h"
#include "FoodAward.h"
#include "ImmunityCompetition.h"
#include "ImmunityAward.h"
#include "Player.h"
#include "Round.h"
#include "TeamCompetition.h"

using namespace std;

// Index 0 = Red Team, Index 1 = Blue Team
Team teams[2] = { Team("Red"), Team("Blue")};
Team *Red = teams;
Team *Blue = teams+1;
int competitionId = 0, teamCompetitionResult;
// Οι συναρτήσεις οι οποίες δηλώνονται παρακάτω επεξηγούνται στο σημείο στο οποίο ορίζονται, δηλαδή μετά την συνάρτηση main
void menu();
void normalDay();
void teamCompetitionDay();
void immunityCompetitionDay();
void creativityCompetitionDay();

extern string allIngredients;

//Static σηνάρτηση η οποία χειρίζεται τον static πίνακα ingredients
static void staticInit(){
    string ingredients[10];
}

int main(){
    menu();
    return 0;
}

//Menu επιλογής μέρας  μέσω μιας switch
void menu(){
    int choice = -1;
    while(choice != 0){
        cout << endl << "1.Normal Day." << endl;
        cout << "2.Team Competition Day." << endl;
        cout << "3.Immunity Competition Day." << endl;
        cout << "4.Creativity Competition Day." << endl;
        cout << "0.Quit" << endl;
        cin >> choice;
        switch(choice){
        case 1:
            normalDay();
            break;
        case 2:
            teamCompetitionDay();
            break;
        case 3:
            immunityCompetitionDay();
            break;
        case 4:
            creativityCompetitionDay();
            break;
        case 0:
            break;
        default:
            cout << "Incorrect Input. Choose between 1 and 3. Press 0 to quit." << endl;
        }
    }
}

//normal day. Υλοποίηση που προσομοιώνει μια φυσιολογική μέρα στον διαγωνισμό του masterchef Gr 2017-2018 χωρίς κανένα διαγωνισμό
void normalDay(){
    cout << endl << "This is a normal day in the Master Chef Game." << endl << endl;
    //Morning
    Red->teamEats();
    Blue->teamEats();
    Red->teamWorks();
    Blue->teamWorks();
    //Evening
    Red->teamSocializes();
    Blue->teamSocializes();
    Red->teamEats();
    Blue->teamEats();
    Red->teamSleeps();
    Blue->teamSleeps();
}

//competition day. Υλοποίηση που προσομοιώνει μια διαγωνιστική μέρα στον διαγωνισμό του masterchef Gr 2017-2018 με έναν ομαδικό διαγωνισμό.
void teamCompetitionDay(){
    cout << endl << "This is a Team Competition day in the Master Chef Game." << endl << endl;
    //Morning
    Red->teamEats();
    Blue->teamEats();
    Red->teamWorks();
    Blue->teamWorks();
    //Team Competition
    FoodAward foodAward("Team Competition Food Award", false);
    cout << "Please give a name to the Team Competition\n";
    string name;
    getchar();
    getline(cin, name);
    TeamCompetition teamContest(++competitionId, name, foodAward);
    teamCompetitionResult = teamContest.compete(*Red, *Blue);
    //Evening
    Red->teamSocializes();
    Blue->teamSocializes();
    Red->teamEats();
    Blue->teamEats();
    Red->teamSleeps();
    Blue->teamSleeps();
}

//immunity competition day. Υλοποίηση που προσομοιώνει μια διαγωνιστική μέρα ασυλίας στον διαγωνισμό του masterchef Gr 2017-2018 με έναν διαγωνισμό ασυλίας.
void immunityCompetitionDay(){
    cout << endl << "This is a Immunity Competition day in the Master Chef Game." << endl << endl;
    //Morning
    Red->teamEats();
    Blue->teamEats();
    Red->teamWorks();
    Blue->teamWorks();
    //Competition
    ImmunityAward immunityAward("Immunity Competition Award", true);
    cout << "Please give a name to the Immunity Competition\n";
    string name;
    getchar();
    getline(cin, name);
    ImmunityCompetition immunityContest(++competitionId, name, immunityAward);
    if (teamCompetitionResult == 0)
        immunityContest.compete(*Red);
    else
        immunityContest.compete(*Blue);
    //Evening
    Red->teamSocializes();
    Blue->teamSocializes();
    Red->teamEats();
    Blue->teamEats();
    Red->teamSleeps();
    Blue->teamSleeps();
}

//creativity competition day. Υλοποίηση που προσομοιώνει μια διαγωνιστική μέρα δημιουργικότητας στον διαγωνισμό του masterchef Gr 2017-2018 με έναν διαγωνισμό δημιουργικότητας.
void creativityCompetitionDay(){
    cout << endl << "This is a Creativity Competition day in the Master Chef Game." << endl << endl;
    //Morning
    Red->teamEats();
    Blue->teamEats();
    Red->teamWorks();
    Blue->teamWorks();
    //Competition
    ExcursionAward excursionAward("Creativity Competition Excursion Award", true);
    cout << "Please give a name to the Creativity Competition\n";
    string name;
    getchar();
    getline(cin, name);
    CreativityCompetition creativityContest(++competitionId, name, excursionAward);
    creativityContest.compete(*Red, *Blue);
    //Evening
    Red->teamSocializes();
    Blue->teamSocializes();
    Red->teamEats();
    Blue->teamEats();
    Red->teamSleeps();
    Blue->teamSleeps();
}
