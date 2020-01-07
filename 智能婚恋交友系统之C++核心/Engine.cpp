#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	brand = "����";
	model = 2.0;
}

Engine::Engine(const string& brand, float model)
{
	this->brand = brand;
	this->model = model;
}

Engine& Engine::operator=(const Engine& other)
{
	if (this == &other) {
		return *this;//Ϊ�˷�ֹf1=f1;��ֹ������Լ���ֵ
	}
	else {
		brand = other.brand;
		model = other.model;
	}
	return *this;
}

Engine::~Engine()
{
	std::cout << "~Engine\n";
}

string Engine::getbrand() const
{
	return brand;
}

float Engine::getmodel() const
{
	return model;
}

string Engine::description() const
{
	stringstream str;
	str << "EngineƷ��:" << brand << ". -Engine�ͺ�:" << model << endl;

	return str.str();
}
