#ifndef COMPETITION_H_INCLUDED
#define COMPETITION_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Competition
{
protected:
    unsigned int id;
    string name;
    string winner;
public:
    Competition()                                                   {id=0; name=""; winner="";}
    Competition(unsigned int i, string n)                           {id=i; name=n;}
    ~Competition()                                                  {cout<<"Competition " << name << " has just ended."<<endl;}

    unsigned int getId()                                            {return id;}                                                        //Getters
    string getName()                                                {return name;}
    string getWinner()                                              {return winner;}
    void setId(unsigned int i)                                      {id=i;}                                                              //Setters
    void setName(string n)                                          {name=n;}
    void setWinner(string w)                                        {winner=w;}

    void status()                                                   {cout<<"\t\tCOMPETITION"<<"id     " <<id << endl << "Name   " << name << endl << "Winner "<< winner << endl;}
};


#endif // COMPETITION_H_INCLUDED
