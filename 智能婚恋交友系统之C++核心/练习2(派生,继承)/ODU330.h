#pragma once
#include "ODU.h"

class ODU330 : public ODU
{
public:
	//ODU330();
	//~ODU330();
	float getBER();//��ȡ��ǰ������
	float getAlarmThreshold();//�鿴�澯����
	bool setAlarmThreshold(float alarmThreshold);//���ø澯����
	string description();//����
private:
	float alarmThreshold;//�澯����
};
