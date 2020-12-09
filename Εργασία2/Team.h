#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Player.h"
#include <string>


class Team {
    string colour;
    int teamPlayerNum;
    Player *teamPlayers;
    unsigned int victories;

public:
    //Constructors and Destructor
    Team();
    Team(string col, int num, int wins);
    ~Team();

    //Get and Set Functions for all the variables
    string getColour()                   {return colour;};
    void setColour(string c)             {colour = c;};

    int getPlayerNum()                   {return teamPlayerNum;};
    void setPlayerNum(int num)           {teamPlayerNum = num;};

    int getVictories()                   {return victories;};
    void setVictories(int wins)          {victories = wins;};

    void setPlayer(int n, string name, string gender, unsigned int age, string occupation, string team);
    string getPlayerName(int n)          {return teamPlayers[n].getName();};
    void printPlayer(int n)              {teamPlayers[n].printStats();};


};


#endif // TEAM_H_INCLUDED
