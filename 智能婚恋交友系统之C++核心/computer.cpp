#include "computer.h"
//�����ۺ�
//�ۺ�,�����𴴽�������

#include <iostream>
#include <Windows.h>

computer::computer(const char* cpuBrand, const char* cpuModel, int HardDisk, int Memory):Cpu(cpuBrand,cpuModel)
{//Ĭ�Ϲ��캯��,��ʼ���б�:Cpu(cpuBrand,cpuModel),�����cpu���Ĭ�Ϲ��캯��
	//this->Cpu = cpu(cpuBrand,cpuModel);//����Ч

	this->HardDisk = HardDisk;
	this->Memory = Memory;
	cout << "computerĬ�Ϲ��캯��" << endl;
}

/*cpu* Cpu;//�������ʱ�����
computer::computer(const char* cpuBrand, const char* cpuModel, int HardDisk, int Memory) 
{
	this->HardDisk = HardDisk;
	this->Memory = Memory;
	this->Cpu = new cpu(cpuBrand, cpuModel);//������Ĳ��
	cout << "computerĬ�Ϲ��캯��" << endl;
}
*/

computer::~computer() {
	//delete[] Cpu;
	//delete[] speaker;//�Լ����Ӳ��ܴ����й�ϵ��(�ۺ�),����ͬ��������
	cout << "computer����" << endl;
}

//�ۺ�
void computer::addSpeaker(Speaker* speaker) {
	this->speaker = speaker;
}