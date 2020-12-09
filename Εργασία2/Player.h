#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
using namespace std;

class Player{
   string name;
   string gender;
   unsigned int age;
   string occupation;
   float skill;
   float fatigue;
   float popularity;
   unsigned int victories;
   string team;

   public:
       // Two constructors, with and without parameters, and the destructor
        Player();
        Player(string n, string g, unsigned int a, string o, string t);
        ~Player();

        //Following are all the get/set functions for all the private variables of the class
        string getName()                       {return name;};             //Gets name
        void setName(string value)             {name = value;};            //Sets name = value

        string getGender()                     {return gender;};           //Gets gender
        void setGender(string value)           {gender = value;};          //Sets gender = value

        unsigned int getAge()                  {return age;};              //Gets age
        void setAge (unsigned int value)       {age = value;};             //Sets age

        string getOccupation()                 {return occupation;};       //Gets occupation
        void setOccupation(string value)       {occupation = value;};      //Sets occupation = value

        float getSkill()                       {return skill;};            //Gets skill
        void setSkill(float value)             {skill = value;};           //Sets skill = value

        float getFatigue()                     {return fatigue;};          //Gets fatigue
        void setFatigue(float value)           {fatigue = value;};         //Sets fatigue = value

        float getPopularity()                  {return popularity;};       //Gets popularity
        void setPopularity(float value)        {popularity = value;};      //Sets popularity = value

        unsigned int getVictories()            {return victories;};        //Gets victories
        void setVictories(unsigned int value)  {victories = value;};       //Sets victories = value

        string getTeam()                       {return team;};             //Gets team
        void setTeam(string value)             {team = value;};            //Sets team = value;

        void printStats();

        void work();
        void socialize();
        void endOfWeekActivities();
        void participateInCompetition(string type);
        void receiveTrophy();
        void vote();
        void leave();
};

#endif // PLAYER_H_INCLUDED
