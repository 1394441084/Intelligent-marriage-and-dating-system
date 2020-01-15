#pragma once
#include "Single.h"

#define FACE_COEFFICIENT 100  //颜值系数

class Boy;
//class(英语意思):类(不是指"班级")
class Girl : public Single
{
public://公有的
	Girl();
	Girl(const char* name, int age, int faceScore);
	Girl(const char* name,int age,int height,const char* chest,int faceScore,int salary);
	~Girl();

	/*
	string getname()const;//get名字
	int getage()const;//get年龄
	int getheight()const;//get身高
	int getfaceScore()const;//get颜值
	int getsalary()const;//get薪资*/
	string basic_information()const;//基本信息
	
	string getchest()const;//get胸
	bool satisfied(const Boy& boy)const;//是否满意
	static void inputGirls(vector<Girl>&girls);//输入多个girl对象的方法接口
	static void inputGirl(Girl& girl);//输入单个girl对象的方法接口
	//static(英语意思):静态
protected://私有的
	string chest="没有chest呢";//胸围
};

