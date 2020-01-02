#include <iostream>
#include <Windows.h>
#include "Human.h"

void testxg() {//测试析构函数的函数
	Human h1;
	{
		Human h2;
	}//h2消亡

	cout << "测试函数结束\n";
}//h1消亡

void testjt() {//测试调用静态数据成员的普通函数
	Human h1;//为了调用静态数据成员而创建的对象,没有意义
	cout << "总人数:" << h1.getHumancount() << endl;
}

void testjt1() {//测试类的静态方法,通过静态方法访问静态数据成员
	//创建类的静态成员函数后,访问类的静态数据成员的方法
	cout << "总人数:" << Human::getHumancount() << endl;//直接通过类名来调用
	//这方法属于整个类,不属于单个对象
	//类名:静态方法
	//静态方法相当于是静态一样跑到类外面了.

	//下面是类的声明
	//int getHumancount();//访问静态数据成员的方法,普通的类函数,有bug
	//类名:静态方法,不能使用this指针,只能访问全局数据成员
	//static int getHumancount();//类的静态成员函数,访问静态数据成员的方法
}

int main(void) {

	while (0) {

		while (0) {//自定义参数的构造函数和编译器默认的构造函数
			Human hwx;//定义一个hwx对象,默认使用默认构造函数(自定义>类内初始值>编译器合成)
			Human hwx1("何宛夏", 23);//调用自定义的构造函数,调用的时候还可以打印
			Human hwx2 = hwx1;//调用拷贝构造函数,展开和上面是一样的
			Human hwx3(hwx1);//调用拷贝构造函数,展开和上面是一样的

			char addr[addrlin] = "美国";

			hwx1.addr1(addr);//使用这个自定义拷贝函数后,修改的只有它

			hwx.test();
			/*注意!
			//(其它参数没有使用自定义,那么出现的值是类内初始值(没有类内初始值就是编译器合成的默认构造函数))
			如类里面有四个数据参数,而自定义的构造函数只传递两个,那么没有传递的那两个会
			成为(类内初始值(没有类内初始值就是编译器合成的默认构造函数)
			*/
			hwx1.test();//使用这个自定义拷贝函数后,修改的只有它
			hwx2.test();
			hwx3.test();
			break;
		}
		while (0) {//拷贝构造函数的基本使用
			Human h1(25, 3500);
			Human h2(28, 4000);
			//showmsg(h1);
			getBetterman(h1, h2);//返回一个临时对象,调用了一次拷贝构造函数,如果返回引用函数那么就不会调用拷贝构造函数
			break;
		}

		while (0) {//拷贝构造函数的调用时机
			Human f1, f2, f3, f4;
			Human F4[4] = { f1,f2,f3,f4 };
			break;
		}
		while (0) {//赋值构造函数示例:
			Human f5, f6;
			f6 = f5;//自动调用合成赋值构造函数,都是浅拷贝(位拷贝)
			f5.test();
			f6.test();

			cout << "\n移民后\n\n";

			f5.addr1("xin");
			f5.test();
			f6.test();
			break;
		}
		break;
	}

	while (0) {//析构函数(最后的晚餐)测试
		testxg();
		Human aa;

		cout << "总人数:" << HumanCount << endl;
		cout << "总人数:" << aa.getHumancount() << endl;
		//cout << "总人数:" << Humancount << endl;
		break;
	}
	while (0) {//静态数据成员的测试
		testxg();//析构函数
		testjt1();//通过类访问//类名:静态方法,不能使用this指针,只能访问全局数据成员
		testjt();//通过对象访问
		break;
	}
	while (0) {
		Human h1;
		Human h2("熊猫血");
		h1.test();
		h2.test();
		break;
	}
	while (1) {
		const Human h3;
		h3.test();

		break;
	}




	system("pause");
	return 0;
}