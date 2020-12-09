/* Μέρος Εργασίας των:
    Ηλία Κωφοκώτσιου      9380     ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου       9378     skapetis@ece.auth.gr
*/

#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;

// Η βασική συνάρτηση αρχικών συνθηκών. Δίδει τις προκαθορισμένες, από την εκφώνηση, τιμές σε μη τυχαία προκαθορισμένα μεγέθη όπως η κούραση και η
// δημοφιλία του παίκτη ενώ δίδει στους παίκτες ένα όνομα "default name", νίκες 0, τον συμβολισμό Ν/Α σε φύλο και επάγγελμα, και "No Team"
// στην ομάδα. Στην τεχνική κατάρτιση, δίδεται αρχικά η τιμή 0 ενώ αυτή αλλάξει σε τυχαία τιμή μεταξύ του 0 και του 80 κατά την δημιουργία ενός
// νέου παίκτη.
Player::Player(){
    skill = 0.0;
    fatigue = 0.0;
    popularity = 50.0;
    victories = 0;
    name="Default Name";
    gender="N/A";
    age=0;
    occupation="N/A";
    team = "No Team";
}

// Η συνάρτηση αρχικών συνθηκών με ορίσματα το όνομα (n), το φύλο (g), την ηλικία (a), το επάγγελμα (o) και την ομάδα (t). Δίδει στις αντίστοιχες
// μεταβλητές τις τιμές των ορισμάτων ενώ αρχικοποιεί τις πορκαθορισμένες μεταβλητές στις τιμές που αναφέρει η εκφώνηση.  Επιπλέον, κάνει αναφορά
// λανθασμένης εισόδου στην περίπτωση που ένα από τα ορίσματα είναι εκτός των επιτρεπτών τιμών.
Player::Player(string n, string g, unsigned int a, string o, string t){
    name=n;
    if (g != "Male" && g!= "male" && g != "Female" && g != "female")
       cout << "Constructor Warning: Incorrect Input for Gender" << endl;
    gender=g;
    if (a > 100)
       cout << "Constructor Warning: Incorrect Input for Age" << endl;
    age=a;
    occupation=o;
    if (t != "Blue" && t!= "blue" && t!= "Red" && t != "red")
       cout << "Constructor Warning: Incorrect Input for Team" << endl;
    team = t;
    skill = 0.0;
    fatigue = 0.0;
    popularity = 50.0;
    victories = 0;
}

// Η συνάρτηση τελικών συνθηκών απλά εμφανίζει οτι το αντικείμενο με όνομα name καταστράφηκε
Player::~Player(){
    cout << "The " << name << " Object has been succesfully destroyed" << endl;
}

// Συναρτηση set για το φύλο, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setGender(string value){
    if (value != "Male" && value!= "male" && value != "Female" && value != "female")
       cout << "Setter Warning: Incorrect Input for Gender" << endl;
    gender = value;
}

// Συναρτηση set για την ηλικία, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setAge(unsigned int value){
    if (value > 100 || value < 18)
       cout << "Setter Warning: Incorrect Input for Age" << endl;
    age= value;
}

// Συναρτηση set για την ομάδα, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setTeam(string value){
    if (value != "Blue" && value!= "blue" && value!= "Red" && value != "red")
       cout << "Setter Warning: Incorrect Input for Team" << endl;
    team = value;
}

// Συναρτηση set για την κατάρτιση, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setSkill(float value){
    if (value < 0.0 || value >100.0)
        cout << "Setter Warning: Incorrect Input for Skill." << endl;
    skill = value;
}

// Συναρτηση set για την κούραση, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setFatigue(float value){
    if (value < 0.0 || value >100.0)
        cout << "Setter Warning: Incorrect Input for Fatigue." << endl;
    fatigue = value;
}

// Συναρτηση set για την δημοφιλία, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setPopularity(float value){
    if (value < 0.0 || value >100.0)
        cout << "Setter Warning: Incorrect Input for Popularity." << endl;
    popularity = value;
}

// Συναρτηση set για τις νίκες, με αναφορά λανθασμένης εισόδου στο όρισμα
void Player::setVictories(unsigned int value){
    if (value < 0)
        cout << "Setter Warning: Incorrect Input for Victories." << endl;
    victories = value;
}

// Μια συνάρτηση που εκτυπώνει όλα τα στοιχεία του παίκτη στην οθόνη
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

// Η συνάρτηση που υλοποιεί την εργασία του παίκτη κατά την διάρκεια μιας εβδομάδας
void Player::work(){
    fatigue += (float)(rand()%21+20);
    skill *= 1.05;
    if (fatigue > 100.0)
        fatigue = 100.0;
    if (skill > 100.0)
        skill = 100.0;
}

// Η συνάρτηση που υλοποιεί την συναναστορφή του παίκτη με τους άλλους
void Player::socialize(){
    popularity = popularity + popularity*(rand()%21-10)/ (float) 100.0;
        if (popularity > 100.0 )
        popularity = 100.0;
    else if (popularity < 0.0)
        popularity = 0.0;
}

// Η συνάρτηση που υλοποιεί την επιλογή του παίκτη για την τελευταία μέρα της εβδομάδας, δηλαδή το αν θα εργαστεί ή θα ξεκουραστεί.
void Player::endOfWeekActivities(){
   int coin = rand()%2;
   if(!coin){
       cout<<"The player "<< name<<" will rest this weekend."<<endl;
       fatigue = 0.0;
   }
   else{
       cout<<"The player"<< name<<" will exercise this weekend."<<endl;
       skill += 5.0;
       if (skill >100.0)
            skill = 100.0;
   }

}

// Συνάρτηση που υλοποιεί την συμμετοχή του παίκτη σε διαγωνισμούς τύπου type
void Player::participateInCompetition (string type){
    fatigue = fatigue + fatigue *(rand()%11+10)/ (float) 100;
    if (fatigue > 100.0)
        fatigue = 100.0;
    cout<<"The player "<< name <<" took part in "<< type <<" Competition" << endl;
}

// Συνάρτηση που υλοποιεί την παρλαβή κάποιου βραβείου από τον παίκτη, τύπου type, που υποδηλώνει την νίκη του σε κάποιον διαγωνισμό.
void Player::receiveTrophy(string type){
    victories++ ;
    cout<<"The player "<< name <<" has received a trophy."<<endl;
}
