#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//#include "ComputerService.h"//ʹ����ĳ�Ա������Ϊ��Ԫ����,���������ͷ�ļ�

class Computer
{
public:
	string getcpu() { return cpu; }

private:
	string cpu = "i5";
	void friend upgrade(Computer* computer);//ȫ�ֺ�����Ϊ��Ԫ����
	//friend void ComputerService::upgrade1(Computer* computer);//��ĳ�Ա������Ϊ��Ԫ����
	friend class ComputerService;//��Ԫ��
};

