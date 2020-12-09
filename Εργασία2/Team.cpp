#include "Team.h"
#include "Player.h"
#include <iostream>
#include <string>

Team::Team(){
    colour = "Blue";
    teamPlayerNum = 0;
    teamPlayers = new Player[11];
    victories = 0;
}

Team::Team(string col, int num, int wins){
    colour = col;
    teamPlayerNum = num;
    teamPlayers = new Player [11];
    victories = wins;
}

Team::~Team(){
    delete[] teamPlayers;
    cout << "The " << colour << " team object was destroyed successfully" << endl;
}

void Team::setPlayer(int n, string name, string gender, unsigned int age, string occupation, string team){
    teamPlayers[n].setName(name);
    teamPlayers[n].setGender(gender);
    teamPlayers[n].setAge(age);
    teamPlayers[n].setOccupation(occupation);
    teamPlayers[n].setTeam(team);
}

