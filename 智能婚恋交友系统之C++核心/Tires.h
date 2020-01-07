#pragma once
#include <sstream>
#include <string>
using namespace std;
//轮胎
class Tires
{
public:
	Tires();
	Tires(const string &brand="米其林");
	//Tires(const string& brand = "liang liang",float pressure=9.9);
	Tires& operator=(const Tires& other);//运算符重载,拷贝构造函数
	~Tires();

	string getbrand() const;
	float getpressure()const;
	string description()const;//描述

private:
	string brand="米其林.";//品牌
	float pressure=2.6;//胎压

};

