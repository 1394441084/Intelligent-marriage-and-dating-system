#pragma once
#include "Tires.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>
using namespace std;

//车
class Car
{
public:
	Car();
	Car(const string &carBrand,const string &carModel,int carPrice,
		const string& engineBrand, float engineModel,
		const string& tiresBrand = "米其林`");
	//Car(const Car& other);//定义拷贝过程函数,引用类型,只有一个拷贝函数,无法重载
	Car& operator=(const Car& other);//运算符重载,拷贝构造函数
	~Car();

	Engine getEngine()const;
	const Tires* getTires(int n)const;
	string getBrand()const;
	string getModel()const;
	int getPrice()const;
	int getDrivingMileage()const;
	string description()const;//描述
private:
	string brand="";//品牌
	string model="";//型号
	int price=0;//价格
	int drivingMileage=20;//行驶里程
	Engine engine;//发动机(组合关系)
	Tires tires[4];//轮胎(组合关系)
};

