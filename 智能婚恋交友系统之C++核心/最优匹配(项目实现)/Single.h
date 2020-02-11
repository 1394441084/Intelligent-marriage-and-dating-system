#pragma once
#include <iostream>
//#include <Windows.h>//出现system();使用不明确的问题,解决不了,需换#include <stdlib.h>
#include <vector>//vector容器相当于自动分配的动态数组，可以放如何东西，类型如何
#include <string>
#include <sstream> //stringstream,往里面塞如何东西都能变为字符串
#include <iomanip>//控制输出输入字符串的精度(长度)
#include <stdio.h>//sscanf_s的头文件
#include <stdlib.h>//解决system();使用不明确的问题

using namespace std;
class Single
{
public:
	//Single();
	//Single(const string name="",int age=0);
	Single(const char* name = "", int age = 0, int height = 0,const char* degree="",int salary=0,int faceScore=0);
	~Single();

	string getname()const;//get名字
	int getage()const;//get年龄
	int getheight()const;//get身高
	string getdegree()const;//get学历
	int getsalary()const;//get薪资
	int getfaceScore()const;//get颜值
	string basic_information()const;//基本信息

private:
	string name = "";//姓名
	int age = 0;//年龄，单位：岁
protected:
	int height = 0;//身高，单位：cm
	string degree = "";//学历
	int salary = 0;//薪资
	int faceScore = 0;//颜值,满分100
};

