#include "Boy.h"

Boy::Boy()
{
	name = "";
	age = 0;
	height = 0;
	degree = "";
	salary = 0;
	faceScore = 0;
}

Boy::Boy(string name, int age, int salary)
{
	this->name = name;
	this->age = age;
	this->salary = salary;
}

Boy::Boy(string name, int salary, string degree)
{
	this->name = name;
	this->salary = salary;
	this->degree = degree;
}

Boy::Boy(string name, int age, int height, string degree, int salary, int faceScore)
{
	this->name = name;
	this->age = age;
	this->height = height;
	this->degree = degree;
	this->salary = salary;
	this->faceScore = faceScore;
}

Boy::~Boy()
{
}

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
}

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

		boys.push_back(Boy(name,salary,degree));
		n++;
	}
}
