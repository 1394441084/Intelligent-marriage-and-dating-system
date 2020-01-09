#pragma once

#include <string>
#include <string.h>

using namespace std;

#define addrlin 64 

extern int HumanCount;//声明,计算定义了多少个对象,全局变量不安全,谁都可以修改

//int Human::Humancount = 0;//对类的静态数据成员进行初始化,静态数据成员初始要在.cpp文件中


//定义一个类"人类"
class Human {
public:  //公有的,对外的
	Human();//手动定义默认构造函数.没有返回值,连void都不能加
	Human(string name, int age);//自定义一个重载默认构造函数,根据需要来定义多个构造函数
	Human(string name, int age, int salary, char* addr);//自定义一个重载默认构造函数,根据需要来定义多个构造函数
	Human(int age, int salary);
	Human(string blodType);//这是const类型的数据定义初始化的声明

	Human(const Human& other);//定义拷贝过程函数,引用类型,只有一个拷贝函数,无法重载

	//(operator=)(函数名)=运算符重载
	Human& operator=(const Human& other);//赋值构造函数f6=f5时自动调用

	~Human();//定义析构函数,不能带参数,只有一个版本

	void eat();//定义方法,"成员函数",吃
	void sleep();//睡觉
	void play();//玩
	void work();//工作
	void test() const;//打印测试信息
	void addr1(const char* addr);

	string getname() const;//名字,后面加const,函数的实现不会修改成员
	int getsalary() const;//薪资
	int getage();//年龄

	//int getHumancount();//访问静态数据成员的方法,普通的类函数,有bug
	//类名:静态方法,不能使用this指针,只能访问全局数据成员
	static int getHumancount();//类的静态成员函数,访问静态数据成员的方法

private:  //私人的
	string name = "无名";//定义数据,成员数据
	int age;//C++11特性,可以直接类内初始值
	int salary;

	char* addr;//地址,由于C++11特性或者是编译器,所以必须要给类内指针初始赋值,不然会有极大危险,如指向空

	static int Humancount;//定义一个静态数据成员

	const char bloodtype = 'A';//定义常量数据成员血型A,类内初始(C++11特性)
	const string bloodType;//通过初始化列表初始;
	/*
	注意：
只要手动定义了任何一个构造函数，编译器就不会生成“合成的默认构造函数”
一般情况下，都应该定义自己的构造函数，不要使用“合成的默认构造函数”
【仅当数据成员全部使用了“类内初始值”，才宜使用“合成的默认构造函数”】
	*/
};//定义类,结束不能丢分号

void showmsg(const Human& man);
const Human& getBetterman(const Human& man1, const Human& man2);