#include <iostream>
#include "Human.h"  //头文件是供别人包含的,编译器不编译头文件的(.cpp文件才是供编译器编译的)

int HumanCount = 0;//定义,计算定义了多少个对象,全局变量不安全,谁都可以修改
int Human::Humancount = 0;//对类的静态数据成员进行初始化

void Human::eat() {//实现类里面的方法(实现成员函数)
	cout << "eat吃\n";
}
void Human::sleep() {
	cout << "sleep睡觉\n";
}
void Human::play() {
	cout << "play玩\n";
}
void Human::work() {
	cout << "work工作\n";
}
string Human::getname() const {//名字,后面加const,函数的实现不会修改成员
	return name;
}
int Human::getage() {
	return age;
}
int Human::getsalary() const {
	return salary;
}
Human::Human():bloodType("B") {//使用自定义的默认构造函数来初始化类内数据值,必须要将类里面的所有值初始化,不然很危险
	//Human::Human():bloodType("B"){}这个是初始化列表
	cout << "调用自定义默认构造函数:" << this << endl;
	name = "何宛夏.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用自定义默认构造函数");
	HumanCount++;
	Humancount++;
}
Human::Human(string blodType):bloodType(blodType) {
	//Human::Human():bloodType("B"){}这个是初始化列表
	cout << "调用自定义默认构造函数:" << this << endl;
	name = "何宛夏.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用自定义默认构造函数");
	HumanCount++;
	Humancount++;
}
Human::Human(int age, int salary) {
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用带参数构造函数");
	HumanCount++;
	Humancount++;
}
Human::Human(string name, int age) {//使用自定义的重载默认构造函数来初始化类内数据值
	//age=age;因为变量重名参数并不改变.要么改名,要么下面
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用带参数构造函数");
	HumanCount++;
	Humancount++;
}
Human::Human(string name, int age, int salary, char* addr) {//使用自定义的重载默认构造函数来初始化类内数据值
	//age=age;因为变量重名参数并不改变.要么改名,要么下面
	cout << "调用此函数声明\n";
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;//this指向调用函数的对象本身,来访问或者修改成员,静态成员除外
	this->salary = salary;
	addr = new char[addrlin];
	strcpy_s(this->addr, addrlin, addr);
	HumanCount++;
	Humancount++;
}


//Human hwx2 = hwx1;//const Human &other=hwx1
Human::Human(const Human& other) {//定义拷贝过程函数,引用类型,传的是对象
	cout << "调用拷贝构造函数\n";//使用编译器默认拷贝构造函数很危险(浅拷贝)
	name = other.name;//使用自定义拷贝函数,必须需要在类里面初始化,不然编译器会自动默认合成初始值,指针会直接挂
	age = other.age;
	salary = other.salary;
	addr = other.addr;
}

void Human::test() const {
	cout << "名字:" << name << endl;//调用类方法,即调用函数
	cout << "年龄:" << age << endl;
	cout << "薪资:" << salary << endl;
	strcpy_s(addr, addrlin, "aaaa");//const的心没有变,只是她变了,堆空间的内容改变了
	cout << "地址:" << addr << endl;
	cout << "列表初始血型:" << bloodType << endl;
	cout << "类内初始血型:" << bloodtype << endl;
}

void Human::addr1(const char* addr) {//修改地址
	if (!addr)return;
	strcpy_s(this->addr, addrlin, addr);
}

//调用函数 showmsg(h1)
//在进行参数传递时,自动执行:Human &man =h1;
void showmsg(const Human& man) {//传递的参数是对象,自动调用了拷贝过程函数
	//传递的参数是引用的话,就不调用拷贝过程函数,好处减少了开销,坏处会被修改,需加const
	cout << man.getname() << "的基本信息:\n";
	man.test();
}

/*
Human getBetterman(Human &man1, Human &man2) {//参数不是引用的话,会调用拷贝构造函数
	if (man1.getsalary() > man2.getsalary()) {
		return man1;
	}
	else {
		return man2;
	}
}
*/

const Human& getBetterman(const Human& man1, const Human& man2) {
	if (man1.getsalary() > man2.getsalary()) {
		cout << "man1\n";
		return man1;
	}
	else {
		cout << "man2\n";
		return man2;
	}
}

Human& Human::operator=(const Human& other) {//赋值构造函数f6=f5时自动调用
	cout << "调用了赋值构造函数\n";
	if (this == &other) {
		return *this;//为了防止f1=f1;防止对象给自己赋值
	}
	//如果f1=f2;就会自动调用operator=(this);operator=(f2);
	name = other.name;
	age = other.age;
	salary = other.salary;
	//如果有必要先释放自己的资源(如动态内存)
	//addr = other.addr;//浅拷贝
	strcpy_s(addr, addrlin, other.addr);//深拷贝

	//返回对象本身的引用,为了方便能链式处理如:f1=f2=f3.
	return *this;//必须返回.为防止f1=f2=f3;这种情况,突然返回空的情况
}
//析构函数,不能主动调用,不然会运行出错,很危险
Human::~Human() {
	cout << "调用析构函数:" << this << endl;
	delete addr;//析构函数是在对象消亡前自动调用的函数
}

int Human::getHumancount() {
	return Humancount;
}