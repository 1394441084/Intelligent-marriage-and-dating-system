#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
using namespace std;

//父类
class Father//父亲
{
public:
	Father();
	Father(const char* name, int age);
	~Father();
	string getname()const;
	int getage()const;
	string  description()const;//描述

private:
	string name;
	//如果一个类,希望它的成员被自己的子类(派生类)直接访问.
	//但是又不想被外部访问,那么可以把这些成员定义为protected访问权限!!!
protected:
	int age;
};

