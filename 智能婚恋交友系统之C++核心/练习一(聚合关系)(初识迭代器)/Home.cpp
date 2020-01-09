#include "Home.h"

Home::Home()
{
	nickname = "";
	age = 0;
	gender = man;
}

Home::Home(const string& nickname, int age, Gender_T gender)
{
	this->nickname = nickname;
	this->age = age;
	this->gender = gender;
}

Home::~Home()
{
}

void Home::Marriage(Home& spouse)//�ۺϹ�ϵ
{
	if (spouse.gender == gender) { return; }//ͬ�ԾͲ����

	this->spouse = &spouse;//�ҵ���ż=��
	spouse.spouse = this;//�����ż=��
}

void Home::divorce()
{
	if (this->spouse == NULL) { 
		cout << "���������,��ɶ����.\n";//����
			return;}

	spouse->spouse = NULL;//��ż����ż=NULL;
	spouse = NULL;//�ҵ���ż=NULL;����
}

void Home::MakeFriends(Home& friendss)
{
	friends.push_back(&friendss);
}

void Home::Break_Off_Friendship(Home& friendss)
{
	//auto x = 100;//int x=100;//C++11��������.�Զ��������ͷ���
	//����.begin();������ʱ�򷵻�һ�������ָ��,ָ���һ����Ա!!!(������)
	//����&friends[0];
	//.end();����һ��������,ָ�����һ��Ԫ�ص���һ��λ��
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &friendss) {
			//.erase();����,����ֵ��һ��������,ָ����һ����Ա
			//�ҵ�����,ʹ��erase()����ɾ������,������һ����Ա��ֵ��it
			//�൱���޷�����
			it=friends.erase(it);
		}
		else {
			it++;
		}
	}
}
/*
void Home::Break_Off_Friendship(Home& friendss)
{//ʹ�ô˷����ᴥ���ϵ�
	for (auto it = friends.begin(); it != friends.end();it++) {
		if (*it == &friendss) {
		//.erase()��������it,����it��һ����Ա,itָ��ĵط�Ϊ��
			friends.erase(it);
		}
	}
}*/

string Home::getnickname() const
{
	return nickname;
}

int Home::getage() const
{
	return age;
}

Gender_T Home::getgender() const
{
	return gender;
}

string Home::Brief_introduction() const
{
	stringstream jj;
	jj << "nickname:" << nickname << "-age:" << age << "-gender:" << (gender==man?"��":"Ů") << endl;

	return jj.str();
}

Home* Home::getspouse() const
{
	return spouse;
}

vector<Home*> Home::getfriends() const
{
	return friends;
}
