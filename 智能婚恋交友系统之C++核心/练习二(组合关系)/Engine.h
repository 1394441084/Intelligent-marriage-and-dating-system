#pragma once
#include <sstream>
#include <string>
using namespace std;
//������
class Engine
{
public:
	Engine();
	Engine(const string& brand, float model);
	Engine& operator=(const Engine& other);//���������,�������캯��
	~Engine();

	string getbrand()const;
	float getmodel()const;
	string description()const;//����

private:
	string brand;//Ʒ��
	float model;//�ͺ�
};

