#include "ODU.h"

ODU::ODU()
{
}

ODU::~ODU()
{
}

float ODU::getPower() const
{
	return power;
}

bool ODU::setPower(float power){
	//ʵ�ʲ�Ʒ��Ŀ��,ͨ�����ڷ��Ϳ��ư�ʵ�ֵ�.
	this->power = power;
	return true;
}

int ODU::getFrequency()
{
	return frequency;
}

bool ODU::setFrequency(int frequency)
{
	this->frequency = frequency;
	return true;
}

float ODU::getBandwidth()
{
	return bandwidth;
}

bool ODU::setBandwidth(float bandwidth)
{
	this->bandwidth = bandwidth;
	return true;
}

string ODU::description()
{
	stringstream str;
	str << "���书��: " << power << "  ����Ƶ��: " << frequency << "  ����: " << bandwidth << " M\n";
	return str.str();
}

