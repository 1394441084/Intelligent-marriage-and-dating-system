#include "Father.h"

Father::Father()
{
	name = "����";
	age = 1000;
}

Father::Father(const char* name, int age)
{
	cout << "���������ȵ��ø���Ĭ�Ϲ��캯��\n";
	this->name = name;
	this->age = age;
}

Father::~Father()
{
}

string Father::getname() const
{
	return name;
}

int Father::getage() const
{
	return age;
}

string Father::description() const
{
	stringstream str;
	str << "  ����:" << name << "  ����:" << age << endl;

	return str.str();
}


