/* Μέρος Εργασίας των:
    Ηλία Κωφοκώτσιου      9380     ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου       9378     skapetis@ece.auth.gr
*/

#include <iostream>
#include "Player.h"
#include "Team.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

// Δηλώσεις των Συναρτήσεων που υλοποιούν τις λειτουργίες του μενού, των οποίων τα σώματα και οι επεξηγήσεις έχουν γραφεί παρακάτω
void newPlayer();
void teamStats();
void playerStats();
void exit();

// Αρχικοποίηση των δυο αντικειμένων ομάδων που θα υπάρχουν στο παιχνίδι
Team Blue("Blue", 0, 0);
Team Red("Red", 0, 0);
int playerNum = 0;

// Μια μεταβλητη που χρησιμεύει στην έξοδο από το μενού, αν και εφόσον το επιθυμεί ο χρήστης
bool exitCondition = false;


// Η main, η οποία εκτυπώνει άπαξ ένα μήνυμα υποδοχής στο πρόγραμμα, δίδει σπόρο στην rand() και, μέσα σε ατέρμονα βρόχο, εμφανίζει το μενού,
// δέχεται την επιλογή του χρήστη και καλεί την ανάλογη συνάρτηση ξανά και ξανά, εώς ότου ο χρήστης επιλέξει να εξέλθει από το πρόγραμμα
int main(){
    {   // Μήνυμα Υποδοχής
        cout << "Welcome to the Masterchef simulation programme. This programme aspires to simulate, however plainly," << endl;
        cout << "the popular televised competition, Masterchef. In this first version of the programme, you are given" << endl;
        cout << "the ability to view and control the aspects of the game that concern the players and the teams." << endl;
        cout << "These are, the ability to add a player to a team, the ability to view a team's statistics, or the" << endl;
        cout << "statistics of individual players. Before you can choose one of these functions, please bear in mind" << endl;
        cout << "that, unless you are using a UNIX based system (i.e. Linux or Macintosh), all text input must be done" <<endl;
        cout << "with Latin characters ONLY."<< endl << "0.1.6 Alpha Version"<< endl<< endl;
    }
    // Σπόρος στην rand()
    srand ( time(nullptr));
    do{
        {   // Εκτύπωση του μενού
            cout << "Please choose one of the following options by typing the corresponding letter and pressing enter:" << endl;
            cout << "   1. Add a new player to any team." << endl;
            cout << "   2. View the statistics of any team, and all the players it consists of." << endl;
            cout << "   3. View the statistics of any individual player." << endl;
            cout << "   4. Exit this programme. Please bear in mind that all the data you have entered will be lost." << endl;
        }
        // Ανάγνωση επιλογής από τον χρήστη και έκφραση switch
        char ch;
        cin >> ch;
        switch (ch){
        case '1':
            if(Blue.getPlayerNum()+ Red.getPlayerNum()== 22){  // Στην περίπτωση που υπάρχουν ήδη 22 παίκτες, δηλαδή ο μέγιστος επιτρεπόμενος αριθμός
                cout << "The maximum amount of players has been reached. Please select another option." << endl;
                break;
            }
            newPlayer();
            break;
        case '2':
            teamStats();
            break;
        case '3':
            playerStats();
            break;
        case '4':
            exit();
            break;
        default:
            cout << "Incorrect Choice. Please input one of the numbers that corresponds to one of the above functions." << endl;
        }
        cout << endl << endl;
    }while (!exitCondition);
    return 0;
}


