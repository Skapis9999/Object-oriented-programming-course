/* Μέρος Εργασίας των:
    Ηλία Κωφοκώτσιου      9380     ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου       9378     skapetis@ece.auth.gr
*/

#include "Team.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>

// Η συνάρτηση αρχικών συνθηκών χωρίς ορίσματα. Αρχικοποιεί το χρώμα στην τιμή "No Colour", τον αριθμό των παικτών σε 0, τις νίκες σε 0 και
// τις μέσες τιμές των στατιστικών και αυτές στο 0. Επιπλέον, γίνεται δυναμική δέσμευση μνήμης για έναν πίνακα τύπου Player, μεγέθους 11 θέσεων.
Team::Team(){
    colour = "No Colour";
    teamPlayerNum = 0;
    teamPlayers = new Player[11];
    victories = 0;
    meanAge = 0;
    meanFatigue = 0;
    meanSkill = 0;
    meanPopularity = 0;
}

// Η συνάρτηση αρχικών συνθηκών με ορίσματα το χρώμα (col), τον αριθμό των καταχωρηθέντων παικτών (num) και τον αριθμό των νικών σε
// διαγωνισμούς. Οι μέσες τιμές των στατιστικών αρχικοποιούνται στο 0. Επιπλέον, γίνεται δυναμική δέσμευση μνήμης για έναν πίνακα τύπου
// Player, μεγέθους 11 θέσεων. Στην περίπτωση που κάποιο από τα ορίσματα είναι εκτός των επιτρεπτών ορίων, εκτυπώνεται το αντίστοιχο σφάλμα.
Team::Team(string col, int num, int wins){
    if (col != "Blue" && col!= "blue" && col!= "Red" && col != "red")
       cout << "Constructor Warning: Incorrect Input for Colour" << endl;
    colour = col;
    if (num < 0 || num > 11)
        cout << "Constructor Warning: Incorrect Input for PlayerNum." << endl;
    teamPlayerNum = num;
    teamPlayers = new Player [11];
    if (wins < 0)
        cout << "Constructor Warning: Incorrect Input for Victories." << endl;
    victories = wins;
    meanAge = 0;
    meanFatigue = 0;
    meanSkill = 0;
    meanPopularity = 0;
}

// Η συνάρτηση τελικών συνθηκών της κλάσης. Απελευθερώνεται η δεσμευμένη μνήμη του πίνακα και εκτυπώνεται η αναφορά καταστροφής του αντικειμένου.
Team::~Team(){
    delete[] teamPlayers;
    cout << "The " << colour << " team object was destroyed successfully" << endl;
}

// Συναρτηση set για τον αριθμό των παικτών, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setPlayerNum(int num){
    if (num < 0 || num > 11)
        cout << "Setter Warning: Incorrect Input for PlayerNum." << endl;
    teamPlayerNum = num;
}

// Συναρτηση set για τις νίκες, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setVictories(int wins){
    if (wins < 0)
        cout << "Setter Warning: Incorrect Input for Victories." << endl;
    victories = wins;
}

// Συναρτηση set για παίκτη της ομάδας. Τα ορίσματα είναι, με σειρά γραφής, το όνομα, το φύλο, η ηλικία, το επάγγελμα και η ομάδα. Καλείται
// για κάθε περίπτωση η αντίστοιχη συνάρτηση set του παίκτη. Σε αυτό το σημείο δίδεται και η τυχαία τιμή στην τεχνική κατάρτιση του παίκτη.
void Team::setPlayer(int n, string name, string gender, unsigned int age, string occupation, string team){
    teamPlayers[n].setName(name);
    teamPlayers[n].setGender(gender);
    teamPlayers[n].setAge(age);
    teamPlayers[n].setOccupation(occupation);
    teamPlayers[n].setTeam(team);
    teamPlayers[n].setSkill(rand()%81);
}

// Συναρτηση set για την μέση κατάρτιση, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setMeanSkill(float val){
    if (val < 0 || val > 100)
        cout << "Setter Warning: Incorrect Input for meanSkill" << endl;
    meanSkill = val;
}

// Συναρτηση set για την μέση δημοφιλία, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setMeanPopularity(float val){
    if (val < 0 || val > 100)
        cout << "Setter Warning: Incorrect Input for meanPopularity" << endl;
    meanPopularity = val;
}

// Συναρτηση set για την μέση ηλικία, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setMeanAge(float val){
    if (val < 0 || val > 100)
        cout << "Setter Warning: Incorrect Input for meanAge" << endl;
    meanAge = val;
}

// Συναρτηση set για την μέση κούραση, με αναφορά λανθασμένης εισόδου στο όρισμα
void Team::setMeanFatigue(float val){
    if (val < 0 || val > 100)
        cout << "Setter Warning: Incorrect Input for meanFatigue" << endl;
    meanFatigue = val;
}

// Συνάρτηση που επικαιροποιεί τις μέσες τιμές των στατιστικών, που θα καλείται κάθε φορά που υπάρχει μεταβολή τους.
void Team::meanStats(){
    meanAge = 0;
    meanFatigue = 0;
    meanPopularity = 0;
    meanSkill = 0;
    for (int i=0; i<teamPlayerNum; i++){
        meanAge += teamPlayers[i].getAge();
        meanFatigue += teamPlayers[i].getFatigue();
        meanSkill += teamPlayers[i].getSkill();
        meanPopularity += teamPlayers[i].getPopularity();
    }
    meanAge /= teamPlayerNum;
    meanFatigue /= teamPlayerNum;
    meanPopularity /= teamPlayerNum;
    meanSkill /= teamPlayerNum;
}

// Συνάρτηση που εκτυπώνει τα στατιστικά της ομάδας, όπως τον αριθμό και το όνομα των παικτών, τον αριθμό των νικών και τις μέσες τιμές των
// στατιστικών των παικτών
void Team::printStats(){
    cout << endl << colour << " Team: " << endl << " Number of Players: " << teamPlayerNum << endl;
    cout << "  Players who belong to this team: " << endl;
    for (int i=0; i< teamPlayerNum; i++)
        cout << teamPlayers[i].getName() << endl;
    cout << "This team has a total of " << victories << " Victories in Competitions." << endl;
    cout << "This team's players have a mean age of: " << meanAge << endl;
    cout << "This team's players have a mean skill of: " << meanSkill << endl;
    cout << "This team's players have a mean popularity of: " << meanPopularity << endl;
    cout << "This team's players have a mean fatigue of: " << meanFatigue << endl << endl;
}

// Συνάρτηση που επιλέγει κάποιον παίκτη από τον πίνακα, δεδομένου οτι ο χρήστης γνωρίζει την θέση του παίκτη στον αντίστοιχο πίνακα,
// για να γίνει η εκτύπωση των στοιχείων του. Καλείται πάντα από την συνάρτηση PlayerStats του αρχείου main.cpp, ώστε ο παίκτης να γνωρίζει
// τις θέσεις των παικτών στον πίνακα.
void Team::choosePlayer(){
    cout << "Please enter the number of the player." << endl;
    unsigned short ch;
    do{
        cin >> ch;
        if (ch <= teamPlayerNum && ch > 0)
            teamPlayers[ch-1].printStats();
        else
            cout << "Incorrect choice. Please input a number between 1 and " << teamPlayerNum << endl;
    }while (ch > teamPlayerNum || ch < 0);
}
