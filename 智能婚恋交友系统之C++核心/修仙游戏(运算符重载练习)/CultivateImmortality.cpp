#include "CultivateImmortality.h"
#include "LingShi.h"
#include "MonsterBeast.h"

CultivateImmortality::CultivateImmortality(const char* name, const char* united, FairyGrade grade)
{
	this->name = name;
	this->united = united;
	this->grade = grade;
	this->raw = true;
}

void CultivateImmortality::dig()
{
	//得到100块初阶灵石(+100)
	shi.push_back(LingShi(100, LingShiGrade::PRIMARY));
}

bool CultivateImmortality::trading()
{
	//判断自己生死
	if (!raw) { cout << "你死了,交易个毛呀!\n"; return false; }

	//卖掉所有妖兽得到灵石
	LingShi lingshi;
	for (int i = 0; i < beast.size(); i++) {
		lingshi = lingshi+ beast[i].MuchValue();
	}
	shi.push_back(lingshi);//放进灵石仓库

	//妖兽没有了,清空;//清掉(起始位,结束位);
	beast.erase(beast.begin(), beast.end());

	return false;
}

bool CultivateImmortality::trading(const MonsterBeast& beast)
{
	//判断自己生死
	if (!raw) {cout << "你死了,交易个毛呀!\n";return false;}

	//检查是否有指定的妖兽
	if (!IsThereSuchAMonster(beast)) {
		cout << name << "没有" << beast << endl;
		return false;
	}

	//计算妖兽价值并将所得灵石载入灵石库
	LingShi lingshi = beast.MuchValue();
	shi.push_back(lingshi);

	//将指定妖兽从妖兽库移出
	RemovedFromTheMonster(beast);

	return true;
}

bool CultivateImmortality::trading(CultivateImmortality& Immortality, const MonsterBeast& beast)
{
	//判断双方是否都存活
	if (!(raw && Immortality.raw)) {
		cout << "交易双方有人是死亡状态,所以无法交易!\n";
		return false;
	}
	//判断对方是否有此妖兽
	if (!Immortality.IsThereSuchAMonster(beast)) {
		cout << Immortality.name << "没有" << beast << endl;
		return false;
	}
	//计算自己总灵石量(单位:初阶)
	LingShi lingshi;
	for (int i = 0; i < shi.size(); i++) {
		lingshi = lingshi + shi[i];
	}
	//判断是否有钱买下妖兽
	if (lingshi >= beast.MuchValue()) {
		//LingShi beastvalue = beast.MuchValue();//妖兽价值多少块初阶灵石
		lingshi = lingshi - beast.MuchValue();//自己总灵石-妖兽价值=剩余灵石
		shi.clear();//清空灵石库
		shi.push_back(lingshi);//将剩余总灵石数据载入自己灵石库
		this->beast.push_back(beast);//将妖兽载入自己妖兽库

		//Immortality.trading(beast);//可以直接用这个,但避免更改错乱暂时不用
		Immortality.RemovedFromTheMonster(beast);//将妖兽从他人妖兽库移出
		Immortality.shi.push_back(beast.MuchValue());//增加与妖兽同等价值的灵石
		return true;
	}
	else {
		cout << "抱歉!" << name << "的灵石不过买" << beast << endl;
		return false;
	}
}

bool CultivateImmortality::trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality, const MonsterBeast& otherbeast)
{
	//判断双方是否都存活
	if (!(raw && otherImmortality.raw)) {
		cout << "交易双方有人是死亡状态,所以无法交易!\n";
		return false;
	}
	//判断是否同意交易妖兽;妖兽等级,种类是否相等||妖兽库有没有||妖兽价值是否相等
	if(beast == otherbeast ||
		!IsThereSuchAMonster(beast)||
		!otherImmortality.IsThereSuchAMonster(otherbeast)||
		!(beast.MuchValue()>=otherbeast.MuchValue())
		) {
		return false;
	}

	//下面是交易了
	//移出双方妖兽
	RemovedFromTheMonster(beast);
	RemovedFromTheMonster(otherbeast);
	//将交换的妖兽添加到各自妖兽库
	this->beast.push_back(otherbeast);
	otherImmortality.beast.push_back(beast);

	return true;
}

