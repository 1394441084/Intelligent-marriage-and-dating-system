#include <iostream>
#include "Human.h"  //ͷ�ļ��ǹ����˰�����,������������ͷ�ļ���(.cpp�ļ����ǹ������������)

int HumanCount = 0;//����,���㶨���˶��ٸ�����,ȫ�ֱ�������ȫ,˭�������޸�
int Human::Humancount = 0;//����ľ�̬���ݳ�Ա���г�ʼ��

void Human::eat() {//ʵ��������ķ���(ʵ�ֳ�Ա����)
	cout << "eat��\n";
}
void Human::sleep() {
	cout << "sleep˯��\n";
}
void Human::play() {
	cout << "play��\n";
}
void Human::work() {
	cout << "work����\n";
}
string Human::getname() const {//����,�����const,������ʵ�ֲ����޸ĳ�Ա
	return name;
}
int Human::getage() {
	return age;
}
int Human::getsalary() const {
	return salary;
}
Human::Human():bloodType("B") {//ʹ���Զ����Ĭ�Ϲ��캯������ʼ����������ֵ,����Ҫ�������������ֵ��ʼ��,��Ȼ��Σ��
	//Human::Human():bloodType("B"){}����ǳ�ʼ���б�
	cout << "�����Զ���Ĭ�Ϲ��캯��:" << this << endl;
	name = "������.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "�����Զ���Ĭ�Ϲ��캯��");
	HumanCount++;
	Humancount++;
}
Human::Human(string blodType):bloodType(blodType) {
	//Human::Human():bloodType("B"){}����ǳ�ʼ���б�
	cout << "�����Զ���Ĭ�Ϲ��캯��:" << this << endl;
	name = "������.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "�����Զ���Ĭ�Ϲ��캯��");
	HumanCount++;
	Humancount++;
}
Human::Human(int age, int salary) {
	this->name = name;//this������ָ��,ָ�������
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "���ô��������캯��");
	HumanCount++;
	Humancount++;
}
Human::Human(string name, int age) {//ʹ���Զ��������Ĭ�Ϲ��캯������ʼ����������ֵ
	//age=age;��Ϊ�����������������ı�.Ҫô����,Ҫô����
	this->name = name;//this������ָ��,ָ�������
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "���ô��������캯��");
	HumanCount++;
	Humancount++;
}
Human::Human(string name, int age, int salary, char* addr) {//ʹ���Զ��������Ĭ�Ϲ��캯������ʼ����������ֵ
	//age=age;��Ϊ�����������������ı�.Ҫô����,Ҫô����
	cout << "���ô˺�������\n";
	this->name = name;//this������ָ��,ָ�������
	this->age = age;//thisָ����ú����Ķ�����,�����ʻ����޸ĳ�Ա,��̬��Ա����
	this->salary = salary;
	addr = new char[addrlin];
	strcpy_s(this->addr, addrlin, addr);
	HumanCount++;
	Humancount++;
}


//Human hwx2 = hwx1;//const Human &other=hwx1
Human::Human(const Human& other) {//���忽�����̺���,��������,�����Ƕ���
	cout << "���ÿ������캯��\n";//ʹ�ñ�����Ĭ�Ͽ������캯����Σ��(ǳ����)
	name = other.name;//ʹ���Զ��忽������,������Ҫ���������ʼ��,��Ȼ���������Զ�Ĭ�Ϻϳɳ�ʼֵ,ָ���ֱ�ӹ�
	age = other.age;
	salary = other.salary;
	addr = other.addr;
}

void Human::test() const {
	cout << "����:" << name << endl;//�����෽��,�����ú���
	cout << "����:" << age << endl;
	cout << "н��:" << salary << endl;
	strcpy_s(addr, addrlin, "aaaa");//const����û�б�,ֻ��������,�ѿռ�����ݸı���
	cout << "��ַ:" << addr << endl;
	cout << "�б��ʼѪ��:" << bloodType << endl;
	cout << "���ڳ�ʼѪ��:" << bloodtype << endl;
}

void Human::addr1(const char* addr) {//�޸ĵ�ַ
	if (!addr)return;
	strcpy_s(this->addr, addrlin, addr);
}

//���ú��� showmsg(h1)
//�ڽ��в�������ʱ,�Զ�ִ��:Human &man =h1;
void showmsg(const Human& man) {//���ݵĲ����Ƕ���,�Զ������˿������̺���
	//���ݵĲ��������õĻ�,�Ͳ����ÿ������̺���,�ô������˿���,�����ᱻ�޸�,���const
	cout << man.getname() << "�Ļ�����Ϣ:\n";
	man.test();
}

/*
Human getBetterman(Human &man1, Human &man2) {//�����������õĻ�,����ÿ������캯��
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

Human& Human::operator=(const Human& other) {//��ֵ���캯��f6=f5ʱ�Զ�����
	cout << "�����˸�ֵ���캯��\n";
	if (this == &other) {
		return *this;//Ϊ�˷�ֹf1=f1;��ֹ������Լ���ֵ
	}
	//���f1=f2;�ͻ��Զ�����operator=(this);operator=(f2);
	name = other.name;
	age = other.age;
	salary = other.salary;
	//����б�Ҫ���ͷ��Լ�����Դ(�綯̬�ڴ�)
	//addr = other.addr;//ǳ����
	strcpy_s(addr, addrlin, other.addr);//���

	//���ض����������,Ϊ�˷�������ʽ������:f1=f2=f3.
	return *this;//���뷵��.Ϊ��ֹf1=f2=f3;�������,ͻȻ���ؿյ����
}
//��������,������������,��Ȼ�����г���,��Σ��
Human::~Human() {
	cout << "������������:" << this << endl;
	delete addr;//�����������ڶ�������ǰ�Զ����õĺ���
}

int Human::getHumancount() {
	return Humancount;
}