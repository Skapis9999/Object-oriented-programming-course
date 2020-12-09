/*Κωφοκώτσιος Ηλίας     Σκαπέτης Χρήστος
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#include "Voting.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Δηλώνονται τα static χαρακτηριστικά της κλάσης ώστε να μπορούν να χρησιμοποιηθούν.
vector <Vote> Voting::votes;
map <string, int> Voting::results;

/*Συνάρτηση printVotes που τυπώνει το διάνυσμα με όλες τις ψήφους που κατατέθηκαν κατά την διάρκεια του Συμβουλίου, καλώντας την
  συνάρτηση status της κλάσης Vote. */
void Voting::printVotes()
{
    cout << " The votes are: " << endl;
    for (unsigned int i=0; i < votes.size(); i++)
        votes[i].status();
}

/*Η συνάρτηση strV(strategic vote) είναι υπεύθυνη για την επιλογή του παίκτη που θα ψηφιστεί κάθε φορά που καλείται ένας παίκτης
  να λάβει μια τέτοια απόφαση. Επιστρέφει κάθε φορά την θέση στον πίνακα των ομάδων του παίκτη που έχει την μέγιστη ή ελάχιστη
  τιμή στο χαρακτηριστικό technique ή popularity. Δέχεται ορίσματα μια τιμή του enum Reason
  καθώς και την ομάδα που συμμετέχει στην ψηφοφορία. Εκμεταλλευόμενοι την αλγεβρική φύση
  του enum, χρησιμοποιώντας τους τελεστές % (υπόλοιπο) και / (πηλίκο) υπολογίζουμε το μέγιστο και το ελάχιστο της τεχνικής
  ή της δημοφιλίας, ότι απαιτείται, και επιστρέφουμε αυτό που ζητήθηκε. Αν a%2 == 0 σημαίνει πως είναι ζυγός
  αριθμός δηλαδή ότι ζητάει ή min ή max Technique αλλιώς είναι μονός που σημαίνει πως
  ζητάει ή min ή max του skill. Με τυπικό αλγόριθμο μεγίστου ελαχίστου υπολογίζονται τα ζητούμενα.
  Τέλος, αν το !(a/2) είναι 1 (false) τυπώνεται η min αλλιώς η max.  */
int Voting::strV(Reason a, Team &team)
{
    int maxIndex = 0, minIndex = 0;
    if (a%2 == 0)
    {
        for (int i=1; i<11; i++)
            if (team.getPlayers()[i].getAge())
            {
                if (team.getPlayers()[i].getTechnique() < team.getPlayers()[minIndex].getTechnique())
                    minIndex = i;
                if (team.getPlayers()[i].getTechnique() > team.getPlayers()[maxIndex].getTechnique())
                    maxIndex = i;
            }
    }
    else
    {
        for (int i=1; i<11; i++)
            if (team.getPlayers()[i].getAge())
            {
                if (team.getPlayers()[i].getPopularity() < team.getPlayers()[minIndex].getPopularity())
                    minIndex = i;
                if (team.getPlayers()[i].getPopularity() > team.getPlayers()[maxIndex].getPopularity())
                    maxIndex = i;
            }
    }
    if (!(a/2))
        return minIndex;
    return maxIndex;
}
/*H createVote δημιουργεί την ψήφο ενός παίκτη και την καταχωρεί στον δυναμικό πίνακα (Vector) των ψήφων.
  Δέχεται ως ορίσματα την ομάδα που ψηφίζει και έναν int που λέγεται index που είναι η θέση του παίκτη που
  ψηφίζει την στιγμή της κλήσης της συνάρτησης. Ο πίνακας reasonString περιέχει τους λόγους αποχώρησης
  που θα τυπώνονται. Με την while και με την if εξασφαλίζουμε ότι θα επιλεχθεί έναν παίκτης για να ψηφισθεί
  και δεν θα ψηφίσει ο παίκτης τον εαυτό του, κάποιον παίκτη που έχει φύγει ή κάποιον παίκτη που έχει ασυλία.
  Με την rand λαμβάνουμε έναν τυχαίο αριθμό από το 0 μέχρι το 10. Ανάλογα με τον αριθμό αυτό, υπάρχουν άνισες
  πιανότητες προκειμένου να επιλεχθεί η στρατηγική της ψήφου. Έτσι παράλληλα με τον παράγοντα της τύχης στην ψηφοφορία
  οι παίκτες θα ακολουθούν κάποια στρατηγική, όπως να ψηφίσουν τον λιγότερο ικανό παίκτη, κτλ. */
