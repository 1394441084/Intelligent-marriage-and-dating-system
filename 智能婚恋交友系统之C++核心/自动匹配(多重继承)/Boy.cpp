#include "Boy.h"

Boy::Boy():Single("2",2)
{
	//cout<<"调用我了\n";
	//name = "";
	//age = 0;
	height = 2;
	degree = "2";
	salary = 2;
	faceScore = 2;
}

//Boy::Boy(string name, int age, int salary):Single(name,age)
Boy::Boy(const char* name, int age, int salary) : Single(name, age)
{//初始化列表出现函数重载有多个,语法无错时,应检查是否对应类型不匹配如(const char* name 对应子类的是string name)
	//使用指针速度快,空间能更节省
	//this->name = name;
	//this->age = age;
	this->salary = salary;
	this->height = 2;
	this->degree = "2";
	this->salary = salary;
	this->faceScore = 2;
}

Boy::Boy(const char* name, int salary, const char* degree):Single(name,2)
{
	//this->name = name;
	//this->salary = salary;
	this->height = 2;
	this->degree = degree;
	this->salary = salary;
	this->faceScore = 2;
}

Boy::Boy(const char* name, int age, int height, const char* degree, int salary, int faceScore):Single(name, age)
{
	//this->name = name;
	//this->age = age;
	this->height = height;
	this->degree = degree;
	this->salary = salary;
	this->faceScore = faceScore;
}

Boy::Boy(const Boy& other):Single((other.getname()).c_str(),other.getage())
{
	this->height = other.height;
	this->degree = other.degree;
	this->salary = other.salary;
	this->faceScore = other.faceScore;
}

Boy::~Boy()
{
}
/*
string Boy::getname() const
{
	return name;
}

int Boy::getage() const
{
	return age;
}

int Boy::getheight() const
{
	return height;
}

string Boy::getdegree() const
{
	return degree;
}

int Boy::getsalary() const
{
	
	return salary;
}

int Boy::getfaceScore() const
{
	return faceScore;
}

string Boy::basic_information() const
{
	stringstream ret;//特殊的设备流如cout类似，自动分配内存方便的很
	ret << name << "-男-薪资（" << salary << ")-学历(" << degree << ")-年龄("<<age<<")";
	return ret.str();//用此方法转为string字符串
}*/

bool Boy::satisfied(const Girl& girl) const
{
	int facescore = salary * SALARY_COEFFICIENT;
	if (facescore > 80) {
		facescore = 80;
	}
	if (girl.getfaceScore() >= facescore) {
		return true;
	}
	else {
		return false;
	}
}

void Boy::inputBoys(vector<Boy>& boys)
{
//类的static方法内不能调用这个类的非static方法(实例方法),因为static方法独立于类,是用类名调用,不属于单个对象
	//getage();//示例,当然也不能访问非static数据成员(实例数据成员)
	string name;
	int salary;
	string degree;

	int n = 1;
	while (1) {
		cout << "请输入第" << n << "位小哥哥的姓名[输入0结束]:" ;
		cin >> name;
		if (name == "0") { break; }
		
		cout << "请输入第" << n << "位小哥哥的薪资:" ;
		cin >> salary;

		cout << "请输入第" << n << "位小哥哥的学历:" << endl;
		cin >> degree;

		boys.push_back(Boy(name.c_str(),salary,degree.c_str()));//.c_str()方法:将string转换char类型
		n++;
	}
}
