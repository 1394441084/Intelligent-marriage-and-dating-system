#pragma once
#include <iostream>
#include <string>
using namespace std;

class LingShi;

//妖兽类
class MonsterBeast
{
public:
	MonsterBeast(const string& species="未知",int grade=0);

	//值多少灵石
	LingShi MuchValue()const;

	friend ostream& operator<<(ostream& os, const MonsterBeast& monsterBeast);//重载<<
	bool operator==(const MonsterBeast& beast)const;//重载==

	//获取妖兽战斗力
	int getMonster()const;

private:
	string species;//种类
	int grade;//等级:1-9 
};

