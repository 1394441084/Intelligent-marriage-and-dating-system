#pragma once
#include "ODU.h"

class ODU330 : public ODU
{
public:
	//ODU330();
	//~ODU330();
	float getBER();//获取当前误码率
	float getAlarmThreshold();//查看告警门限
	bool setAlarmThreshold(float alarmThreshold);//设置告警门限
	string description();//描述
private:
	float alarmThreshold;//告警门限
};
