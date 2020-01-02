#include "computer.h"
//组合与聚合
//聚合,不负责创建和销毁

#include <iostream>
#include <Windows.h>

computer::computer(const char* cpuBrand, const char* cpuModel, int HardDisk, int Memory):Cpu(cpuBrand,cpuModel)
{//默认构造函数,初始化列表:Cpu(cpuBrand,cpuModel),会调用cpu类的默认构造函数
	//this->Cpu = cpu(cpuBrand,cpuModel);//不高效

	this->HardDisk = HardDisk;
	this->Memory = Memory;
	cout << "computer默认构造函数" << endl;
}

/*cpu* Cpu;//用这个的时候才是
computer::computer(const char* cpuBrand, const char* cpuModel, int HardDisk, int Memory) 
{
	this->HardDisk = HardDisk;
	this->Memory = Memory;
	this->Cpu = new cpu(cpuBrand, cpuModel);//和上面的差不多
	cout << "computer默认构造函数" << endl;
}
*/

computer::~computer() {
	//delete[] Cpu;
	//delete[] speaker;//自己跳河不能带上有关系的(聚合),不是同生共死的
	cout << "computer析构" << endl;
}

//聚合
void computer::addSpeaker(Speaker* speaker) {
	this->speaker = speaker;
}