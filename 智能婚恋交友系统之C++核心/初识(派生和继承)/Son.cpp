#include "Son.h"

//没有显式调用父类的构造函数,会自动调用父类的默认构造函数
Son::Son()//:Father("Son",0)
{
	//name = "";
	//age = 0;
	game = "游戏";
}

//创建Son对象时会调用默认构造函数
//会先调用父类的构造函数,用来初识化从父类继承下来的数据
//再调用自己的构造函数,用来初始化自己定义的数据
//(因为有些东西是从父亲那继承下来的,所以子类不知道如何构建)
Son::Son(const char* name, int age, const char* game):Father(name,age){//在子类显式调用父类构造函数,自动调用对应版本的构造函数
	//没有体现父类的构造函数,那就会自动调用父类的默认构造函数,
	this->game = game;
}

Son::~Son()
{
}

string Son::getgame() const
{
	return game;
}

string Son::description()const {
	//public公有继承方式:子类的成员函数中无法直接访问从父类继承的private成员
	stringstream str;
	str << "  姓名:" << getname() << "  年龄:" << age <<"  游戏:"<< game << endl;
	return str.str();
}