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
		return *this;//Ϊ�˷�ֹf1=f1;��ֹ������Լ���ֵ
	}
	else {
		brand = other.brand;
		pressure = other.pressure;
	}

	//���ض����������,Ϊ�˷�������ʽ������:f1=f2=f3.
	return *this;//���뷵��.Ϊ��ֹf1=f2=f3;�������,ͻȻ���ؿյ����
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
	str << "TiresƷ��:" << brand << "  ̥ѹ:" << pressure << endl;

	return str.str();
}
