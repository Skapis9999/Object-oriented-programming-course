#include "Player.h"
#include <iostream>     //For the basic I/O functions, cin, cout, etc.
#include <stdlib.h>     //For the rand() and srand() functions
#include <string>       //For string
#include <cstdio>       //For getchar()



using namespace std;

Player::Player(){         //Αρχικοποίηση χωρίς ορίσματα
    skill = rand()%81;        //Initial Skill is a random number from 0 to 80 (percent)  ///Can it reach above 80?///
    fatigue = 0;              //Initial Fatigue is 0 (percent)
    popularity = 50;          //Initial Popularity is 50 (percent)
    victories = 0;            //Initial Victories are obviously 0
    name="Default Name";
    gender="Ν/Α";
    age=0;
    occupation="Ν/Α";
    team = "No Team";
}

Player::Player(string n, string g, unsigned int a, string o, string t){
   name=n;
   gender=g;
   age=a;
   occupation=o;
   team = t;
}

Player::~Player(){
    cout << "The " << name << " Object has been succesfully destroyed" << endl;
}

void Player::printStats(){
    cout << "Player name: " << getName() << endl;
    cout << "Team:        " << getTeam() << endl;
    cout << "Gender:      " << getGender() << endl;
    cout << "Age:         " << getAge() << endl;
    cout << "Occupation:  " << getOccupation() << endl;
    cout << "Fatigue:     " << getFatigue() << endl;
    cout << "Skill:       " << getSkill() << endl;
    cout << "Popularity:  " << getPopularity() << endl;
}

void Player::work(){
    fatigue=+(rand()%21+20);      //Generates random number from 20 to 40
    skill *=1.05;                 //Skill is increased by 5% proportionally
}

void Player::socialize(){
    popularity = popularity + popularity*(rand()%21-10)/100; //Generates random number from -10 to 10 and changes popularity proportionally
}

void Player::endOfWeekActivities(){
   int coin=rand()%2;        //Generates random number. or 0 either 1. Works like coin
   if(!coin)
   {
       cout<<"The player "<< name<<" will rest this weekend."<<endl;
       fatigue=0;
   }
   else
   {
       cout<<"The player"<< name<<" will exercise this weekend."<<endl;
       skill+=5;
   }

}

void Player::participateInCompetition (string type){
    fatigue = fatigue + fatigue*(rand()%11+10)/100;     //Generates random number from 10 to 20 and increases fatigue proportionally
    cout<<"The player "<< name <<" took part in "<< type <<" Competition"<<endl;
}

void Player::receiveTrophy(){
    victories++ ;
    cout<<"The player "<< name <<" won"<<endl;
}

void Player::vote(){
    cout << "Please input the player to be voted by " << name << endl;
    string voted, reason;
    getchar();
    getline(cin, voted);
    cout << "Please input the reason why." << endl;
    getchar();
    getline(cin,reason);
    //This function requires also that the strings voted and reason are stored in a team-wide array.
    //However, as it is not required by the current programme we decided to leave it here so it'd be ready for any future additions
}

void Player::leave(){ //This function is followed by ~Player
    ////The player << Name << has been kicked out of the game, as a result of the disqualification competition. << endl
    cout<<"The player "<< name<<" lost :-("<<endl;
    cout<<endl<<"----------------GAME OVER "<< name<< " ------------------"<<endl;
}
