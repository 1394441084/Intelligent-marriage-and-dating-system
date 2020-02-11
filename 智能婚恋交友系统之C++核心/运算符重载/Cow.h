#pragma once
#include <string>
#include <sstream>
using namespace std;

class pork;
class Goat;
class Cow //ţ��
{
public:
	Cow(int weight = 0);
	Cow(const char* name = "��");

	//������ת������
	Cow(const pork& pork0);

	~Cow();

	//ʹ�������������ʵ�ֱ�̬�ӷ�
	//ʹ��operator�����������һ��Ĭ�ϲ����Ƕ��������Լ�(Cow)
	pork operator+(const Goat& goat);//һͷţ+һֻ��=���ٽ�����
	pork operator+(const Cow& cow);//һͷţ+һͷţ=���ٽ�����
	Cow operator+(int n);

	//������ת��ͨ����(������������ز��践������)
	operator int()const;
	operator char* ()const;

	friend ostream& operator<<(ostream& os, const Cow& cow0);

	string describe();//������Ϣ

private:
	char* name = NULL;
	int weight=0;//����
	friend pork operator-(const Cow& cow1, const Cow& cow2);
	friend pork operator-(const Goat& cow1, const Cow& cow2);
	friend pork operator-(const Cow& cow2, const Goat& cow1);
	friend Cow operator+(int n, const Cow& cow);
};

