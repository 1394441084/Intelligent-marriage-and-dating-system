#pragma once
#include "Tires.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>
using namespace std;

//��
class Car
{
public:
	Car();
	Car(const string &carBrand,const string &carModel,int carPrice,
		const string& engineBrand, float engineModel,
		const string& tiresBrand = "������`");
	//Car(const Car& other);//���忽�����̺���,��������,ֻ��һ����������,�޷�����
	Car& operator=(const Car& other);//���������,�������캯��
	~Car();

	Engine getEngine()const;
	const Tires* getTires(int n)const;
	string getBrand()const;
	string getModel()const;
	int getPrice()const;
	int getDrivingMileage()const;
	string description()const;//����
private:
	string brand="";//Ʒ��
	string model="";//�ͺ�
	int price=0;//�۸�
	int drivingMileage=20;//��ʻ���
	Engine engine;//������(��Ϲ�ϵ)
	Tires tires[4];//��̥(��Ϲ�ϵ)
};

