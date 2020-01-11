#pragma once
#include <string>
#include <sstream>
using namespace std;

class ODU
{
public:
	ODU();
	~ODU();

	float getPower()const;//�鿴���书��
	bool setPower(float power);//���÷��书��
	int getFrequency();//�鿴����Ƶ��
	bool setFrequency(int frequency);//���÷���Ƶ��
	float getBandwidth();//�鿴����
	bool setBandwidth(float bandwidth);//���ô���
	string description();//����
	
private:
	float power;//���书��
	int frequency;//����Ƶ��
	float bandwidth;//����,��λ:M
};

