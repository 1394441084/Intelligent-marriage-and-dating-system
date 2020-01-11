#include "ODU330.h"

float ODU330::getBER()
{
	return 0.00005f;//模拟
}

float ODU330::getAlarmThreshold()
{
	return alarmThreshold;
}

bool ODU330::setAlarmThreshold(float alarmThreshold)
{
	this->alarmThreshold = alarmThreshold;
	return true;
}

string ODU330::description()
{
	stringstream str;
	str << "发射功率: " << getPower() << "  发射频率: " << getFrequency() << "  带宽: " << getBandwidth() << " M"
		<< "  误码率: " << getBER() << "  告警门限: " << alarmThreshold << endl;
	return str.str();
}
