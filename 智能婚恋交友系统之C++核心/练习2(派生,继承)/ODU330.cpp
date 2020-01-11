#include "ODU330.h"

float ODU330::getBER()
{
	return 0.00005f;//ģ��
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
	str << "���书��: " << getPower() << "  ����Ƶ��: " << getFrequency() << "  ����: " << getBandwidth() << " M"
		<< "  ������: " << getBER() << "  �澯����: " << alarmThreshold << endl;
	return str.str();
}
