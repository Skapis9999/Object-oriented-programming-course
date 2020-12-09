/*Κωφοκώτσιος Ηλίας     Σκαπέτης Χρήστος
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Player.h"

using namespace std;

class Team{

    string color;
    Player *players;

public:

    Team(){color = ""; players = new Player[11];}
    Team(string color);
    ~Team(){delete [] players; cout << "Team " << color << " is destroyed." << endl;}

    string getColor(){return color;}
    Player* getPlayers(){return players;}

    void setColor(string val){color = val;}

    int getNumberOfPlayers();
    void setCandidate(string player);
    void removePlayer(string name);
    void status(bool playerInformation);

};

#endif // TEAM_H_INCLUDED
