//#define _CRTDEG_MAP_ALLOC //检测动态内存泄漏

#include <iostream>
#include <stdlib.h>//检测动态内存泄漏
#include "Cow.h"
#include "Goat.h"
#include "pork.h"

/*
//检测动态内存泄漏
#include <crtdbg.h>
//替代new
#ifdef _DEBUG  
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK,__FILE__,__LINE__)
#define new DBG_NEW
#endif
#endif
*/

using namespace std;

ostream& operator<<(ostream& os, const Cow& cow0)
{
	cow0.name ? os<< "牛的名字:" << cow0.name << "\t牛的体重:"
		<< cow0.weight :
		os << "牛的体重:" << cow0.weight;
	return os;
}

pork operator-(const Cow& cow1, const Cow& cow2) {//使用友元函数实现运算符重载
	int tmp = (cow1.weight - cow2.weight)*2;
	return pork(tmp);
}

pork operator-(const Goat& cow1, const Cow& cow2) {//使用友元函数实现运算符重载
	int tmp = cow1.getweight()*3 - cow2.weight*2;
	return pork(tmp);
}

pork operator-(const Cow& cow2, const Goat& cow1) {//使用友元函数实现运算符重载
	int tmp = cow2.weight * 2- cow1.getweight() * 3;
	return pork(tmp);
}

//使用友元函数重载<<运算符
ostream& operator<<(ostream& os, const pork& pork) {
	pork.name ? os << "第" << pork.ID << "头猪的名字:" << pork.name << "\t猪的体重:" 
		<< pork.weight << "\t猪的价格:" << pork.price :
		os << "猪的体重:" << pork.weight;
	return os;
}
//使用友元函数重载>>运算符
istream& operator>>(istream& is, pork& pork) {
	//因为pork.name是char *name;会因输入而导致空间不足而访问到其它内存
	//使用string方便快捷的存储输入的字符串,在后面重新分配空间给pork.name
	string name1;
	char* p = NULL;
	p = pork.name;//指向同一块堆
	delete[] p;//内存泄漏问题解决,但pork.name不等于NULL,会随机指向一块内存,不手动指向的话,会发生可怕的后果
	//cout << pork.name << endl;//打印了葺葺葺葺葺,解决这问题:重载=运算符,好像也不顶用呀
	
	cout << "第?头猪\t姓名:?\t体重:?\t单价:?\n";
	is >> pork.ID >> name1 >> pork.weight >> pork.price;//由于cin保存不了空格,所以不需要理会name1是否为空
	pork.name = (char*)malloc((name1.length() + 1) * sizeof(char));//分配空间大小
	//将name1拷贝到pork.name,由于string是从0开始计算,所以加1;
	strcpy_s(pork.name, name1.length() + 1, name1.c_str());
	return is;
}

int main(void) {
	//使用成员函数实现运算符重载示例:
	while (0) { 
		Cow c1(100);
		Cow c2(200);
		//pork p =c1 + c2;//调用的是c1.operator+(c2);
		pork p = c1.operator+(c2);
		cout << p.describe() << endl;

		Goat g(100);
		//p = c1+g;
		p = c1.operator+(g);
		cout << p.describe() << endl;
		break;
	}

	//使用友元函数实现运算符重载示例:
	while (0) { 
		Cow c1(100);
		Cow c2(200);

		pork p = c1 - c2;//-200
		cout << p.describe() << endl;

		Goat g(100);
		p = g - c1;//100
		cout << p.describe() << endl;

		p = c1 - g;//-100
		cout << p.describe() << endl;
		break;
	}

	//友元函数和成员函数重载示例:
	while (0) { 
		Cow c(100);
		Cow c1 = c + 200;//300
		Cow c2 = 300 + c;//必须用友元函数来做

		cout << c1.describe() << endl;
		cout << c2.describe() << endl;
		break;
	}

	// =运算符重载
	while (0) {
		pork p("小猪", 50, 30); pork p1(80), p2(90);
		cout << p.describe() << endl;
		cout << p1.describe() << endl;
		cout << p2.describe() << endl;
		p1 = p2 = p;
		cout << "\n-------------赋值后-------------\n\n";
		cout << p.describe() << endl;
		cout << p1.describe() << endl;
		cout << p2.describe() << endl;
		break;
	}

	//关系运算符重载
	while (0) { 
		Goat y1(80), y2(100);
		if (y1 > y2) {
			cout << "y1重\n";
		}
		else if (y1 == y2) {
			cout << "一样重\n";
		}
		else {
			cout << "y2重\n";
		}
		break;
	}
	
	//下标运算符重载 []
	while (1) {

		pork p("猪猪侠", 1000, 100);
		/*
		if(p["姓名"]){
		cout << p["姓名"] << endl;
		}
		else {
			cout << "kongkong\n";
		}*/
	
		//优化后,即可读,又能避免错误

		//当使用operator int()const;//会出现重大错误"pork::operator []": 2个重载有相似的转换
		//cout << p[WEIGHT_KEY] << "\t" << p["45"] << "\t" << p[PRICE_KEY] << endl;//使用字符串来进行读写不是很兼容

		cout << "-----------重载后----------\n";
		cout << p[weight_key] << "\t" << p[id_key] << "\t" << p[price_key] << endl;
		break;
	}


	//输出输入运算符重载
	while (0) {
		pork p("猪猪侠", 1000, 100);
		pork p1(300);
		/*使用成员函数重载<<运算符
		p1<<(p << cout << endl)<<endl;//p.operator<<(cout);这种方式好恶心呀,不方便
		//cout << p;
		//cout.operator<<(p);//.operator<<()方法是p的,cout无法调用
		*/

		//使用友元函数重载<<运算符
		cout << p << endl << p1 << endl;

		cin >> p;

		cout << p << endl;

		break;
	}

	/*
	string n = "\0";
	cout << n.length() << endl;
	cout << size(n) << endl;
	cout << strlen(n.c_str()) << endl;
	*/

	//普通类型转类类型
	while (0) {
		pork pork1 = 1000;//体重 构造函数pork(int);
		pork pork2 = "huahua";//名字 构造函数pork(char *);

		cout << pork1 << endl;
		cout << pork2 << endl;
		break;
	}

	//类类型转普通类型
	while (0) { 
		Cow c(250);
		Cow a("而已");
		int weight = c;//250
		char* name = a;//"而已"

		cout << a.describe() << endl;
		cout << weight << endl;
		cout << name << endl;
		break; }

	//类类型转类类型
	while (0) { 
		pork p("", 2000, 50);
		Cow c = p;
		char* n = p;
		int i = p;
		cout << p << "\n";
		cout << c << "\n";
		cout << n << endl;
		cout << i << endl;
		break; }

	//_CrtDumpMemoryLeaks();//检测动态内存泄漏
	system("pause");
	return 0;
}
Cow operator+(int n, const Cow& cow) {
	int tmp = cow.weight + n;
	return Cow(tmp);
}