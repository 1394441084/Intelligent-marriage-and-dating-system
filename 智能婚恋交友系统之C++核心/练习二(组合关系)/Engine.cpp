#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	brand = "国产";
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
		return *this;//为了防止f1=f1;防止对象给自己赋值
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
	str << "Engine品牌:" << brand << ". -Engine型号:" << model << endl;

	return str.str();
}
