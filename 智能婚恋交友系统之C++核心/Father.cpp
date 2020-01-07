#include "Father.h"

Father::Father()
{
	name = "父类";
	age = 1000;
}

Father::Father(const char* name, int age)
{
	cout << "调用子类先调用父类默认构造函数\n";
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
	str << "  姓名:" << name << "  年龄:" << age << endl;

	return str.str();
}


