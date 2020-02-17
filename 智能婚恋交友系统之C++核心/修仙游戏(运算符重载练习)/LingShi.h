#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

//灵石等级(枚举) //由于使用的是C++11的新标准,所以不能直接和int挂钩
enum class LingShiGrade {
	PRIMARY,     //初阶
	MIDDLE_RANK, //中阶
	EXPERT,      //高阶
	TOTAL_GRADE  //总阶级,有多少等级(常用于边界处理)
};

//灵石类
class LingShi
{
public:
	LingShi(int number=0, LingShiGrade grade= LingShiGrade::PRIMARY);//注意:在此使用枚举需用限定符

	string str()const;//转换字符串,调用它就能得到字符串

	friend ostream& operator<<(ostream& os,const LingShi& lingshi);//重载<<

	LingShi operator+(const LingShi& other)const;//重载+
	LingShi operator-(const LingShi& other)const;//重载+
	bool operator>=(const LingShi& other)const;//重载>=

	int getNumber()const;//获取多少块灵石
private:
	int number;//数量:  块
	LingShiGrade grade;//灵石的等级:初阶 中阶 高阶
};

