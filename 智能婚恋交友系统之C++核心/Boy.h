#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>//vector�����൱���Զ�����Ķ�̬���飬���Է���ζ������������
#include <string>
#include "Girl.h"
using namespace std;
#define SALARY_COEFFICIENT 0.006  //н��ϵ��

class Boy
{
public:
	Boy();
	Boy(string name, int age, int salary);
	Boy(string name, int salary,string degree);
	Boy(string name, int age, int height, string degree, int salary, int faceScore);
	~Boy();

	string getname()const;//get����
	int getage()const;//get����
	int getheight()const;//get���
	string getdegree()const;//getѧ��
	int getsalary()const;//getн��
	int getfaceScore()const;//get��ֵ
	string basic_information()const;//������Ϣ
	bool satisfied(const Girl& girl)const;//�Ƿ�����
	static void inputBoys(vector<Boy>&boys);//������boy����ķ����ӿ�
	void vectortest() {//����vector��������Ĳ���
		age += 10;
	}
private:
	string name="";//����
	int age=0;//���䣬��λ����
	int height=0;//��ߣ���λ��cm
	string degree="";//ѧ��
	int salary=0;//н��
	int faceScore=0;//��ֵ,����100
};

