#pragma once
#include <string>
#include <sstream> //stringstream,往里面塞如何东西都能变为字符串

using namespace std;
#define FACE_COEFFICIENT 100  //颜值系数

class Boy;

class Girl
{
public:
	Girl();
	Girl(string name, int age, int faceScore);
	Girl(string name,int age,int height,string chest,int faceScore,int salary);
	~Girl();

	string getname()const;//get名字
	int getage()const;//get年龄
	int getheight()const;//get身高
	string getchest()const;//get胸
	int getfaceScore()const;//get颜值
	int getsalary()const;//get薪资
	string basic_information()const;//基本信息
	bool satisfied(const Boy& boy)const;//是否满意
	static void inputGirls(vector<Girl>&girls);//输入多个girl对象的方法接口
private:
	string name="没有name呢";//名字
	int age=0;//年龄,单位岁
	int height=0;//身高,单位cm
	string chest="没有chest呢";//胸围
	int faceScore=0;//颜值,满分100分
	int salary=0;//薪资
};

