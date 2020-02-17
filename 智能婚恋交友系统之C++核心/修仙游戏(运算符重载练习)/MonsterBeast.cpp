#include "MonsterBeast.h"
#include "LingShi.h"
#define POWER_MONSTER	1000	//����ս��������ϵ��

MonsterBeast::MonsterBeast(const string& species, int grade)
{
	this->species = species;
	this->grade = grade;
}

LingShi MonsterBeast::MuchValue() const
{
	//���޼����Ӧ������ʯ
	int ysjbdyls[] = { 100,200,500,1000,2000,5000,10000,20000,100000 };
	//�����޼�ֵ���ٳ�����ʯ
	int MuchValue = ysjbdyls[grade - 1];

	return LingShi(MuchValue,LingShiGrade::PRIMARY);
}

bool MonsterBeast::operator==(const MonsterBeast& beast)const
{
	if (this->grade == beast.grade && this->species == beast.species) {
		return true;
	}
	else {
		return false;
	}
}

int MonsterBeast::getMonster() const
{
	//int power = grade * POWER_MONSTER;
	return grade * POWER_MONSTER;
}

ostream& operator<<(ostream& os, const MonsterBeast& monsterBeast)
{
	os << monsterBeast.species << "��������\t�ȼ�:" << monsterBeast.grade;
	return os;
}