void Voting::createVote(Team &team, int index)
{
    bool check = false;
    Reason r;
    int choice;
    string reasonString[5]={"The player has the worst technique. They deserve to leave the game.",
                            "Everybody hates the player. They deserve to leave.",
                            "Their skill has given the player leadership tendencies.",
                            "They are too popular. I hate them.",
                            "Absolutely no reason at all"};
    while(!check)
    {
        choice = rand()%11;
        if (choice <=2){
            r = lowTechnique;
            choice = strV(r, team);
        }
        else if (choice <=5){
            r = lowPopularity;
            choice = strV(r, team);
        }
        else if (choice <=7){
            r = highTechnique;
            choice = strV(r, team);
        }
        else if (choice <=9){
            r = highPopularity;
            choice = strV(r, team);
        }
        else{
            r = random;
            choice = rand()%11;
        }
        check = true;
        if (choice == index)
            check = false;
        else if (!team.getPlayers()[choice].getAge())
            check = false;
        else if (team.getPlayers()[choice].getImmunity() == true)
            check = false;
    }
    votes.push_back(Vote(team.getPlayers()[choice].getName(), reasonString[r]));
}


// Συνάρτηση που τύπωνει όλα τα ζεύγη κλειδιού - τιμής που περιέχει ο χάρτης την στιγμή της κλήσης. Εκτυπώνονται δηλαδή
// όλα τα ονόματα που ψηφίστηκαν και οι ψήφοι του καθένα.
void Voting::printResults()
{
    map<string, int>::iterator p = results.begin();
    cout << " Voting Results: " << endl;
    for (; p!=results.end(); p++)
        cout << "   Player: " << p->first << "   Number of Votes: " << p->second << endl;
}

/*Η votingProcess είναι και η συνάρτηση με την μεγαλύτερη δυσκολία και το μεγαλύτερο
 μέγεθος. Υλοποιεί την όλη διαδικασία της ψηφοφορίας. Δέχεται ως όρισμα μόνο την ομάδα
 που συμμετέχει την ψηφοφορία. Αρχικά, με μια while καλείται η συνάρτηση createVote για κάθε παίκτη,
 προκειμένου να ψηφίζσυν όσοι παίκτες δεν έχουν αποχωρήσει από το παιχνίδι (δηλαδή όποιος έχει ηλικία
 διάφορη του 0). Στην συνέχεια εκτυπώνονται οι ψήφοι. Στην συνέχεια, για κάθε ψήφο, γίνεται έλεγχος
 έαν υπάρχει ήδη το κλειδί στον χάρτη. Εάν ναι, τότε αυαξάνεται η τιμή του κλειδιού κατά ένα. Αλλιώς το
 κλειδί προστίθεται και ξεκινάει με μια ψήφο. Τυπώνονται τα αποτελέσματα. Μετά με κατάλληλο αλγόριθμο
 βρίσκονται οι δύο παίκτες με τις περισσότερες ψήφους, γίνονται υποψήφιοι για αποχώρηση και φεύγει ο
 χειρότερος. Τέλος καθαρίζονται ψήφοι και αποτελέσματα.
 */

void Voting::votingProcess(Team &team)
{
    srand(time(NULL));  // Για τυχαιότητα αριθμών
    int i=0, j=0;       // i για να μετρώνται οι παίκτες, j για να μετρώνται οι ψήφοι του καθενός
    while (team.getNumberOfPlayers()-i)
    {
        if (team.getPlayers()[i].getAge())
            for (int k=1; k<=team.getPlayers()[i].getVotes(); k++)
            {
                createVote(team, i);
                j++;
            }
        i++;
    }

    printVotes();
    for (i=0; i<j; i++)  // i για την καταμέτρηση των ψήφων που έχουν καταχωρηθεί.
    {
        if (results.count(votes[i].getVoted()))
        {
            map<string, int>::iterator p = results.find(votes[i].getVoted());
            p->second++;
        }
        else
            results.insert(pair <string, int>(votes[i].getVoted(), 1));
    }
    printResults();

    int index[2];
    map<string, int>::iterator p, max = results.begin();
    for (p=results.begin(); p!=results.end(); p++)
        if(p->second > max->second)
            max = p;
    pair <string, int> fMVP = *max;  // First most voted player
    results.erase(max);
    max = results.begin();
    for (p=results.begin(); p!=results.end(); p++)
        if(p->second > max->second)
            max = p;
    pair <string, int> sMVP = *max; // Second most voted player
    for (i=0; i<team.getNumberOfPlayers(); i++)
    {
        if (fMVP.first == team.getPlayers()[i].getName())
            index[0] = i;
        if (sMVP.first == team.getPlayers()[i].getName())
            index[1] = i;
    }
    team.getPlayers()[index[0]].setCandidate(true);
    team.getPlayers()[index[1]].setCandidate(true);
    if (team.getPlayers()[index[0]].getTechnique() < team.getPlayers()[index[1]].getTechnique())
    {
        cout << " The player to leave the game is: " << endl;
        team.getPlayers()[index[0]].status();
        team.removePlayer(team.getPlayers()[index[0]].getName());
    }
    else if (team.getPlayers()[index[0]].getTechnique() > team.getPlayers()[index[1]].getTechnique())
    {
        cout << " The player to leave the game is: " << endl;
        team.getPlayers()[index[1]].status();
        team.removePlayer(team.getPlayers()[index[1]].getName());
    }
    else
    {
        cout << " The player to leave the game is: " << endl;
        team.getPlayers()[index[1]].status();
        team.removePlayer(team.getPlayers()[index[rand()%2]].getName());
    }
    votes.clear();
    results.clear();
}
