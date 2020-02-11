#include "Single.h"
/*
Single::Single()
{
	name = "";
	age = 0;
	height = 0;
	degree = "";
	salary = 0;
	faceScore = 0;
}

Single::Single(const string name, int age)
{
	this->name = name;
	this->age = age;
}*/

Single::Single(const char* name, int age, int height, const char* degree, int salary, int faceScore)
{
	this->name = name;
	this->age = age;
	this->height = height;
	this->degree = degree;
	this->salary = salary;
	this->faceScore = faceScore;
}

Single::~Single()
{
}

string Single::getname() const
{
	return name;
}

int Single::getage() const
{
	return age;
}

int Single::getheight() const
{
	return height;
}

string Single::getdegree() const
{
	return degree;
}

int Single::getsalary() const
{
	return salary;
}

int Single::getfaceScore() const
{
	return faceScore;
}

string Single::basic_information() const
{
	stringstream str;
	str << __FUNCTION__ << "-名字:" << name << "  -年龄:" << age << "  -身高:" << height
		<< "  -薪资:" << salary << "  -学历:" << degree << "  -颜值:" << faceScore << endl;
	return str.str();
}
