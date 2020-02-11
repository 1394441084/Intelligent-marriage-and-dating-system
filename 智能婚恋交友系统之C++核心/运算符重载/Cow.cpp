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
	if (!name||name==" "||name=="\t"||name=="\0")name = "空空如也";//name==""也要加进去,不然还是不会空空如也
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	weight = 0;
}

Cow::Cow(const pork& pork0)
{
	//(char*)pork0;//调用operator char* ()const;函数,返回pork0的私有成员name
	int len = strlen((char*)pork0) + 1;
	name = new char[len];
	strcpy_s(name, len, (char*)pork0);

	//调用的是const方法,如果重载的[]运算符不是const方法,编译器会去寻找其它的const运算符,从而得到结果
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
	/*加法规则:
	一斤牛肉:两斤猪肉
	一斤羊肉:三斤猪肉
	*/
	int tmp = this->weight*2+goat.getweight()*3;
	return pork(tmp);
}

pork Cow::operator+(const Cow& cow)
{
	int tmp = (this->weight + cow.weight) * 2;


	return pork(tmp);//返回一个猪肉类的对象
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
	str <<"名字"<< name <<"体重"<< weight << "斤牛肉";
	return str.str();
}


