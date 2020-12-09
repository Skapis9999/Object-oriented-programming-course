/* Μέρος Εργασίας των:
    Ηλία Κωφοκώτσιου      9380     ikofokots@ece.auth.gr
    Σκαπέτη Χρήστου       9378     skapetis@ece.auth.gr
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
using namespace std;

// Κλάση που καλύπτει τις ανάγκες των παικτών. Οι μεταβλητές της κλάσης αυτής είναι, κατά σειρά γραφής, το όνομα του παίκτη, το φύλο,
// η ηλικία, το επάγγελμα, η τεχνική κατάρτιση, η κούραση, η δημοφιλία, οι νίκες στους διαγωνισμούς καθώς και η ομάδα
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
        // Δυο συναρτήσεις αρχικών συνθηκών, με και χωρίς παραμέτρους και η συνάρτηση τελικών συνθηκών της κλάσης
        Player();
        // Επειδή κάποια στοιχεία, όπως πχ η κούραση, έχουν πολύ συγκεκριμένες τιμές κατά την δημιουργία ενός παίκτη, η συνάρτηση αρχικών συνθηκών
        // παίρνει ως ορίσματα μόνο το όνομα (n), το φύλο (g), την ηλικία (a), το επάγγελμα (o) και την ομάδα του παίκτη (t)
        Player(string n, string g, unsigned int a, string o, string t);
        ~Player();

        // Ακολουθούν όλες οι συναρτήσεις get/set για όλες τις μεταβλητές της κλάσης. Οι συναρτήσεις set παίρνουν ως όρισμα κάθε φορά την νέα τιμή
        // της εκάστοτε μεταβλητής
        string getName()                       {return name;};
        void setName(string value)             {name = value;};

        string getGender()                     {return gender;};
        void setGender(string value);

        unsigned int getAge()                  {return age;};
        void setAge (unsigned int value);

        string getOccupation()                 {return occupation;};
        void setOccupation(string value)       {occupation = value;};

        float getSkill()                       {return skill;};
        void setSkill(float value);

        float getFatigue()                     {return fatigue;};
        void setFatigue(float value);

        float getPopularity()                  {return popularity;};
        void setPopularity(float value);

        unsigned int getVictories()            {return victories;};
        void setVictories(unsigned int value);

        string getTeam()                       {return team;};
        void setTeam(string value);

        // Μια συνάρτηση που εκτυπώνει όλα τα στοιχεία του παίκτη στην οθόνη
        void printStats();

        // Οι συναρτήσεις που περιγράφουν τις δυνατότητες του παίκτη, όπως αυτές αναγράφονται μέσα στο κείμενο της εκφώνησης. (βλ. Player.cpp)
        void work();
        void socialize();
        void endOfWeekActivities();
        void participateInCompetition(string type);
        void receiveTrophy(string type);
};

#endif // PLAYER_H_INCLUDED
