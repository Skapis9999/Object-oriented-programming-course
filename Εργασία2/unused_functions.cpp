//From Player.h
public:
    void Work(float Skill, float Fatigue);
    void Socialize(float Popularity);
    void EndOfWeekActivities(float Skill, float Fatigue);
    void ParticipateInCompetition(float Fatigue, string Type);
    void ReceiveTrophy(unsigned int Victories);
    void Vote();
    void Leave();



//From Player.cpp
void Player::Work(float skill, float fatigue){
    Fatigue=+(rand()%21+20);      //Generates random number from 20 to 40
    Skill=*1,05;                  //Skill is increased by 5% proportionally
    if(Skill>80)
        Skill=80;              //In order not to have skill over 80% which is the upper limit ////Is it???///
}

void Player::Socialize(float popularity){
    Popularity=Popularity+Popularity*(rand()%21-10)/100; //Generates random number from -10 to 10 and changes popularity proportionally
}

void Player::EndOfWeekActivities(float skill, float fatigue){
   int coin=rand()%2;        //Generates random number. or 0 either 1. Works like coin
   if(!coin)
   {
       cout<<"The player "<< Name<<" will rest this weekend."<<endl;
       Fatigue=0;
   }
   else
   {
       cout<<"The player"<< Name<<" will exercise this weekend."<<endl;
       Skill+=5;
   }

}

void Player::ParticipateInCompetition(float fatigue, string Type){
    Fatigue=Fatigue+Fatigue*(rand()%11+10)/100;     //Generates random number from 10 to 20 and increases fatigue proportionally
    cout<<"The player "<< Name<<" took part in "<< Type <<" Competition"<<endl;
}

void Player::ReceiveTrophy(unsigned int victories){
    Victories=Victories+1 ;
    cout<<"The player "<< Name<<" won"<<endl;
}

void Player::Vote(){
    //We do not know how Voting works. We will change this function in the future
    // Yes, we do, each player has to vote someone on his team for a reason. All the votes are collected and the results are called out by the judges.
}

void Player::Leave(){ //This function is followed by ~Player
    ////The player << Name << has been kicked out of the game, as a result of the disqualification competition. << endl
    cout<<"The player "<< Name<<" lost :-("<<endl;
    cout<<endl<<"----------------GAME OVER "<< Name<< " ------------------"<<endl;
}

//From Team.h
void ParticipateInCompetition(string Type);
void ReceiveTrophy();
void ParticipateInVoting();

//From Team.cpp
extern int playerNum;
extern Player *Players;

void Team::ParticipateInCompetition(string Type){
    if (Type == "Team")
        for(int i=0; i<TeamPlayerNum; i++){
            TeamPlayers[i].ParticipateInCompetition(TeamPlayers[i].GetFatigue(),Type);
            for (int j=0; j<playerNum; j++){
                if (TeamPlayers[i].GetName() == Players[j].GetName())
                    Players[j] = TeamPlayers[i];
            }
        }
    else if (Type == "Immunity")
        for(int i=0; i<TeamPlayerNum; i++){
            TeamPlayers[i].ParticipateInCompetition(TeamPlayers[i].GetFatigue(),Type);
            for (int j=0; j<playerNum; j++){
                if (TeamPlayers[i].GetName() == Players[j].GetName())
                    Players[j] = TeamPlayers[i];
            }
        }
    else if (Type == "Disqualification")
        for(int i=0; i<TeamPlayerNum; i++){
            TeamPlayers[i].ParticipateInCompetition(TeamPlayers[i].GetFatigue(),Type);
            for (int j=0; j<playerNum; j++){
                if (TeamPlayers[i].GetName() == Players[j].GetName())
                    Players[j] = TeamPlayers[i];
            }
        }
}

void Team::ReceiveTrophy(){
    Victories += 1;
    cout << "The " << Colour << " team has received a trophy!" << endl;
}

void Team::ParticipateInVoting(){
    //Voting Procedure
}
