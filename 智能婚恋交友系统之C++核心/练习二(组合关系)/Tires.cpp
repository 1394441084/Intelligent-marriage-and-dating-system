#include "Tires.h"
#include <iostream>

Tires::Tires()
{
	this->brand = "mi qi li";
	this->pressure = 2.8;
}

Tires::Tires(const string& brand)
{
	this->brand = brand;
	this->pressure = 2.5;
}
/*
Tires::Tires(const string& brand, float pressure)
{
	this->brand = brand;
	this->pressure = pressure;
}*/

Tires& Tires::operator=(const Tires& other)
{
	if (this == &other) {
		return *this;//为了防止f1=f1;防止对象给自己赋值
	}
	else {
		brand = other.brand;
		pressure = other.pressure;
	}

	//返回对象本身的引用,为了方便能链式处理如:f1=f2=f3.
	return *this;//必须返回.为防止f1=f2=f3;这种情况,突然返回空的情况
}

Tires::~Tires()
{
	std::cout << "~Tires\n";
}

string Tires::getbrand() const
{
	return brand;
}

float Tires::getpressure() const
{
	return pressure;
}

string Tires::description() const
{
	stringstream str;
	str << "Tires品牌:" << brand << "  胎压:" << pressure << endl;

	return str.str();
}
