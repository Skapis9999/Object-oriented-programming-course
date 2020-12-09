#include "ImmunityCompetition.h"
#include "ImmunityAward.h"

/*Constructor της ImmunityCompetition με ορίσματα τα: i το id του competition,  n το name το competition,
και το iA ένα αντικείμενο τύπου ImmunityAward*/
ImmunityCompetition::ImmunityCompetition(unsigned int i, string n, ImmunityAward iA): Competition(i,n)
{
    id=i;
    name=n;
    immunityAward.setName(iA.getName());
    immunityAward.setSolo(iA.getSolo());
    immunityAward.setVotes(iA.getVotes());
}

/*status της ImmunityCompetition. Εμφανίζει όλες τις μεταβλητές της κλάσης δηλαδή name και id του διαγωνισμού,
 καθώς και το votes και το solo του ExcursionAward */
void ImmunityCompetition::status()
{
    cout<< "Votes = "<< immunityAward.getVotes();
    cout<< "Name: "<< name;
    cout << "Competition ID: " << id << endl;
    cout<< "Solo: "<< immunityAward.getSolo();
}

/*Η συνάρτηση που υλοποιεί την συμμετοχή 2 ομάδων σε έναν διαγωνισμό ασυλίας.*/
void ImmunityCompetition::compete(Team &team)
{
    float* skillFatigue = new float[12];
    for(unsigned int j=0; j<12; j++)
    {
        skillFatigue[j]=(team.getPlayers()[j].getTechnique())*0.75+(team.getPlayers()[j].getFatigue())*0.25;
    }
    float max;
    int position;
    max=skillFatigue[0];
    position=0;
    for(unsigned int j=0; j<12; j++)
    {
        if(skillFatigue[j]>max)
        {
            max=skillFatigue[j];
            position=j;
        }
    }
}
