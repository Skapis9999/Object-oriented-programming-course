#include <iostream>
#include "Player.h"
#include "Team.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

    // The Menu Function Prototypes
void newPlayer();
void TeamStats();
void printPlayer(Player pl);
void PlayerStats();
void exit();

    // Team and Player Initialization
Team Blue;
Team Red("Red", 0, 0);
int playerNum = 0;

    // The Menu Exit Condition
bool exitCondition = false;

int main(){
    {   // Initial Text Greeting
        cout << "Welcome to the Masterchef simulation programme. This programme aspires to simulate, however plainly," << endl;
        cout << "the popular televised competition, Masterchef. In this first version of the programme, you are given" << endl;
        cout << "the ability to view and control the aspects of the game that concern the players and the teams." << endl;
        cout << "These are, the ability to add a player to a team, the ability to view a team's statistics, or the" << endl;
        cout << "statistics of individual players. Before you can choose one of these functions, please bear in mind" << endl;
        cout << "that, unless you are using a UNIX based system (i.e. Linux or Macintosh), all text input must be done" <<endl;
        cout << "with Latin characters ONLY."<< endl << "0.1.4 Alpha Version"<< endl<< endl;
    }
    // rand() function time seed
    srand (time(NULL));

    do{
        {// Menu Console Output
            cout << "Please choose one of the following options by typing the corresponding letter and pressing enter:" << endl;
            cout << "   1. Add a new player to any team." << endl;
            cout << "   2. View the statistics of any team, and all the players it consists of." << endl;
            cout << "   3. View the statistics of any individual player." << endl;
            cout << "   4. Exit this programme. Please bear in mind that all the data you have entered will be lost." << endl;
        }
        // Decision Character and Switch Statement
        char ch;
        cin >> ch;
        switch (ch){
        case '1':
            if(playerNum>21){  //If already 22 players then return to menu (the array starts from 0, so the last position is 21)
                cout << "The maximum amount of players has been reached. Please select another option." << endl;
                break;
            }
            newPlayer();
            break;
        case '2':
            TeamStats();
            break;
        case '3':
            PlayerStats();
            break;
        case '4':
            exit();
            break;
        default:
            cout << "Incorrect Choice. Please input one of the numbers that corresponds to one of the above functions." << endl;
        }
    }while (!exitCondition);
    return 0;
}


void newPlayer(){
    string name, gender, occupation, team;
    unsigned int age;
    {   // Input and Saving of Player's Name
        cout<<"Please input the new player's name"<<endl;
        getchar();
        getline (cin, name);
    }
    {   // Input and Saving of Player's Gender
        cout<<"Please input the player's gender"<<endl;
        bool correctGender=false;
        do{
            cin >> gender;
            if(gender=="Male"||gender=="male"||gender=="female"||gender=="Female"){
                correctGender=true;
            }
            else
                cout << "Incorrect Choice. Please input \"Male\" or \"Female.\"" << endl;
        }while(!correctGender);
    }
    {   // Input and Saving of Player's Age
        cout<<"Please input the player's age"<<endl;
        bool correctAge=false;
        do{
            cin >> age;
            if(age >= 18 && age <= 100){
                correctAge=true;
            }
            else if (age < 18)
                cout << "Unfortunately only adults are allowed to participate in Master Chef. Please input an age equal or greater than 18." << endl;
            else{
                cout << "Unfortunately, based on health regulations, people over 100 years old are not allowed to participate in the game." << endl;
                cout << "Please input a valid age over 18 years old." << endl;
            }
        }while(!correctAge);
    }
    {   // Input and Saving of Player's Occupation
        cout << "Please input the player's Occupation" << endl;
        getchar();
        getline(cin, occupation);
    }
    {   // Input and Saving of Player's Team
        if(Blue.getPlayerNum() == 11 && Red.getPlayerNum() < 11){
            cout << "Because the maximum amount of players has been reached for the blue team," << name;
            cout << " will have to be placed in the red team automatically." << endl;
            Red.setPlayer(Red.getPlayerNum(), name, gender, age, occupation, "Red");
            Red.setPlayerNum(Red.getPlayerNum()+1);
        }
        else if(Red.getPlayerNum() == 11 && Blue.getPlayerNum() < 11){
            cout << "Because the maximum amount of players has been reached for the red team," << name;
            cout << " will have to be placed in the blue team automatically." << endl;
            Blue.setPlayer(Blue.getPlayerNum(), name, gender, age, occupation, "Blue");
            Blue.setPlayerNum(Blue.getPlayerNum()+1);
        }
        else if (Red.getPlayerNum() < 11 && Blue.getPlayerNum() < 11){
            cout << "Please input the team to which the player will belong, \"Red\" or \"Blue\"." << endl;
            bool correctTeam = false;
            do {
                cin >> team;
                if (team == "Blue" || team == "blue"){
                    Blue.setPlayer(Blue.getPlayerNum(), name, gender, age, occupation, "Blue");
                    Blue.setPlayerNum(Blue.getPlayerNum()+1);
                    correctTeam = true;
                }
                else if (team == "Red" || team == "red"){
                    Red.setPlayer(Red.getPlayerNum(), name, gender, age, occupation, "Red");
                    Red.setPlayerNum(Red.getPlayerNum()+1);
                    correctTeam = true;
                }
                else
                    cout << "Incorrect Input. Please input either \"Blue\" or \"Red\"" << endl;
            }while (!correctTeam);
        }
    }
    cout << "The Player " << name << " has been successfully initialized" << endl;
        // Increment of PlayerNum so that the next player is stored in the next array position
    playerNum++;
}

