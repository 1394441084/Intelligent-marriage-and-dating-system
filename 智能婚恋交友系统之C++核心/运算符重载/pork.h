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
	pork(int weight = 0);//��ͨ����ת������
	pork(const char* name);
	pork(const char* name, int weight, int price);
	//���ظ�ֵ�����
	pork& operator=(const pork& p);
	/*
	pork& operator=(const pork p);//ʹ�ô���������ػ�����ش����,�����ٵ�name

	ʵ�ִ���:
	pork1=pork2;//ִ��pork1& operator=(const pork2);//�൱��pork2 = p;

	���̽���:
	��ִ��pork1=pork2;//pork1����ֵΪpork2;
	��pork& operator=(const pork p);��������,ջ�ռ����,��ʱ����p����������
	��ô���ͳ�������pork2 = p;//�����ٴε��ø�ֵ,pork2����ֵΪp  //�ǵ��ÿ������캯��(�������ϳɵıس�����)
	---------------pork2��char *name,�ͳ��˷Ƿ��ڴ���,��Ϊָ���˱�����Ŀռ�

	�������:
	�Զ���Ŀ������캯��(���,λ����)

	�ܽ�:
	��ñ�ʹ�ô��ַ�ʽ,��Ȼ�����Ӷ���Ŀ���,���߲���Ҫ���鷳
	��������pork& operator=(const pork* p);//��Ч!!!��������ʶ��Ϊ��ֵ���������.Ҳ����pork1=pork2;�������.
	*/

	//�±����������
	int operator[](string i)const;
	int operator[](int i)const;
	//char* operator[](string i);//����C++����,���Բ������ط������Ͳ�һ����

	// i���� o������������
	friend ostream& operator<<(ostream& os, const pork& pork);
	friend istream& operator>>(istream& is,pork& pork);
	/*ʹ�ó�Ա��������<<�����
	ostream& operator<<(ostream& os)const;//������������
	*/

	//������ת��ͨ����(������������ز��践������)
	operator int ()const;//"pork::operator []": 2�����������Ƶ�ת��
	operator char* ()const;

	~pork();

	string describe();//������Ϣ
private:
	int weight = 0;//�������
	char* name = NULL; //�������
	int price = 0;//����
	static int id;//�ڼ�ͷ��
	int ID = 0;
};

