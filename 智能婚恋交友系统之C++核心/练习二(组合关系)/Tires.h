#pragma once
#include <sstream>
#include <string>
using namespace std;
//��̥
class Tires
{
public:
	Tires();
	Tires(const string &brand="������");
	//Tires(const string& brand = "liang liang",float pressure=9.9);
	Tires& operator=(const Tires& other);//���������,�������캯��
	~Tires();

	string getbrand() const;
	float getpressure()const;
	string description()const;//����

private:
	string brand="������.";//Ʒ��
	float pressure=2.6;//̥ѹ

};

