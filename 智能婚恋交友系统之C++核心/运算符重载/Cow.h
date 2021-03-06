#pragma once
#include <string>
#include <sstream>
using namespace std;

class pork;
class Goat;
class Cow //牛类
{
public:
	Cow(int weight = 0);
	Cow(const char* name = "空");

	//类类型转类类型
	Cow(const pork& pork0);

	~Cow();

	//使用运算符重载来实现变态加法
	//使用operator运算符重载有一个默认参数是对象本身如自己(Cow)
	pork operator+(const Goat& goat);//一头牛+一只羊=多少斤猪肉
	pork operator+(const Cow& cow);//一头牛+一头牛=多少斤猪肉
	Cow operator+(int n);

	//类类型转普通类型(类型运算符重载不需返回类型)
	operator int()const;
	operator char* ()const;

	friend ostream& operator<<(ostream& os, const Cow& cow0);

	string describe();//描述信息

private:
	char* name = NULL;
	int weight=0;//体重
	friend pork operator-(const Cow& cow1, const Cow& cow2);
	friend pork operator-(const Goat& cow1, const Cow& cow2);
	friend pork operator-(const Cow& cow2, const Goat& cow1);
	friend Cow operator+(int n, const Cow& cow);
};

