#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//#include "ComputerService.h"//使用类的成员函数作为友元函数,必须包含其头文件

class Computer
{
public:
	string getcpu() { return cpu; }

private:
	string cpu = "i5";
	void friend upgrade(Computer* computer);//全局函数作为友元函数
	//friend void ComputerService::upgrade1(Computer* computer);//类的成员函数作为友元函数
	friend class ComputerService;//友元类
};

