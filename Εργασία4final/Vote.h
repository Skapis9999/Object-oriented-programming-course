/*����������� �����     �������� �������
  9380                  9378
  6944316621            6933251534
  ikofokots@ece.auth.gr skapetis@ece.auth.gr*/

#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

/*� ����� Vote ������������ ��� ���� ���� ������ ��� ���������� MasterChef. ���� � ����� ��������
  2 ���������� ����� string ��� ����������� voted ��� reason �� ������ ��������� �� ����� ��� ������
  ��� ��������� ��� ��������� ����� ��� ��� ���� ���������� ����������. �� ����������� ����� �����������
  ������� �������� �� � ����� ��������, ����� ��� ��������� ������� �������� ���� ��� getters ���
  setters ��� ���� ��������� ��� ������. ����� ������ ��� ��������� status ���� ��������� ��� 2 ����������
  ��� ������ ��� ������ ��� ������.*/
class Vote
{
    string voted;
    string reason;

public:

    Vote()                                  {voted = "No Player"; reason = "Because of you";}
    //�������� voted ��� reason ��� ������������ ��� voted ��� reason ��� ������
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
