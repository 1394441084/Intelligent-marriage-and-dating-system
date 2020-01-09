#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

class Father {
public:
	Father(const char* lastName="父亲姓",const char* fristName="父亲名"){
		this->lastName=lastName;this->fristName=fristName; cout << __FUNCTION__ << endl;}
	~Father() {}

	void playBasketball() {//打篮球
		cout << "打篮球\n";}
	void dance() {//跳舞
		cout << "父亲类舞\n";}

protected:
	string lastName;//姓
	string fristName;//名
};

class Mother {
public:
	Mother(const char* food = "钱",const char* lastName="母亲姓", const char* fristName="母亲名") {
		this->food = food;this->lastName = lastName;this->fristName = fristName; cout << __FUNCTION__ << endl;}
	~Mother(){}

	void dance() {//跳舞
		cout << "母亲类舞\n";}
	string getfood() {
		return food;
	}

private:
	string lastName;//姓
	string fristName;//名
//protected:
	string food;//喜欢的事物
};

class Son : public Mother,public Father {//多重继承,class Son : public Father,private Mother 也可以这样
	//默认构造函数的顺序和单系继承一样,只是在父类继承中顺序是以上为标准
public:
	Son(const char *lastName,const char *fristName,const char *food,const char *game);
	~Son(){}

	void playgame();
	void dance() {//跳舞
		Father::dance();
		Mother::dance();
	}
private:
	string game;

};

int main(void) {
	Son wsc("王", "思聪", "B","多开");
	wsc.playBasketball();
	//wsc.dance();
	wsc.Father::dance();//调成员时,限定哪个父类的方法,就能解决掉调用不明确的问题
	//解决多重继承的二义性的方法(1)
	wsc.Mother::dance();//使用"类名::"指定,指定调用从哪个基类继承的方法(成员)
	wsc.playgame();
	cout << "\n------------*************-------------\n";
	wsc.dance();//解决多重继承的二义性的方法(2),在子类中重新实现重名方法,在方法内部使用基类名限定调用对应的方法

	system("pause");
	return 0;
}

Son::Son(const char* lastName, const char* fristName, const char* food, 
	const char* game):Father(lastName,fristName),Mother(food)
{
	/*Mother(food)会调用:
	Mother(const char* food = "钱",const char* lastName="母亲姓", const char* fristName="母亲名") ,
	按顺序覆盖,只填一个就只覆盖第一个,后面按照自定的来处理,如果没有自定义的话编译器就会找类内初始化>电脑合成默认初始化*/
	this->game = game;
	cout << __FUNCTION__ << endl;
}

void Son::playgame() {

	cout << "一起玩" << game << "吧,食物:" << getfood() << endl;
}