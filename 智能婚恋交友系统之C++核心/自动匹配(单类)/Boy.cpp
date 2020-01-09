#include "Boy.h"

Boy::Boy()
{
	//cout<<"��������\n";
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
	stringstream ret;//������豸����cout���ƣ��Զ������ڴ淽��ĺ�
	ret << name << "-��-н�ʣ�" << salary << ")-ѧ��(" << degree << ")-����("<<age<<")";
	return ret.str();//�ô˷���תΪstring�ַ���
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

		boys.push_back(Boy(name,salary,degree));
		n++;
	}
}