// Συνάρτηση η οποία αναλαμβάνει την καταχώρηση ενός καινούριου παίκτη στον πίνακα κάποιας ομάδας. Γίνεται ανάγνωση του ονόματος, του φύλου,
// της ηλικίας, του επαγγέλματος και της ομάδας του νέου παίκτη και, μετά την επιλογή και της ομάδας, τα στοιχεία του νέου παίκτη
void newPlayer(){
    string name, gender, occupation, team;
    unsigned int age;
    {   // Είσοδος και αποθήκευση του ονόματος του παίκτη
        cout<<"Please input the new player's name"<<endl;
        getchar();
        getline (cin, name);
    }
    {   // Είσοδος και αποθήκευση του φύλου του παίκτη (επιτρεπτές απαντήσεις μόνο τα male και female)
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
    {   // Είσοδος και αποθήκευση της ηλικίας του παίκτη (επιτρεπτό εύρος από 18 έως 100 ετών)
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
    {   // Έισοδος και αποθήκευση του επαγγέλματος του παίκτη
        cout << "Please input the player's Occupation" << endl;
        getchar();
        getline(cin, occupation);
    }
    {   // Καθορισμός Ομάδας του Παίκτη
        if(Blue.getPlayerNum() == 11 && Red.getPlayerNum() < 11){ // Στην περίπτωση που μόνο στην κόκκινη ομάδα υπάρχει διαθέσιμη θέση
            cout << "Because the maximum amount of players has been reached for the blue team, " << name;
            cout << " will have to be placed in the red team automatically." << endl;
            Red.setPlayer(Red.getPlayerNum(), name, gender, age, occupation, "Red");
            Red.setPlayerNum(Red.getPlayerNum()+1);
            Red.meanStats();
        }
        else if(Red.getPlayerNum() == 11 && Blue.getPlayerNum() < 11){ // Στην περίπτωση που μόνο στην μπλε ομάδα υπάρχει διαθέσιμη θέση
            cout << "Because the maximum amount of players has been reached for the red team," << name;
            cout << " will have to be placed in the blue team automatically." << endl;
            Blue.setPlayer(Blue.getPlayerNum(), name, gender, age, occupation, "Blue");
            Blue.setPlayerNum(Blue.getPlayerNum()+1);
            Blue.meanStats();
        }
        else if (Red.getPlayerNum() < 11 && Blue.getPlayerNum() < 11){ // Είσοδος ομάδας και καταχώριση στοιχείων του παίκτη στον αντιστοιχο πίνακα
            cout << "Please input the team to which the player will belong, \"Red\" or \"Blue\"." << endl;
            bool correctTeam = false;
            do {
                cin >> team;                                            // Επιτρεπτές είσοδοι είναι μόνο οι blue και red
                if (team == "Blue" || team == "blue"){
                    Blue.setPlayer(Blue.getPlayerNum(), name, gender, age, occupation, "Blue");
                    Blue.setPlayerNum(Blue.getPlayerNum()+1);
                    Blue.meanStats();
                    correctTeam = true;
                }
                else if (team == "Red" || team == "red"){
                    Red.setPlayer(Red.getPlayerNum(), name, gender, age, occupation, "Red");
                    Red.setPlayerNum(Red.getPlayerNum()+1);
                    Red.meanStats();
                    correctTeam = true;
                }
                else
                    cout << "Incorrect Input. Please input either \"Blue\" or \"Red\"" << endl;
            }while (!correctTeam);
        }
    }
    cout << "The Player " << name << " has been successfully initialized" << endl;
}

// Συνάρτηση η οποία αναλαμβάνει την προβολή των στοιχείων και των στατιστικών μιας ομάδας, δηλαδή του χρώματος της, του ατιθμού των παικτών
// και τα ονόματά τους, τον αριθμό των νικών σε διαγωνισμούς και την μέση ηλικία, κούραση, κατάρτιση και δημοφιλία των παικτών.
void teamStats(){
    cout << "Please input which team you would like to see statistics for, Red or Blue" << endl;
    string choice;
    do{
        cin >> choice;
        if (choice == "Blue" || choice == "blue")
                Blue.printStats();
        else if (choice == "red" || choice == "Red")
            Red.printStats();
        else
            cout << "Incorrect input. Please choose one of the two teams, \"Red\" or \"Blue\"" << endl;
    }while (choice != "Blue" && choice != "blue" && choice != "red" && choice != "Red");
}

// Συνάρτηση η οποία αναλαμβάνει προβολή των στοιχείων ενός παίκτη. Η επιλογή του παίκτη μπορεί να γίνει είτε με την απευθείας εισαγωγή του
// πλήρους ονόματός του από τον χρήστη, είτε από την προβολή όλων των παικτών των ομάδων, την επιλογή της ομάδας και μετά την επιλογή του
// αριθμού του προς προβολή παίκτη.
void playerStats(){
    cout << "Would you wish to do a direct search with the player's name or would you like to see all the players and then choose?" <<endl;
    cout << "Please either type the full name directly or type \"view\" for the list of players." << endl;
    string choice;
    getchar();
    getline(cin,choice);
    if (choice == "view" || choice == "View"){
        cout << "This is a list of all the players in the competition" << endl << "   Blue Team" << endl;
        for (int i = 0; i<Blue.getPlayerNum(); i++)
            cout << i+1 << ". " << Blue.getPlayerName(i) << endl;
        cout << "   Red Team" << endl;
        for (int i = 0; i<Red.getPlayerNum(); i++)
            cout << i+1 << ". " << Red.getPlayerName(i) << endl;
        cout << "Please input the team of the player whose statistics you want to view." << endl;
        string team;
        bool correctTeam = false;
        do {
            cin >> team;
            if (team == "Blue" || team == "blue"){
                Blue.choosePlayer();
                correctTeam = true;
            }
            else if (team == "Red" || team == "red"){
                Red.choosePlayer();
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

// Συνάρτηση η οποία καλείται κατά την επιλογή της εξόδου από το πρόγραμμα από τον χρήστη. Στην περίπτωση αυτή ζητείται η επιβεβαίωση της επιλογής
// αυτής από τον χρήστη, με την εισαγωγή της συμβολοσειράς "yes". Εάν εισαχθεί σωστά, τότε το πρόγραμμα τερματίζει.
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
