#pragma once
#include <iostream>
//#include <Windows.h>//����system();ʹ�ò���ȷ������,�������,�軻#include <stdlib.h>
#include <vector>//vector�����൱���Զ�����Ķ�̬���飬���Է���ζ������������
#include <string>
#include <sstream> //stringstream,����������ζ������ܱ�Ϊ�ַ���
#include <iomanip>//������������ַ����ľ���(����)
#include <stdio.h>//sscanf_s��ͷ�ļ�
#include <stdlib.h>//���system();ʹ�ò���ȷ������

using namespace std;
class Single
{
public:
	//Single();
	//Single(const string name="",int age=0);
	Single(const char* name = "", int age = 0, int height = 0,const char* degree="",int salary=0,int faceScore=0);
	~Single();

	string getname()const;//get����
	int getage()const;//get����
	int getheight()const;//get���
	string getdegree()const;//getѧ��
	int getsalary()const;//getн��
	int getfaceScore()const;//get��ֵ
	string basic_information()const;//������Ϣ

private:
	string name = "";//����
	int age = 0;//���䣬��λ����
protected:
	int height = 0;//��ߣ���λ��cm
	string degree = "";//ѧ��
	int salary = 0;//н��
	int faceScore = 0;//��ֵ,����100
};

