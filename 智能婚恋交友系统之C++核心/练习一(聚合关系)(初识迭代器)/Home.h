#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>

using namespace std;

typedef enum Gender {
	man,	//����
	women	//Ů��
}Gender_T;

class Home
{
public:
	Home();//Ĭ�Ϲ��캯��
	Home(const string& nickname, int age, Gender_T gender);//�ǳ�,����,�Ա�
	~Home();//��������

	void Marriage(Home &spouse);//���,�ۺϹ�ϵ
	void divorce();//���
	void MakeFriends(Home &friendss);//����
	void Break_Off_Friendship(Home& friendss);//�Ͻ�
	string getnickname()const;//ѯ���ǳ�
	int getage()const;//ѯ������
	Gender_T getgender()const;//ѯ���Ա�
	string Brief_introduction()const;//���Ҽ��
	Home* getspouse()const;//ѯ����ż��˭
	vector<Home*> getfriends()const;//ѯ��������˭

private:
	string nickname;//�ǳ�
	int age;//����
	Gender_T gender;//�Ա�
	Home* spouse=NULL;//��ż,����һ������ָ��
	vector<Home*>friends;//����,����vector���ڱ��ݹ�ϵ,������ָ��
};

