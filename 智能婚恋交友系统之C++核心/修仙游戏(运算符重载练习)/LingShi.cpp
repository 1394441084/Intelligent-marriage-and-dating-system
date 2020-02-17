#include "LingShi.h"

LingShi::LingShi(int number, LingShiGrade grade)
{
	this->number = number;
	this->grade = grade;
}

string LingShi::str() const
{
	stringstream str;
	str << number << "块";

	//处理进来的枚举,判断灵石等级
	switch (grade) {
	case LingShiGrade::PRIMARY:
		str << "初阶灵石";
		break;
	case LingShiGrade::MIDDLE_RANK:
		str << "中阶灵石";
		break;
	case LingShiGrade::EXPERT:
		str << "高阶灵石";

		//出现其它情况:
	default:
		str << "未知灵石";
		break;
	}

	return str.str();
}

LingShi LingShi::operator+(const LingShi& other)const
{
	int total = 0;//两颗灵石的总数(单位:初阶)
	
	if (other.grade == LingShiGrade::PRIMARY) {
		total += other.number;
	}
	else if (other.grade == LingShiGrade::MIDDLE_RANK) {
		total += other.number*10;
	}
	else if (other.grade == LingShiGrade::EXPERT) {
		total += other.number * 100;
	}

	if (this->grade == LingShiGrade::PRIMARY) {
		total += this->number;
	}
	else if (this->grade == LingShiGrade::MIDDLE_RANK) {
		total += this->number * 10;
	}
	else if (this->grade == LingShiGrade::EXPERT) {
		total += this->number * 100;
	}

	return LingShi(total, LingShiGrade::PRIMARY);
}

LingShi LingShi::operator-(const LingShi& other) const
{
	int i = 0;//自己灵石
	int others = 0;//别人灵石
	//别人灵石换算成初阶
	if (other.grade == LingShiGrade::PRIMARY) {
		others = other.number;
	}
	else if (other.grade == LingShiGrade::MIDDLE_RANK) {
		others = other.number * 10;
	}
	else if (other.grade == LingShiGrade::EXPERT) {
		others = other.number * 100;
	}
	//自己灵石换算成初阶
	if (this->grade == LingShiGrade::PRIMARY) {
		i = this->number;
	}
	else if (this->grade == LingShiGrade::MIDDLE_RANK) {
		i = this->number * 10;
	}
	else if (this->grade == LingShiGrade::EXPERT) {
		i = this->number * 100;
	}

	return LingShi(i - others,LingShiGrade::PRIMARY);
}

bool LingShi::operator>=(const LingShi& other)const
{
	int i = 0;//自己灵石
	int others = 0;//别人灵石
	//别人灵石换算成初阶
	if (other.grade == LingShiGrade::PRIMARY) {
		others = other.number;
	}
	else if (other.grade == LingShiGrade::MIDDLE_RANK) {
		others = other.number * 10;
	}
	else if (other.grade == LingShiGrade::EXPERT) {
		others = other.number * 100;
	}
	//自己灵石换算成初阶
	if (this->grade == LingShiGrade::PRIMARY) {
		i = this->number;
	}
	else if (this->grade == LingShiGrade::MIDDLE_RANK) {
		i = this->number * 10;
	}
	else if (this->grade == LingShiGrade::EXPERT) {
		i = this->number * 100;
	}
	//自己灵石比较别人灵石
	if (i >= others) {
		return true;
	}

	return false;
}

int LingShi::getNumber() const
{
	return number;
}

ostream& operator<<(ostream& os, const LingShi& lingshi)
{
	os << lingshi.str();
	return os;
}
