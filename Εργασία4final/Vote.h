/*Κωφοκώτσιος Ηλίας     Σκαπέτης Χρήστος
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

/*Η κλάση Vote προσομοιάζει την ψήφο κάθε παίκτη του παιχνιδιού MasterChef. Αυτή η κλάση περιέχει
  2 μεταβλητές τύπου string που ονομάζονται voted και reason οι οποίες περιέχουν το όνομα του παίκτη
  που ψηφίστηκε για αποχώρηση καθώς και τον λόγο αποχώρησης αντίστοιχα. Οι συναρτήσεις είναι συναρτήσεις
  αρχικών συνθηκών με ή χωρίς ορίσματα, καθώς και συνάρτηση τελικών συνθηκών όπως και getters και
  setters για κάθε μεταβλητή της κλάσης. Τέλος έχουμε την συνάρτηση status όπου εκτυπώνει τις 2 μεταβλητές
  της κλάσης την στιγμή της κλήσης.*/
class Vote
{
    string voted;
    string reason;

public:

    Vote()                                  {voted = "No Player"; reason = "Because of you";}
    //ορίσματα voted και reason που αντιστοιχούν στα voted και reason της κλάσης
    Vote(string voted,string reason)        {this->voted=voted; this->reason=reason;}
    ~Vote()                                 {cout << "Vote object is destroyed"<<endl;}

    void setVoted(string voted)                  {this->voted = voted;}
    void setReason(string reason)            {this-> reason= reason;}

    string getVoted()                        {return voted;}
    string getReason()                        {return reason;}

    void status()
    {
        cout << "   Player voted is " << voted <<endl;
        cout << "   Reason voted is " << reason <<endl;
    }

};

#endif // VOTE_H_INCLUDED
