#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define WEIGHT_KEY  "����"
#define PRICE_KEY   "����"
#define ID_KEY		"���"
#define NAME_KEY	"����"

typedef enum {
	id_key,
	weight_key,
	price_key
}PORK_KEY;

class pork //������
{
public:
	pork(int weight = 0);
	pork(const char* name = "��", int weight = 0, int price = 0);
	//���ظ�ֵ�����
	pork& operator=(const pork& p);

	//�±����������
	int operator[](string i);
	int operator[](int i);
	//char* operator[](string i);//����C++����,���Բ������ط������Ͳ�һ����

	// i���� o������������
	friend ostream& operator<<(ostream& os, const pork& pork);
	friend istream& operator>>(istream& is,pork& pork);
	/*ʹ�ó�Ա��������<<�����
	ostream& operator<<(ostream& os)const;//������������
	*/

	~pork();

	string describe();//������Ϣ
private:
	int weight = 0;//�������
	char* name = NULL; //�������
	int price = 0;//����
	static int id;//�ڼ�ͷ��
	int ID = 0;
};

