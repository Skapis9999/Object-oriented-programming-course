/*����������� �����     �������� �������
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

//���������� �� ����� �� �������������� ���� ��������� createVote �� ��� ���� ���������� ����� ��� ���������
enum Reason{lowTechnique, lowPopularity, highTechnique, highPopularity, random};

/*� ����� voting ������������ ��� ���������� ���������� ��� ���������� ��� MasterChef
  ��� �� �������������� ��� ����� static ���� �������� ��� ���������� ���� �� ����������� ��
  ������ �� �������������. ������ ������ ��� ������� vector (�������� ������) ����� Vote ����� ��� ��� �������
  map (�����) �� ������� ����� string ��� ����� ����� int �� ����� ���������� ����� �� ������� ��� ������� ���
  ���������� ��� �� ����� ��� ����������� � ������� ����������. � ��������� ��� �����������
  ��������� ��� ������ Voting.cpp ���� ��������.*/
class Voting
{
    static vector <Vote> votes;
    static map < string, int> results;
public:
    /* ��� ������� �������� �� ������� ����������� ������� ��� ������� ��������, ����� ������ ���� �� ����������
       ��� �� ����������� ����� ��������, ������� �� ������� ��� ����� �� ������������ ����������� ��� ������ Voting.
       ��������, ��� ����������� ���� ��������� getters ��� setters, ����� ��� ��������� �� ����������� �����. */
    static void votingProcess(Team &team);
    static void printVotes();
    static void printResults();
    static void createVote(Team &team, int index);
    static int strV(Reason a, Team &team);
} ;

#endif // VOTING_H_INCLUDED

