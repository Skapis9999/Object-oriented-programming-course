/*����������� �����     �������� �������
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#include "Voting.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//���������� �� static �������������� ��� ������ ���� �� ������� �� ���������������.
vector <Vote> Voting::votes;
map <string, int> Voting::results;

/*��������� printVotes ��� ������� �� �������� �� ���� ��� ������ ��� ����������� ���� ��� �������� ��� ����������, �������� ���
  ��������� status ��� ������ Vote. */
void Voting::printVotes()
{
    cout << " The votes are: " << endl;
    for (unsigned int i=0; i < votes.size(); i++)
        votes[i].status();
}

/*� ��������� strV(strategic vote) ����� �������� ��� ��� ������� ��� ������ ��� �� �������� ���� ���� ��� �������� ���� �������
  �� ����� ��� ������ �������. ���������� ���� ���� ��� ���� ���� ������ ��� ������ ��� ������ ��� ���� ��� ������� � ��������
  ���� ��� �������������� technique � popularity. ������� �������� ��� ���� ��� enum Reason
  ����� ��� ��� ����� ��� ���������� ���� ���������. ���������������� ��� ��������� ����
  ��� enum, ��������������� ���� �������� % (��������) ��� / (������) ������������ �� ������� ��� �� �������� ��� ��������
  � ��� ����������, ��� ����������, ��� ������������ ���� ��� ��������. �� a%2 == 0 �������� ��� ����� �����
  ������� ������ ��� ������ � min � max Technique ������ ����� ����� ��� �������� ���
  ������ � min � max ��� skill. �� ������ ��������� �������� ��������� ������������� �� ���������.
  �����, �� �� !(a/2) ����� 1 (false) ��������� � min ������ � max.  */
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
/*H createVote ���������� ��� ���� ���� ������ ��� ��� ��������� ���� �������� ������ (Vector) ��� �����.
  ������� �� �������� ��� ����� ��� ������� ��� ���� int ��� ������� index ��� ����� � ���� ��� ������ ���
  ������� ��� ������ ��� ������ ��� ����������. � ������� reasonString �������� ���� ������ ����������
  ��� �� ����������. �� ��� while ��� �� ��� if ������������� ��� �� ��������� ���� ������� ��� �� ��������
  ��� ��� �� ������� � ������� ��� ����� ���, ������� ������ ��� ���� ����� � ������� ������ ��� ���� ������.
  �� ��� rand ���������� ���� ������ ������ ��� �� 0 ����� �� 10. ������� �� ��� ������ ����, �������� ������
  ���������� ����������� �� ��������� � ���������� ��� �����. ���� ��������� �� ��� ��������� ��� ����� ���� ���������
  �� ������� �� ���������� ������ ����������, ���� �� �������� ��� �������� ����� ������, ���. */
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


// ��������� ��� ������� ��� �� ����� �������� - ����� ��� �������� � ������ ��� ������ ��� ������. ������������ ������
// ��� �� ������� ��� ���������� ��� �� ����� ��� ������.
void Voting::printResults()
{
    map<string, int>::iterator p = results.begin();
    cout << " Voting Results: " << endl;
    for (; p!=results.end(); p++)
        cout << "   Player: " << p->first << "   Number of Votes: " << p->second << endl;
}

/*� votingProcess ����� ��� � ��������� �� ��� ���������� �������� ��� �� ����������
 �������. �������� ��� ��� ���������� ��� ����������. ������� �� ������ ���� ��� �����
 ��� ���������� ��� ���������. ������, �� ��� while �������� � ��������� createVote ��� ���� ������,
 ����������� �� �������� ���� ������� ��� ����� ���������� ��� �� �������� (������ ������ ���� ������
 ������� ��� 0). ���� �������� ������������ �� �����. ���� ��������, ��� ���� ����, ������� �������
 ��� ������� ��� �� ������ ���� �����. ��� ���, ���� ���������� � ���� ��� �������� ���� ���. ������ ��
 ������ ����������� ��� �������� �� ��� ����. ���������� �� ������������. ���� �� ��������� ���������
 ���������� �� ��� ������� �� ��� ������������ ������, �������� ��������� ��� ��������� ��� ������ �
 ����������. ����� ������������ ����� ��� ������������.
 */

void Voting::votingProcess(Team &team)
{
    srand(time(NULL));  // ��� ���������� �������
    int i=0, j=0;       // i ��� �� ��������� �� �������, j ��� �� ��������� �� ����� ��� �������
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
    for (i=0; i<j; i++)  // i ��� ��� ����������� ��� ����� ��� ����� �����������.
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
