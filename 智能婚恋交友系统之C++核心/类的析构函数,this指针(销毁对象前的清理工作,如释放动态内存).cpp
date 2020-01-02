#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define addrlin 64 

//定义一个类"人类"
class Human {
public:  //公有的,对外的
	Human();//手动定义默认构造函数.没有返回值,连void都不能加
	Human(string name, int age);//自定义一个重载默认构造函数,根据需要来定义多个构造函数
	Human(string name, int age, int salary, char* addr);//自定义一个重载默认构造函数,根据需要来定义多个构造函数
	Human(int age, int salary);

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

private:  //私人的
	string name = "无名";//定义数据,成员数据
	int age;//C++11特性,可以直接类内初始值
	int salary;
	
	char* addr;//地址,由于C++11特性或者是编译器,所以必须要给类内指针初始赋值,不然会有极大危险,如指向空

	/*
	注意：
只要手动定义了任何一个构造函数，编译器就不会生成“合成的默认构造函数”
一般情况下，都应该定义自己的构造函数，不要使用“合成的默认构造函数”
【仅当数据成员全部使用了“类内初始值”，才宜使用“合成的默认构造函数”】
	*/
};//定义类,结束不能丢分号

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
Human::Human() {//使用自定义的默认构造函数来初始化类内数据值,必须要将类里面的所有值初始化,不然很危险
	cout << "调用自定义默认构造函数:" << this << endl;
	name = "何宛夏.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用自定义默认构造函数");
}
Human::Human(int age, int salary) {
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用带参数构造函数");
}
Human::Human(string name, int age) {//使用自定义的重载默认构造函数来初始化类内数据值
	//age=age;因为变量重名参数并不改变.要么改名,要么下面
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "调用带参数构造函数");
}
Human::Human(string name, int age, int salary, char* addr) {//使用自定义的重载默认构造函数来初始化类内数据值
	//age=age;因为变量重名参数并不改变.要么改名,要么下面
	cout << "调用此函数声明\n";
	this->name = name;//this是特殊指针,指向对象本身
	this->age = age;//this指向调用函数的对象本身,来访问或者修改成员,静态对象除外
	this->salary = salary;
	addr = new char[addrlin];
	strcpy_s(this->addr, addrlin, addr);
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
	cout << "地址:" << addr << endl;
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
	cout << "调用析构函数:"<<this<<endl;
	delete addr;//析构函数是在对象消亡前自动调用的函数
}
void testxg() {//测试析构函数的函数
	Human h1;
	{
		Human h2;
	}//h2消亡

	cout << "测试函数结束\n";
}//h1消亡

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

	while (1) {//析构函数(最后的晚餐)
		testxg();



		break;
	}



	system("pause");
	return 0;
}