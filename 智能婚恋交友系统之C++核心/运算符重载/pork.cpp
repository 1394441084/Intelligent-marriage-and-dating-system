#include "pork.h"
#include <iostream>




int pork::id = 0;

pork::pork(int weight)
{
	this->weight = weight;
}

pork::pork(const char* name, int weight, int price)
{
	if (!name)name = "��";
	this->name = new char[strlen(name)+1];//+1��Ž�����,��0��ʼ����,��������ֹͣ,�մ�����Ϊ0,�������'\0',���Կ��ٵĿ�ҪΪ1.
	strcpy_s(this->name, strlen(name)+1, name);//�������������û�и��ƵĻ�,�ͻ����ʹ�����ʱ��ָ�������ط����ֱ�������bug
	this->weight = weight;
	this->price = price;
	this->ID = ++id;
}

pork& pork::operator=(const pork& p)
{
	if(this==&p)return *this;//��ֹ�Լ����Լ���ֵ
	if (name)delete[] name;//�ͷ�ԭ���ڴ�;p1.name("rock")=p2.name("rockkk"),�ռ䲻��
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
	this->weight = p.weight;
	this->price = p.price;
	this->ID = p.ID+1;
	return *this;
}

int pork::operator[](string i)
{//Ϊ��ʹ������ӵĽ�׳,ʹ�ú궨���ܹ��ܺõı������
	if (i == ID_KEY) { return ID; }
	else if (i == WEIGHT_KEY) { return weight; }
	else if (i == PRICE_KEY) { return price; }
	else { return -1; }
}
int pork::operator[](int i)
{
	if (i == id_key) { return ID; }
	else if (i == weight_key) { return weight; }
	else if (i == price_key) { return price; }
	else { return -1; }
}
/*
char* pork::operator[](string i)
{
	if (i == "����") { return name; }
	else { return NULL; }
}*/

/*ʹ�ó�Ա��������<<�����
ostream& pork::operator<<(ostream& os) const
{
	name ? os << "��" << ID << "ͷ�������:" << name << "\t�������:" << weight << "\t��ļ۸�:" << price :
		os << "�������:" << weight;
	return os;
}*/

pork::~pork()
{
	if (name) {
		delete[] name;
		cout << "��\n";
	}
}

string pork::describe()
{
	stringstream str;

	name ? str << "��" << ID << "ͷ�������:" << name << "\t�������:" << weight << "\t��ļ۸�:" << price :
		str << "�������:" << weight;
	return str.str();
}
