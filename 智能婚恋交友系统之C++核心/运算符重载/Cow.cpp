#include "Cow.h"
#include "pork.h"
#include "Goat.h"

Cow::Cow(int weight)
{
	this->weight = weight;
}

pork Cow::operator+(const Goat& goat)
{
	/*�ӷ�����:
	һ��ţ��:��������
	һ������:��������
	*/
	int tmp = this->weight*2+goat.getweight()*3;
	return pork(tmp);
}

pork Cow::operator+(const Cow& cow)
{
	int tmp = (this->weight + cow.weight) * 2;


	return pork(tmp);//����һ��������Ķ���
}

Cow Cow::operator+(int n)
{
	int tmp = weight + n;
	return Cow(tmp);
}

string Cow::describe()
{
	stringstream str;
	str << weight << "��ţ��";
	return str.str();
}


