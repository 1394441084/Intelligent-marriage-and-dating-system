#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>//vector容器相当于自动分配的动态数组，可以放如何东西，类型如何
#include <string>
#include "Girl.h"
using namespace std;
#define SALARY_COEFFICIENT 0.006  //薪资系数

class Boy
{
public:
	Boy();
	Boy(string name, int age, int salary);
	Boy(string name, int salary,string degree);
	Boy(string name, int age, int height, string degree, int salary, int faceScore);
	~Boy();

	string getname()const;//get名字
	int getage()const;//get年龄
	int getheight()const;//get身高
	string getdegree()const;//get学历
	int getsalary()const;//get薪资
	int getfaceScore()const;//get颜值
	string basic_information()const;//基本信息
	bool satisfied(const Girl& girl)const;//是否满意
	static void inputBoys(vector<Boy>&boys);//输入多个boy对象的方法接口
	void vectortest() {//测试vector容器陷阱的测试
		age += 10;
	}
private:
	string name="";//姓名
	int age=0;//年龄，单位：岁
	int height=0;//身高，单位：cm
	string degree="";//学历
	int salary=0;//薪资
	int faceScore=0;//颜值,满分100
};

