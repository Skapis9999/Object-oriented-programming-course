#ifndef TEAMCOMPETITION_H_INCLUDED
#define TEAMCOMPETITION_H_INCLUDED

#include "Competition.h"
#include "Round.h"
#include "Team.h"
#include "Player.h"
#include "FoodAward.h"

class TeamCompetition:  public Competition
{
    FoodAward foodAward;
    Round round[3]{/*   Stuff  */};

public:
    TeamCompetition();
    TeamCompetition(unsigned int i, string n, FoodAward fa);
    ~TeamCompetition(){cout<<"TeamCompetition "<< name<<" has ended"<<endl;}

    Award getAward()                      {return foodAward;}                                               //get object
    string getAwardName()                 {return foodAward.getName();}                                     //get object's variables
    Round getRound(unsigned int i)        {return round[i];}
    int getRoundid(unsigned int i)        {return i+1;}                                                     //i=0,1,2 id=1,2,3
    int getRoundDuration(unsigned int i)  {return round[i].getDuration();}
    string getRoundWinner(unsigned int i) {return round[i].getWinner();}

    void status(){
        string nameStatus=getAwardName();
        cout<<"\t\tTEAM COMPETITION"<<endl<<"\tFoodAward"<<endl<<"Name     "<< nameStatus <<endl<<"Solo     "<< "False"<<endl;                  //FoodAward
        cout<<"\tRound"<<endl<<"ID       "<< 1<<endl<< "Duration "<< getRoundDuration(0)<<endl<<"Winner   "<<getRoundWinner(0)<<endl;           //Round1
        cout<<"\tRound"<<endl<<"ID       "<< 2<<endl<< "Duration "<< getRoundDuration(1)<<endl<<"Winner   "<<getRoundWinner(1)<<endl;           //Round2
        cout<<"\tRound"<<endl<<"ID       "<< 3<<endl<< "Duration "<< getRoundDuration(2)<<endl<<"Winner   "<<getRoundWinner(2)<<endl;           //Round3
    }

    AverageTechnique(Player ArrayPlayers1[], Player ArrayPlayers2[]);
    AverageFatigue(Player ArrayPlayers1[], Player ArrayPlayers2[]);


    int compete(Team &team1, Team &team2);
};

#endif // TEAMCOMPETITION_H_INCLUDED
