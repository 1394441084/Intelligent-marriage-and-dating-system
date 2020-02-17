#include "LingShi.h"

LingShi::LingShi(int number, LingShiGrade grade)
{
	this->number = number;
	this->grade = grade;
}

string LingShi::str() const
{
	stringstream str;
	str << number << "��";

	//���������ö��,�ж���ʯ�ȼ�
	switch (grade) {
	case LingShiGrade::PRIMARY:
		str << "������ʯ";
		break;
	case LingShiGrade::MIDDLE_RANK:
		str << "�н���ʯ";
		break;
	case LingShiGrade::EXPERT:
		str << "�߽���ʯ";

		//�����������:
	default:
		str << "δ֪��ʯ";
		break;
	}

	return str.str();
}

LingShi LingShi::operator+(const LingShi& other)const
{
	int total = 0;//������ʯ������(��λ:����)
	
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
	int i = 0;//�Լ���ʯ
	int others = 0;//������ʯ
	//������ʯ����ɳ���
	if (other.grade == LingShiGrade::PRIMARY) {
		others = other.number;
	}
	else if (other.grade == LingShiGrade::MIDDLE_RANK) {
		others = other.number * 10;
	}
	else if (other.grade == LingShiGrade::EXPERT) {
		others = other.number * 100;
	}
	//�Լ���ʯ����ɳ���
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
	int i = 0;//�Լ���ʯ
	int others = 0;//������ʯ
	//������ʯ����ɳ���
	if (other.grade == LingShiGrade::PRIMARY) {
		others = other.number;
	}
	else if (other.grade == LingShiGrade::MIDDLE_RANK) {
		others = other.number * 10;
	}
	else if (other.grade == LingShiGrade::EXPERT) {
		others = other.number * 100;
	}
	//�Լ���ʯ����ɳ���
	if (this->grade == LingShiGrade::PRIMARY) {
		i = this->number;
	}
	else if (this->grade == LingShiGrade::MIDDLE_RANK) {
		i = this->number * 10;
	}
	else if (this->grade == LingShiGrade::EXPERT) {
		i = this->number * 100;
	}
	//�Լ���ʯ�Ƚϱ�����ʯ
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
