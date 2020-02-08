#pragma once
class Goat //羊类
{
public:
	Goat(int weight = 0);

	int getweight()const;
	//关系运算符重载
	bool operator>(Goat& goat);
	bool operator<(Goat& goat);
	bool operator==(Goat& goat);

private:
	int weight = 0;//体重

};

