#include "Boy.h"

Girl::Girl():Single("3",3)
{
	//name = "";
	//age = 0;
	height = 3;
	chest = "��";
	faceScore = 3;
	salary = 3;
	degree = "3";
}

Girl::Girl(const char* name, int age, int faceScore) :Single(name, age)
{
	//this->name = name;
	//this->age = age;
	this->faceScore = faceScore;
	this->height = 3;
	this->chest = "��";
	this->salary = 3;
	degree = "3";
}

Girl::Girl(const char* name, int age, int height, const char* chest, int faceScore, int salary) :Single(name, age)
{
	//this->name = name;
	//this->age = age;
	this->height = height;
	this->chest = chest;
	this->faceScore = faceScore;
	this->salary=salary;
	degree = "3";
}

Girl::~Girl()
{
}
/*
string Girl::getname() const
{
	return name;
}

int Girl::getage()const {
	return age;
}

int Girl::getheight()const {
	return height;
}

int Girl::getfaceScore()const{
	return faceScore;
}

int Girl::getsalary()const {
	return salary;
}

string Girl::basic_information()const {
	stringstream ret;//������豸����cout���ƣ��Զ������ڴ淽��ĺ�
	ret << name << "-Ů-��ֵ��" << faceScore << ")-����(" << age << ")-��Χ("<<chest<<")";
	return ret.str();//�ô˷���תΪstring�ַ���
}
*/

string Girl::getchest()const {
	return chest;
}

bool Girl::satisfied(const Boy& boy) const
{
	//������ֵ80 80*FACE_COEFFICIENT
	if (boy.getsalary() >= faceScore * FACE_COEFFICIENT) {
		return true;
	}
	else {
		return false;
	}
}

void Girl::inputGirls(vector<Girl>& girls)
{
	string name;
	int age;
	int faceScore;

	int n = 1;
	while (1) {
		cout << "�������" << n << "λС��������[����0����]:" ;
		cin >> name;
		if (name == "0") { break; }

		cout << "�������" << n << "λС��������:";
		cin >> age;

		cout << "�������" << n << "λС������ֵ:" << endl;
		cin >> faceScore;

		girls.push_back(Girl(name.c_str(), age, faceScore));
		n++;
	}
}
