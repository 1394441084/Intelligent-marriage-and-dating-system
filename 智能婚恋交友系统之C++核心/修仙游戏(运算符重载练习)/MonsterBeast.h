#pragma once
#include <iostream>
#include <string>
using namespace std;

class LingShi;

//������
class MonsterBeast
{
public:
	MonsterBeast(const string& species="δ֪",int grade=0);

	//ֵ������ʯ
	LingShi MuchValue()const;

	friend ostream& operator<<(ostream& os, const MonsterBeast& monsterBeast);//����<<
	bool operator==(const MonsterBeast& beast)const;//����==

	//��ȡ����ս����
	int getMonster()const;

private:
	string species;//����
	int grade;//�ȼ�:1-9 
};

