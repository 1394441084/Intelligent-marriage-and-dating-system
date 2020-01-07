#pragma once
#include <sstream>
#include <string>
using namespace std;
//发动机
class Engine
{
public:
	Engine();
	Engine(const string& brand, float model);
	Engine& operator=(const Engine& other);//运算符重载,拷贝构造函数
	~Engine();

	string getbrand()const;
	float getmodel()const;
	string description()const;//描述

private:
	string brand;//品牌
	float model;//型号
};

