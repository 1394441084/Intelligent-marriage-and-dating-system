#include "Cow.h"
#include "pork.h"
#include "Goat.h"

Cow::Cow(int weight)
{
	this->weight = weight;
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

string Cow::describe()
{
	stringstream str;
	str << weight << "斤牛肉";
	return str.str();
}


