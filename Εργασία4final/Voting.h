/*Κωφοκώτσιος Ηλίας     Σκαπέτης Χρήστος
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

#include "Vote.h"
#include "Team.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

//Απαρίθμηση το οποίο θα χρησιμοποιηθεί στην συνάρτηση createVote ως τον λόγο αποχώρησης αυτού που ψηφίστηκε
enum Reason{lowTechnique, lowPopularity, highTechnique, highPopularity, random};

/*Η κλάση voting προσομοιάζει την διαδικασία ψηφοφορίας του παιχνιδιού του MasterChef
  Όλα τα χαρακτηριστικά της είναι static όπως ζητήθηκε και αντίστοιχα όλες οι συναρτήσεις οι
  οποίες τα χρησιμοποιούν. Αρχικά έχουμε ένα στατικό vector (δυναμικό πίνακα) τύπου Vote καθώς και ένα στατικό
  map (χάρτη) με κλειδιά τύπου string και τιμές τύπου int το οποίο ουσιαστικά είναι τα ονόματα των παικτών που
  ψηφίστηκαν και οι ψήφοι που συγκέντρωσε ο καθένας αντίστοιχα. Η επεξήγηση των συναρτήσεων
  βρίσκεται στο αρχείο Voting.cpp λόγω μεγέθους.*/
class Voting
{
    static vector <Vote> votes;
    static map < string, int> results;
public:
    /* Δεν κρίθηκε αναγκαίο να γραφούν συναρτήσεις αρχικών και τελικών συνθηκών, διότι εφόσον όλες οι μεταβλητές
       και οι συναρτήσεις είναι στατικές, μπορούν να κληθούν και χωρίς να δημιουργηθεί αντικείμενο την κλάσης Voting.
       Επιπλέον, δεν χρειάστηκαν στην υλοποίηση getters και setters, οπότε δεν γράφτηκαν οι συναρτήσεις αυτές. */
    static void votingProcess(Team &team);
    static void printVotes();
    static void printResults();
    static void createVote(Team &team, int index);
    static int strV(Reason a, Team &team);
} ;

#endif // VOTING_H_INCLUDED

