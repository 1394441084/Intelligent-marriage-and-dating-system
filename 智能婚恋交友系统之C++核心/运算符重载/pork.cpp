#include "pork.h"
#include <iostream>




int pork::id = 0;

pork::pork(int weight)
{
	this->weight = weight;
}

pork::pork(const char* name, int weight, int price)
{
	if (!name)name = "空";
	this->name = new char[strlen(name)+1];//+1存放结束符,从0开始计算,到结束符停止,空串长度为0,但存放了'\0',所以开辟的空要为1.
	strcpy_s(this->name, strlen(name)+1, name);//这里如果结束符没有复制的话,就会出现使用左参时会指向其它地方出现崩溃或者bug
	this->weight = weight;
	this->price = price;
	this->ID = ++id;
}

pork& pork::operator=(const pork& p)
{
	if(this==&p)return *this;//防止自己给自己赋值
	if (name)delete[] name;//释放原来内存;p1.name("rock")=p2.name("rockkk"),空间不够
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
	this->weight = p.weight;
	this->price = p.price;
	this->ID = p.ID+1;
	return *this;
}

int pork::operator[](string i)
{//为了使程序更加的健壮,使用宏定义能够很好的避免错误
	if (i == ID_KEY) { return ID; }
	else if (i == WEIGHT_KEY) { return weight; }
	else if (i == PRICE_KEY) { return price; }
	else { return -1; }
}
int pork::operator[](int i)
{
	if (i == id_key) { return ID; }
	else if (i == weight_key) { return weight; }
	else if (i == price_key) { return price; }
	else { return -1; }
}
/*
char* pork::operator[](string i)
{
	if (i == "姓名") { return name; }
	else { return NULL; }
}*/

/*使用成员函数重载<<运算符
ostream& pork::operator<<(ostream& os) const
{
	name ? os << "第" << ID << "头猪的名字:" << name << "\t猪的体重:" << weight << "\t猪的价格:" << price :
		os << "猪的体重:" << weight;
	return os;
}*/

pork::~pork()
{
	if (name) {
		delete[] name;
		cout << "消\n";
	}
}

string pork::describe()
{
	stringstream str;

	name ? str << "第" << ID << "头猪的名字:" << name << "\t猪的体重:" << weight << "\t猪的价格:" << price :
		str << "猪的体重:" << weight;
	return str.str();
}
