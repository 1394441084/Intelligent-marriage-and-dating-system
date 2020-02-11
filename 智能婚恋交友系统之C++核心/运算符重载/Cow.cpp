#include "Cow.h"
#include "pork.h"
#include "Goat.h"

Cow::Cow(int weight)
{
	const char* name = "kong";
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->weight = weight;
}

Cow::Cow(const char* name)
{
	if (!name||name==" "||name=="\t"||name=="\0")name = "�տ���Ҳ";//name==""ҲҪ�ӽ�ȥ,��Ȼ���ǲ���տ���Ҳ
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	weight = 0;
}

Cow::Cow(const pork& pork0)
{
	//(char*)pork0;//����operator char* ()const;����,����pork0��˽�г�Աname
	int len = strlen((char*)pork0) + 1;
	name = new char[len];
	strcpy_s(name, len, (char*)pork0);

	//���õ���const����,������ص�[]���������const����,��������ȥѰ��������const�����,�Ӷ��õ����
	weight = pork0[weight_key];
}

Cow::~Cow()
{
	if (name) {
		delete[] name;
	}
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

Cow::operator int() const
{
	return weight;
}

Cow::operator char* () const
{
	return name;
}

string Cow::describe()
{
	stringstream str;
	str <<"����"<< name <<"����"<< weight << "��ţ��";
	return str.str();
}


