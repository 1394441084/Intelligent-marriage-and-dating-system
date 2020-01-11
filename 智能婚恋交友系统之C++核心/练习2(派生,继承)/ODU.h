#pragma once
#include <string>
#include <sstream>
using namespace std;

class ODU
{
public:
	ODU();
	~ODU();

	float getPower()const;//查看发射功率
	bool setPower(float power);//设置发射功率
	int getFrequency();//查看发射频率
	bool setFrequency(int frequency);//设置发射频率
	float getBandwidth();//查看带宽
	bool setBandwidth(float bandwidth);//设置带宽
	string description();//描述
	
private:
	float power;//发射功率
	int frequency;//发射频率
	float bandwidth;//带宽,单位:M
};

