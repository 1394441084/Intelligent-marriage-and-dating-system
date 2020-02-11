#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define WEIGHT_KEY  "体重"
#define PRICE_KEY   "单价"
#define ID_KEY		"编号"
#define NAME_KEY	"姓名"

typedef enum {
	id_key,
	weight_key,
	price_key
}PORK_KEY;

class pork //猪肉类
{
public:
	pork(int weight = 0);//普通类型转类类型
	pork(const char* name);
	pork(const char* name, int weight, int price);
	//重载赋值运算符
	pork& operator=(const pork& p);
	/*
	pork& operator=(const pork p);//使用此运算符重载会出现重大错误,如销毁掉name

	实现代码:
	pork1=pork2;//执行pork1& operator=(const pork2);//相当于pork2 = p;

	过程解析:
	先执行pork1=pork2;//pork1被赋值为pork2;
	当pork& operator=(const pork p);函数结束,栈空间毁灭,此时调用p的析构函数
	那么最后就成这样了pork2 = p;//不是再次调用赋值,pork2被赋值为p  //是调用拷贝构造函数(编译器合成的必出问题)
	---------------pork2的char *name,就成了非法内存了,因为指向了被毁灭的空间

	解决方法:
	自定义的拷贝构造函数(深拷贝,位拷贝)

	总结:
	最好别使用此种方式,不然会增加额外的开销,或者不必要的麻烦
	如果定义成pork& operator=(const pork* p);//无效!!!编译器不识别为赋值运算符重载.也就是pork1=pork2;不会调用.
	*/

	//下标运算符重载
	int operator[](string i)const;
	int operator[](int i)const;
	//char* operator[](string i);//由于C++规则,所以不能重载返回类型不一样的

	// i输入 o输出运算符重载
	friend ostream& operator<<(ostream& os, const pork& pork);
	friend istream& operator>>(istream& is,pork& pork);
	/*使用成员函数重载<<运算符
	ostream& operator<<(ostream& os)const;//可以连续调用
	*/

	//类类型转普通类型(类型运算符重载不需返回类型)
	operator int ()const;//"pork::operator []": 2个重载有相似的转换
	operator char* ()const;

	~pork();

	string describe();//描述信息
private:
	int weight = 0;//猪的体重
	char* name = NULL; //猪的名字
	int price = 0;//单价
	static int id;//第几头猪
	int ID = 0;
};

