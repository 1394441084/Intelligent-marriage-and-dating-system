#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <sstream>
using namespace std;

//����
class Father//����
{
public:
	Father();
	Father(const char* name, int age);
	~Father();
	string getname()const;
	int getage()const;
	string  description()const;//����

private:
	string name;
	//���һ����,ϣ�����ĳ�Ա���Լ�������(������)ֱ�ӷ���.
	//�����ֲ��뱻�ⲿ����,��ô���԰���Щ��Ա����Ϊprotected����Ȩ��!!!
protected:
	int age;
};

