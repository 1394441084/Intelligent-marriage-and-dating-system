#pragma once
#include "LingShi.h"
#include "MonsterBeast.h"
#include "CultivateImmortality.h"

//测试灵石类函数
void testLingShiClass();
//测试妖兽类函数
void testMonsterBeast();
//测试修仙者类函数
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
	MonsterBeast monsterBeast("蛟龙",3);
	
	cout << monsterBeast << endl;
	cout << monsterBeast.MuchValue() << endl;

}

void testCultivateImmortality() {
	CultivateImmortality zwc("周伟长", "骑牛会所", FairyGrade::LIANQI);
	MonsterBeast monster("猪猪",1);
	MonsterBeast monster1("狗狗", 1);
	
	for (int i = 0; i < 50; i++) {
		zwc.dig();
	}

	zwc.CatchMonsterBeast(monster);

	MonsterBeast monster2("猫猫", 1);

	cout << "---------------捕获" <<monster<<"之后----------"<< endl;
	cout << zwc << endl;

	zwc.CatchMonsterBeast(monster1);
	zwc.CatchMonsterBeast(monster2);

	cout << "--------------捕获多只妖兽之后----------------" << endl;

	cout << zwc << endl;

	//zwc.trading(monster1);

	cout << "--------------卖掉狗狗妖兽之后---------------\n";
	cout << zwc << endl;

	//zwc.trading();
	cout << "-------------全部妖兽都卖掉------------------\n";
	cout << zwc << endl;

	CultivateImmortality hl("韩立", "无", FairyGrade::JIEDAN);
	MonsterBeast 噬金仙("噬金仙", 2);
	cout << hl << endl;
	hl.CatchMonsterBeast(噬金仙);
	cout << hl << endl;

	zwc.trading(hl, 噬金仙);//周伟长向韩立购买噬金仙
	cout << "------------互相交易后------------\n";
	cout << zwc << endl;
	cout << hl << endl;

	//MonsterBeast boos("无敌神兽", 9);
	//hl.CatchMonsterBeast(boos);
	//zwc.CatchMonsterBeast(boos);

	cout << "------------卖妖兽给他人换取灵石--------------\n";
	zwc.trading(monster2, hl);
	cout << zwc << endl;
	cout << hl << endl;

	cout << "------------妖兽交换妖兽----------------\n";
	hl.trading(monster2, zwc, monster1);
	cout << zwc << endl;
	cout << hl << endl;

}