#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//战力换算
#define POWER_XXZ		1000		 //修仙者战力级别换算系数
#define POWER_LINGSHI	0.1			 //灵石战力换算系数
#define POWER_BEAST		0.1			 //妖兽战力换算系数

//修行者级别
enum class FairyGrade {
	LIANQI,		//练气期
	ZHUJI,		//筑基期
	JIEDAN,		//结丹期
	YUANYING,	//元婴期
	HUASHEN,	//化神期
	LIANXU,		//炼虚期
	HETI,		//合体期
	DACHENG,	//大乘期
	DUJIE,		//渡劫期
	//ZONGJIBIE	//总等级
};

class LingShi;
class MonsterBeast;

//修仙者类
class CultivateImmortality
{
public:
	//默认构造函数
	CultivateImmortality(const char* name="新手", const char* united="无", FairyGrade grade= FairyGrade::LIANQI);

	//挖矿
	void dig();
	//去市场卖所有妖兽
	bool trading();
	//去市场卖指定的妖兽*
	bool trading(const MonsterBeast& beast);
	//用自己灵石买其它修行者指定妖兽(自己,他人妖兽)
	bool trading(CultivateImmortality& Immortality,const MonsterBeast& beast);
	//用自己指定的妖兽和他人交换指定妖兽(自己妖兽,他人,他人妖兽)
	bool trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality,const MonsterBeast& otherbeast);
	//将自己指定的妖兽卖给他人,以换取灵石(自己妖兽,他人)
	bool trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality);
	//自己的战斗力
	int OneselfPower()const;
	//捕获妖兽
	bool CatchMonsterBeast(const MonsterBeast& beast);
	//输出<<重载运算符
	friend ostream& operator<<(ostream& os, const FairyGrade& grade);
	friend ostream& operator<<(ostream& os,const CultivateImmortality& Immortality);
	
	//检查是否有指定的妖兽
	bool IsThereSuchAMonster(const MonsterBeast& beast)const;
	//移出指定妖兽
	bool RemovedFromTheMonster(const MonsterBeast& beast);
private:
	string name;				//姓名
	string united;				//门派
	FairyGrade grade;			//修仙者级别
	vector<LingShi>shi;			//灵石资产
	vector<MonsterBeast>beast;	//妖兽资产
	bool raw;					//生;真为生,假为死

	
	//修仙者死亡后处理
	void DeathOfYogi();
};

	//ostream& operator<<(ostream& os, const CultivateImmortality& Immortality);