void TeamStats(){
    cout << "Please input which team you would like to see statistics for, Red or Blue" << endl;
    string choice;
    do{
        cin >> choice;
        if (choice == "Blue" || choice == "blue"){
            cout << endl << " Blue Team: " << endl << "Number of Players: " << Blue.getPlayerNum() << endl;
            cout << "Players who belong to this team: " << Blue.getPlayerName(0) << endl;
            for (int i=1; i< Blue.getPlayerNum(); i++){
                cout << "                                 " << Blue.getPlayerName(i) << endl;
            }
            cout << "This team has a total of " << Blue.getVictories() << " Victories in Competitions." << endl;
        }
        else if (choice == "red" || choice == "Red"){
            cout << endl << " Red Team: " << endl << "Number of Players: " << Red.getPlayerNum() << endl;
            cout << "Players who belong to this team: " << Red.getPlayerName(0) << endl;
            for (int i=1; i< Red.getPlayerNum(); i++){
                cout << "                                  " << Red.getPlayerName(i) << endl;
            }
            cout << "This team has a total of " << Red.getVictories() << " Victories in Competitions." << endl;

        }
        else
            cout << "Incorrect input. Please choose one of the two teams, \"Red\" or \"Blue\"" << endl;
    }while (choice != "Blue" && choice != "blue" && choice != "red" && choice != "Red");
}

void PlayerStats(){
    cout << "Would you wish to do a direct search with the player's name or would you like to see all the players and then choose?" <<endl;
    cout << "Please either type the full name directly or type \"view\" for the list of players." << endl;
    string choice;
    getchar();
    getline(cin,choice);
    if (choice == "view" || choice == "View"){
        cout << "This is a list of all the players in the competition" << endl << "    Blue Team" << endl;
        for (int i = 0; i<Blue.getPlayerNum(); i++)
            cout << i+1 << ". " << Blue.getPlayerName(i) << endl;
        cout << "   Red Team" << endl;
        for (int i = 0; i<Red.getPlayerNum(); i++)
            cout << i+1 << ". " << Red.getPlayerName(i) << endl;
        cout << "Please input the team of the player whose stats you want to view." << endl;
        string team;
        bool correctTeam = false;
        do {
            cin >> team;
            if (team == "Blue" || team == "blue"){
                cout << "Please enter the number of the player." << endl;
                unsigned short ch;
                do{
                    cin >> ch;
                    if (ch <= Blue.getPlayerNum() && ch > 0)
                        Blue.printPlayer(ch-1);
                    else
                        cout << "Incorrect choice. Please input a number between 1 and " << Blue.getPlayerNum() << endl;
                }while (ch > Blue.getPlayerNum() || ch < 0);
                correctTeam = true;
            }
            else if (team == "Red" || team == "red"){
                cout << "Please enter the number of the player." << endl;
                unsigned short ch;
                do{
                    cin >> ch;
                    if (ch <= Red.getPlayerNum() && ch > 0)
                        Red.printPlayer(ch-1);
                    else
                        cout << "Incorrect choice. Please input a number between 1 and " << Blue.getPlayerNum() << endl;
                }while (ch > Red.getPlayerNum() || ch < 0);
                correctTeam = true;            }
            else
                cout << "Incorrect Input. Please input either \"Blue\" or \"Red\"" << endl;
        }while (!correctTeam);
    }
    else{
        bool found = false;
        for (int i=0; i<Blue.getPlayerNum(); i++)
            if (choice == Blue.getPlayerName(i)){
                found = true;
                Blue.printPlayer(i);
            }
        if (!found)
            for (int i=0; i<Red.getPlayerNum(); i++)
                if (choice == Red.getPlayerName(i)){
                    found = true;
                    Red.printPlayer(i);
                }
        if (!found){
            cout << "There does not exist a player with the name " << choice << "." << endl;
            cout << "Please check your input and try again, or try to view all the players by typing \"view\"." << endl;
        }
    }
}

void exit(){
    cout << "Do you really want to exit the programme? All entered data will be lost." << endl;
    cout << "Please confirm you choice by typing \"yes\" into the console." << endl;
    cout << "Any other choice will return you to the main menu." << endl;
    string choice;
    cin >> choice;
    if (choice == "yes" || choice == "Yes")
        exitCondition = true;
    else
        exitCondition = false;
}
