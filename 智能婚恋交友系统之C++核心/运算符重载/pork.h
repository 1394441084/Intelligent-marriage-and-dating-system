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
	pork(int weight = 0);
	pork(const char* name = "猪", int weight = 0, int price = 0);
	//重载赋值运算符
	pork& operator=(const pork& p);

	//下标运算符重载
	int operator[](string i);
	int operator[](int i);
	//char* operator[](string i);//由于C++规则,所以不能重载返回类型不一样的

	// i输入 o输出运算符重载
	friend ostream& operator<<(ostream& os, const pork& pork);
	friend istream& operator>>(istream& is,pork& pork);
	/*使用成员函数重载<<运算符
	ostream& operator<<(ostream& os)const;//可以连续调用
	*/

	~pork();

	string describe();//描述信息
private:
	int weight = 0;//猪的体重
	char* name = NULL; //猪的名字
	int price = 0;//单价
	static int id;//第几头猪
	int ID = 0;
};

