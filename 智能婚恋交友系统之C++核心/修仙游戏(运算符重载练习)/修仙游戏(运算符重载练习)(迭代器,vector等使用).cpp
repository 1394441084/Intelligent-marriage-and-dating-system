#pragma once
#include "LingShi.h"
#include "MonsterBeast.h"
#include "CultivateImmortality.h"

//������ʯ�ຯ��
void testLingShiClass();
//���������ຯ��
void testMonsterBeast();
//�����������ຯ��
void testCultivateImmortality();

int main(void) {

	//testLingShiClass();
	//testMonsterBeast();
	testCultivateImmortality();

	system("pause");
	return 0;
}

void testLingShiClass() {
	LingShi lingshi(100,LingShiGrade::MIDDLE_RANK);
	const LingShi lll(1000, LingShiGrade::MIDDLE_RANK);
	lingshi = lll + lingshi;

	cout << lingshi << endl;
}

void testMonsterBeast() {
	MonsterBeast monsterBeast("����",3);
	
	cout << monsterBeast << endl;
	cout << monsterBeast.MuchValue() << endl;

}

void testCultivateImmortality() {
	CultivateImmortality zwc("��ΰ��", "��ţ����", FairyGrade::LIANQI);
	MonsterBeast monster("����",1);
	MonsterBeast monster1("����", 1);
	
	for (int i = 0; i < 50; i++) {
		zwc.dig();
	}

	zwc.CatchMonsterBeast(monster);

	MonsterBeast monster2("èè", 1);

	cout << "---------------����" <<monster<<"֮��----------"<< endl;
	cout << zwc << endl;

	zwc.CatchMonsterBeast(monster1);
	zwc.CatchMonsterBeast(monster2);

	cout << "--------------�����ֻ����֮��----------------" << endl;

	cout << zwc << endl;

	//zwc.trading(monster1);

	cout << "--------------������������֮��---------------\n";
	cout << zwc << endl;

	//zwc.trading();
	cout << "-------------ȫ�����޶�����------------------\n";
	cout << zwc << endl;

	CultivateImmortality hl("����", "��", FairyGrade::JIEDAN);
	MonsterBeast �ɽ���("�ɽ���", 2);
	cout << hl << endl;
	hl.CatchMonsterBeast(�ɽ���);
	cout << hl << endl;

	zwc.trading(hl, �ɽ���);//��ΰ�����������ɽ���
	cout << "------------���ཻ�׺�------------\n";
	cout << zwc << endl;
	cout << hl << endl;

	//MonsterBeast boos("�޵�����", 9);
	//hl.CatchMonsterBeast(boos);
	//zwc.CatchMonsterBeast(boos);

	cout << "------------�����޸����˻�ȡ��ʯ--------------\n";
	zwc.trading(monster2, hl);
	cout << zwc << endl;
	cout << hl << endl;

	cout << "------------���޽�������----------------\n";
	hl.trading(monster2, zwc, monster1);
	cout << zwc << endl;
	cout << hl << endl;

}