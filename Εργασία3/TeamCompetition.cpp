#include "TeamCompetition.h"
#include <iostream>

using namespace std;

TeamCompetition::TeamCompetition(){
        //Everything is constructed automatically
}

TeamCompetition::TeamCompetition(unsigned int i, string n, FoodAward f): Competition(i,n){
      foodAward.setBonusSupplies(f.getBonusSupplies());
}

int TeamCompetition::AverageTechnique(Player ArrayPlayers1[], Player ArrayPlayers2[]){
    double skill1 = 0, skill2 = 0;
    for (int i=0; i<5; i++){
        skill1 += ArrayPlayers1[i].getTechnique();
        skill2 += ArrayPlayers2[i].getTechnique();
    }
    if(skill1>skill2)
        return 1;
    else
        return (skill1<skill2) ? 0 : 2;
}

int TeamCompetition::AverageFatigue(Player ArrayPlayers1[], Player ArrayPlayers2[]){
    double fatigue1 = 0, fatigue2 = 0;
    for (int i=0; i<5; i++){
        fatigue1 += ArrayPlayers1[i].getFatigue();
        fatigue2 += ArrayPlayers2[i].getFatigue();
    }
    if(fatigue1>fatigue2)
        return 1;
    else
        return (fatigue1 == fatigue2) ? 2 : 0;
}

int TeamCompetition::compete(Team &team1, Team &team2){
    unsigned int wins1=0, wins2=0, roundNum=0;
    Player ArrayPlayers1[5], ArrayPlayers2[5];
    string roundWinner[3];
    roundNum++;
    cout << "Before For\n";
    for(; roundNum<4; roundNum++){ //Big for
        unsigned int numbers[5];
        //Random different numbers for team1.
        for (int i = 0; i<5; i++){
            bool different = true;
            do{
                different = true;
                numbers[i] = rand()%11;
                for (int j=0; j<i; j++)
                    different &= (numbers[i] != numbers[j]);
            }while(!different);
            ArrayPlayers1[i] = team1.getPlayers()[numbers[i]];
        }
        for (int i = 0; i<5; i++){
            bool different = true;
            do{
                different = true;
                numbers[i] = rand()%11;
                for (int j=0; j<i; j++)
                    different &= (numbers[j] != numbers[i]);
            }while(!different);
            ArrayPlayers2[i] = team2.getPlayers()[numbers[i]];
        }
        //Compete
        for(int i=0; i<5; i++){
            ArrayPlayers1[i].compete();
            ArrayPlayers2[i].compete();
        }
        //Winners
        unsigned int betterTeam;
        betterTeam = AverageTechnique(ArrayPlayers1, ArrayPlayers2);
        if(betterTeam==1){
            wins1++;
            roundWinner[roundNum-1]=team1.getColor();}
        else if(betterTeam==0)
            {wins2++;
            roundWinner[roundNum-1]=team2.getColor();}
        else if(betterTeam==2)
        {
            unsigned int restTeam;
            restTeam = AverageFatigue(ArrayPlayers1, ArrayPlayers2);
            if(restTeam==1)
                {wins1++;
                roundWinner[roundNum-1]=team1.getColor();}
            else if(restTeam==0)
                {wins2++;
                roundWinner[roundNum-1]=team2.getColor();}
            else if(restTeam==2)
                {cout<< "It's a draw. Both Teams are winners.";
                wins1++;
                wins2++;}
        }
    }
    //"Results Menu" appeared only once. User can choose only one option
    cout << "Please choose which results you wish to see."<<endl;
    cout << "1.Overall Results"<<endl;
    cout << "2.Round Results"<<endl;
    cout << "0.No results"<<endl;
    unsigned int choice;
    bool menuBool = false;
    while(!menuBool){
        cin >> choice;
        if(choice==0 || choice==1 || choice==2){
            menuBool= true;
            break;
        }
        else
            cout<<"Please choose 1 or 2 or 0"<< endl;
    }
    switch(choice){
        case 1:
            if(wins1>wins2)
                cout<<endl<<"The winner team is team "<< team1.getColor() << " with score "<<wins1<< "-"<< wins2<<endl;
            else
                cout<<endl<<"The winner team is team "<< team2.getColor() << " with score "<<wins2<< "-"<< wins1<<endl;
            break;
        case 2:
            cout<<endl<<"The winner of the first round is team "<< roundWinner[0]<<endl;
            cout<<endl<<"The winner of the second round is team "<< roundWinner[1]<<endl;
            cout<<endl<<"The winner of the third round is team "<< roundWinner[2]<<endl;
            break;
        default:
            break;
    }
    if(wins1>=2){
        int a=team1.getWins()+1;
        team1.setWins(a);
        team1.setSupplies(team1.getSupplies() + foodAward.getBonusSupplies()) ;
        return 1;
    }
    else{
        int a=team2.getWins()+1;
        team2.setWins(a);
        team2.setSupplies(team1.getSupplies() + foodAward.getBonusSupplies()) ;
        return 0;
    }
}
