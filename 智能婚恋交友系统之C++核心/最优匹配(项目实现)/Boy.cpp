#include "Boy.h"

Boy::Boy():Single("2",2)
{
	//cout<<"��������\n";
	//name = "";
	//age = 0;
	height = 2;
	degree = "2";
	salary = 2;
	faceScore = 2;
}

//Boy::Boy(string name, int age, int salary):Single(name,age)
Boy::Boy(const char* name, int age, int salary) : Single(name, age)
{//��ʼ���б���ֺ��������ж��,�﷨�޴�ʱ,Ӧ����Ƿ��Ӧ���Ͳ�ƥ����(const char* name ��Ӧ�������string name)
	//ʹ��ָ���ٶȿ�,�ռ��ܸ���ʡ
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
}*/


string Boy::basic_information() const
{
	stringstream ret;//������豸����cout���ƣ��Զ������ڴ淽��ĺ�
	ret << "�Ա�:��\t\t����:"<<this->getname() 
		<< "\t\tн��:" <<this->salary 
		<< "\t\tѧ��:" << this->degree
		<< "\t\t����:" <<this->getage();
	return ret.str();//�ô˷���תΪstring�ַ���
}

bool Boy::satisfied(const Girl& girl) const
{
	int facescore = salary * SALARY_COEFFICIENT;
	if (facescore > 80) {facescore = 80;}

	if (girl.getfaceScore() >= facescore) {
		return true;
	}
	else {
		return false;
	}
}

void Boy::inputBoys(vector<Boy>& boys)
{
//���static�����ڲ��ܵ��������ķ�static����(ʵ������),��Ϊstatic������������,������������,�����ڵ�������
	//getage();//ʾ��,��ȻҲ���ܷ��ʷ�static���ݳ�Ա(ʵ�����ݳ�Ա)
	string name;
	int salary;
	string degree;

	int n = 1;
	while (1) {
		cout << "�������" << n << "λС��������[����0����]:" ;
		cin >> name;
		if (name == "0") { break; }
		
		cout << "�������" << n << "λС����н��:" ;
		cin >> salary;

		cout << "�������" << n << "λС����ѧ��:" << endl;
		cin >> degree;

		boys.push_back(Boy(name.c_str(),salary,degree.c_str()));//.c_str()����:��stringת��char����
		n++;
	}
}

void Boy::inputBoy(Boy& boy)
{
	string name;
	int salary;
	string degree;

		cout << "������С��������:";
		cin >> name;

		cout << "������С����н��:";
		cin >> salary;

		cout << "������С����ѧ��:";
		cin >> degree;

		boy = Boy(name.c_str(), salary, degree.c_str());//.c_str()����:��stringת��char����
}

bool Boy::operator>(const Boy& boy)
{
	return salary > boy.salary;
}

ostream& operator<<(ostream& os, const Boy& boy)
{
	os<< "�Ա�:��\t\t����:" << boy.getname()
		<< "\t\tн��:" << boy.salary
		<< "\t\tѧ��:" << boy.degree
		<< "\t\t����:" << boy.getage();
	return os;
}
