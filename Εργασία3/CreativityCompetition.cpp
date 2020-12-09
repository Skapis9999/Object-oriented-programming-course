#include "CreativityCompetition.h"

using namespace std;

string allIngredients[51] = {"Beef", "Pork", "Chicken", "Duck", "Veal", "Lamb", "Rabbit", "Octopus", "Squid", "Oysters", "Crab", "Lobster", "Tuna",
                           "Codfish", "Salmon", "Swordfish", "Tomato", "Pepper", "Cucumber", "Lettuce", "Broccoli", "Olives", "Beetroot",
                           "Potato", "Eggplant", "Zucchini", "Artichoke", "Corn", "Onions", "Mushrooms", "Apple", "Pear", "Pineapple", "Orange"
                           "Avocado", "Noodles", "Taglietelles", "Spaghetti", "Rice", "Orzo", "Cous-Cous", "Basil", "Wine", "Cognac", "Parsley"
                           "Spearmint", "Dill", "Celery", "Fennel", "Oregano", "Marjoram"};

//Constructor της CreativityCompetition χωρίς ορίσματα
CreativityCompetition::CreativityCompetition(){
    id = 0;
    name = "";
    winner = "";
}

//Constructor της CreativityCompetition με ορίσματα τα: i το id του competition,  n το name το competition, και το eA ένα αντικείμενο τύπου ExcursionAward
CreativityCompetition::CreativityCompetition(unsigned int i, string n, ExcursionAward eA): Competition(i,n){
    excursionAward.setName(eA.getName());
    excursionAward.setSolo(eA.getSolo());
}

/*status της CreativityCompetition. Εμφανίζει όλες τις μεταβλητές της κλάσης δηλαδή name και id του διαγωνισμού,
 τα ingridients από τον πίνακα ingredients[]  καθώς και το name και το solo του ExcursionAward */
void CreativityCompetition::status(){
    cout << "Creativity Competition" << endl << "Name: " << name << endl;
    cout << "Competition ID: " << id << endl;
    cout << "The ingredients available for this competition are: " << endl;
    for (int i=0; i<10; i++)
        cout << "\t" << ingredients[i] << endl;
    cout << "Award: Excursion Award" << endl;
    cout << "Award Name: " << excursionAward.getName() << endl;
    cout << "Award Type: Solo" << endl;
}

/*Η συνάρτηση που υλοποιεί την συμμετοχή 2 ομάδων σε έναν διαγωνισμό δημιουργικότητας.Έχει ως ορίσματα  τις δυο ομάδες με όλους τους παίκτες. Με μια for γεμίζετε ένας πίνακας με 10 τυχαία ingredients,
τα οποία ελέγχονται ώστε να είναι διαφορετικά. Ένας πίνακας στην συνέχεια χειρίζεται όλους τους παίκτες. Ακουλουθεί μια for η οποία βγάζει τον
νικητή σύμφωνα με τον ψευδοκώδικα που μας δόθηκε. Τέλος, τυπώνεται το status του νικητή παίκτη καθώς και λαμβάνει τα bonus και τις ποινές σε τεχνική
και δημοφιλία σύμφωνα με τον ψευδοκώδικα */
void CreativityCompetition::compete(Team &team1, Team &team2){
    for (int i=0; i<10; i++){
        bool different = true;
        int num;
        do{
             num = rand()%51;
            for (int j=0; j<i; j++)
                different = different && (ingredients[j] != allIngredients[num]);
        }while(!different);
        ingredients[i] = allIngredients[num];
    }
    Player *players[2] = {team1.getPlayers(), team2.getPlayers()};
    float maxTechnique = -1;
    int maxIndex = -1, playerIndex =0;
    for (; playerIndex<22; playerIndex++){
        float technique = players[playerIndex%2][playerIndex/2].getTechnique();
        if (technique > maxTechnique){
            maxTechnique = technique;
            maxIndex = playerIndex;
        }
    }
    Player* winner = &players[maxIndex%2][maxIndex/2];
    winner->status();
    winner->setTechnique(winner->getTechnique()+ excursionAward.getTechniqueBonus());
    winner->setPopularity(winner->getPopularity()+ excursionAward.getPopularityPenalty());
}
