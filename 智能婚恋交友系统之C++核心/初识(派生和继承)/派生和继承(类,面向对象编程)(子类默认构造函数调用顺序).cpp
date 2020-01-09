#include "Son.h"

//简单的例子实现"派生" "继承",(派生叫父类也叫基类)派生下为子类
//父类        子类
//继承方式分:公有,私有,保护等三种方式
/*
子类，一般会添加自己的数据成员/成员函数，
或者，重新定义从父类继承的方法!!!子类对象会调用自己定义的方法,而不会调用父类的重名方法
*/
/*
项目-属性-C/C++-命令行中   添加: /d1 reportSingleClassLayoutFather   /d1 reportSingleClassLayoutSon   
/d1 reportSingleClassLayout 命令  Father  类名   这是查看类内存分布情况vs2019没啥用处
*/

/*类的访问权限总结:
public:
外部可以直接访问,通过对象来访问这个成员如:
Father wjl("王健林", 66);
cout<<wjl.getname()<<endl;

private:
外部不可以访问
自己内部的成员函数可以访问
Father wjl("王健林", 66);
cout<<name<<endl;//错误
子类的成员函数不可以直接访问
只有自己的所有成员函数内才能直接访问

protected:
对内是public
对外是private:
和private很相似,不同的是子类的成员函数中可以直接访问
*/

class M {
public:
	M() {
		cout << __FUNCTION__ << endl;
	}

	~M() {
		cout << __FUNCTION__ << endl;
	}
};

class N {
public:
	N() {
		cout << __FUNCTION__ << endl;
	}

	~N() {
		cout << __FUNCTION__ << endl;
	}
};

class A {
public:
	A() {
		cout << __FUNCTION__ << endl;
	}

	~A() {
		cout << __FUNCTION__ << endl << endl;
	}
};

class B : public A {
public:
	B() {
		cout << __FUNCTION__ << endl << endl;
	}

	~B() {
		cout << __FUNCTION__ << endl;
	}
private:
	M m1;
	M m2;
	static N ms;
};

N B::ms;  //静态成员

int main(void) {
	while(0){//公有继承方式:Son继承Father的成员内容,public和protected都能直接访问,亲生儿继承法
	Father wjl("王健林", 66);
	cout << "------------\n";
	Son wsc("王思聪", 32,"英雄联盟");

	cout << wjl.description() << endl;
	cout << wsc.description() << endl;
	//cout << wsc.getname() << "  游戏:" << wsc.getgame() << endl;

	cout << sizeof(wjl) << endl;
	//成员函数不占空间,只耗了数据成员的内存
	cout << sizeof(wsc) << endl;

	break;}

	while (0) {//私有继承方式:Son继承Father的成员内容(但Father成员全变为private),私生儿继承法(继承给你,当是你不能告诉别人)
		Son wsc("王思聪", 32, "英雄联盟");
		cout << wsc.getage();//私生儿无法访问父类继承下来的public:成员
		break; }

	while (1) { //子类和父类的构造函数的调用顺序
		/*
		当创建子类对象时, 构造函数的调用顺序：
静态数据成员的构造函数 ->  父类的构造函数 ->  非静态的数据成员的构造函数 -> 自己的构造函数

注意: 
无论创建几个对象, 该类的静态成员只构建一次, 所以静态成员的构造函数只调用1次!!!
		*/
		/*
		子类的析构函数的调用顺序，和子类的构造函数的调用顺序相反！！！
记住，相反即可。
		*/
		B b;
		cout << "\n\n**************************\n\n";
		B c;


		break; }


	system("pause");
	return 0;
}