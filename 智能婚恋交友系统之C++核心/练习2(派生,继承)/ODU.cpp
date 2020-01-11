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
	//实际产品项目中,通过串口发送控制包实现的.
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
	str << "发射功率: " << power << "  发射频率: " << frequency << "  带宽: " << bandwidth << " M\n";
	return str.str();
}