bool CultivateImmortality::trading(const MonsterBeast& beast,CultivateImmortality& otherImmortality)
{
	//判断双方是否都存活
	if (!(raw && otherImmortality.raw)) {
		cout << "交易双方有人是死亡状态,所以无法交易!\n";
		return false;
	}

	//判断妖兽是否拥有和对方是否有购买力
	LingShi lingshi;
	for (int i = 0; i < otherImmortality.shi.size(); i = i + 1) {
		lingshi = lingshi + otherImmortality.shi[i];
	}
	if (IsThereSuchAMonster(beast) && (lingshi >= beast.MuchValue())) {
		RemovedFromTheMonster(beast);//移除自己妖兽
		otherImmortality.beast.push_back(beast);//他人添加妖兽
		otherImmortality.shi.clear();//清空他人灵石库
		lingshi = lingshi - beast.MuchValue();//剩余灵石
		otherImmortality.shi.push_back(lingshi);//将他人剩余灵石载入他人灵石库
		this->shi.push_back(beast.MuchValue());//将交易所得灵石载入自己灵石库
		return true;
	}
	else {//其它情况
		cout << "没有购买了或者自己没有妖兽\n";
		return false;
	}

	//其它情况
	return false;
}

int CultivateImmortality::OneselfPower() const
{
	//计算修仙者级别战斗力
	int power = ((int)grade + 1) * POWER_XXZ;

	//计算灵石助攻战斗力
	LingShi lingshi;
	for (int i = 0; i < shi.size(); i++) {
		lingshi = lingshi + shi[i];
	}
	power += lingshi.getNumber() * POWER_LINGSHI;

	//计算妖兽助攻战斗力
	for (int i = 0; i < this->beast.size(); i++) {
		power += this->beast[i].getMonster() * POWER_BEAST;
	}

	return power;
}

bool CultivateImmortality::CatchMonsterBeast(const MonsterBeast& beast)
{
	if (OneselfPower() > beast.getMonster()) {
		//赢了得到妖兽
		this->beast.push_back(beast);
		return true;
	}
	else {
		//输了:死!!!
		DeathOfYogi();
		return false;
	}
}

bool CultivateImmortality::IsThereSuchAMonster(const MonsterBeast& beast)const
{
	//遍历妖兽库看是否有指定妖兽
	for (int i = 0; i < this->beast.size(); i++) {
		if (this->beast[i] == beast) {
			return true;
		}
	}

	//妖兽库都没有了,返回false
	return false;
}

bool CultivateImmortality::RemovedFromTheMonster(const MonsterBeast& beast)
{
	//定义一个迭代器(特殊指针),it=this->beast.begin();//指向妖兽库的第一个成员
	vector<MonsterBeast>::iterator it = this->beast.begin();
	//.end();最后成员的下一个位置
	while (it != this->beast.end()) {
		if (*it == beast) {
			it=this->beast.erase(it);
			return true;
		}
		else {
			it++;
		}
	}

	return false;
}

void CultivateImmortality::DeathOfYogi()
{
	raw = false;//生存状态变为死
	shi.erase(shi.begin(), shi.end());//灵石库清空
	beast.erase(beast.begin(), beast.end());//妖兽库清空
}

ostream& operator<<(ostream& os, const FairyGrade& grade)
{
	switch (grade) {
	case FairyGrade::LIANQI:
		os << "练气期";
		break;
	case FairyGrade::ZHUJI:
		os << "筑基期";
		break;
	case FairyGrade::JIEDAN:
		os << "结丹期";
		break;
	case FairyGrade::YUANYING:
		os << "元婴期";
		break;
	case FairyGrade::HUASHEN:
		os << "化神期";
		break;
	case FairyGrade::LIANXU:
		os << "炼虚期";
		break;
	case FairyGrade::HETI:
		os << "合体期";
		break;
	case FairyGrade::DACHENG:
		os << "大乘期";
		break;
	case FairyGrade::DUJIE:
		os << "渡劫期";
		break;
	default:
		os << "你丫的突破天际了都!!!";
		break;
	}
	return os;
}

ostream& operator<<(ostream& os, const CultivateImmortality& Immortality)
{
	os << "[修行者]" << Immortality.name << (Immortality.raw ? "在修" : "以亡")
		<< "\t门派:" << Immortality.united << "\t级别:" << Immortality.grade;

	LingShi lingshi;
	for (int i = 0; i < Immortality.shi.size(); i++) {
		lingshi = lingshi + Immortality.shi[i];
	}

	os << "\t灵石:" << lingshi << "\t妖兽:";

	if (!Immortality.beast.size()) {
		os << "无";
	}
	else {
		for (int i = 0; i < Immortality.beast.size(); i++) {
			os << Immortality.beast[i] << " ";
		}
	}

	return os;
}

