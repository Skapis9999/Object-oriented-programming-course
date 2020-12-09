/* Μέρος Εργασίας των:
    Ηλία Κωφοκώτσιου      9380     ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου       9378     skapetis@ece.auth.gr
*/

#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include "Player.h"
#include <string>

// Κλάση που καλύπτει τις ανάγκες των ομάδων. Οι μεταβλητές της κλάσης αυτής είναι, κατά σειρά γραφής, το χρώμα, ο αριθμός των παικτών που έχουν καταχωρηθεί,
// ένας δείκτης - πίνακας για τους 11 παίκτες της ομάδας (είτε έχουν καταχωρηθεί τα σοιχεία τους είτε όχι), ο αριθμός των νικών, η μέση ηλικία των παικτών, η μέση κατάρτιση,
// η μέση κούραση και η μέση δημοφιλία.
class Team {
    string colour;
    int teamPlayerNum;
    Player *teamPlayers;
    unsigned int victories;
    float meanAge;
    float meanSkill;
    float meanFatigue;
    float meanPopularity;

public:
    // Δυο συναρτήσεις αρχικών συνθηκών, με και χωρίς παραμέτρους και η συνάρτηση τελικών συνθηκών της κλάσης
    Team();
    // Οι παράμετροι εδώ είναι το χρώμα, ο αριθμός των καταχωρηθέντων παικτών και ο αριθμός των νικών, γιατί οι μέσοι δείκτες των υπόλοιπων χαρακτηριστικών της
    // ομάδας μεταβάλλονται ανάλογα με τα στοιχεία των παικτών, και άρα δεν υπόκεινται σε διαφορετική αρχικοποιήση.
    Team(string col, int num, int wins);
    ~Team();

    // Ακολουθούν όλες οι συναρτήσεις get/set για όλες τις μεταβλητές της κλάσης. Οι συναρτήσεις set παίρνουν ως όρισμα κάθε φορά την νέα τιμή
    // της εκάστοτε μεταβλητής. Ειδικά για τον πίνακα δεν γράφτηκε τέτοιο ζεύγος συναρτήσεων. Αντίθετα, γράφτηκε σετ συναρτήσεων που μεταβάλλουν ή επιστρέφουν
    // τα στοιχεία - στατιστικά ενός παίκτη του πίνακα.
    string getColour()                   {return colour;};
    void setColour(string c)             {colour = c;};

    int getPlayerNum()                   {return teamPlayerNum;};
    void setPlayerNum(int num);

    int getVictories()                   {return victories;};
    void setVictories(int wins);

    float getMeanSkill()                 {return meanSkill;};
    void setMeanSkill(float val);

    float getMeanAge()                   {return meanAge;};
    void setMeanAge(float val);

    float getMeanFatigue()               {return meanFatigue;};
    void setMeanFatigue(float val);

    float getMeanPopularity()            {return meanPopularity;};
    void setMeanPopularity(float val);

    void setPlayer(int n, string name, string gender, unsigned int age, string occupation, string team);
    string getPlayerName(int n)          {return teamPlayers[n].getName();};
    // Εκτυπώνει τα στοιχεία του παίκτη στην θέση n του πίνακα
    void printPlayer(int n)              {teamPlayers[n].printStats();};

    // Πρόκειται για συνάρτηση καλούμενη από την playerStats του αρχείου main.cpp, που εξυπηρετεί στην αναζήτηση κάποιου παίκτη στον πίνακα της ομάδας
    // και στην συνέχεια στην εκτύπωση των στοιχείων του
    void choosePlayer();

    // Συνάρτηση που ανανεώνει τους μέσους όρους των στατιστικών των παικτών της ομάδας. Καλείται κάθε φορά που αυτά υπόκεινται μεταβολή.
    void meanStats();

    // Συνάρτηση που κάνει εκτύπωση των στοιχείων της ομάδας, δηλαδή τον αριθμό και τα ονόματα των παικτών, τους μέσους όρους των στατιστικών τους και τον αριθμό
    // των νικών της ομάδας.
    void printStats();
};


#endif // TEAM_H_INCLUDED
