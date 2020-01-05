#include "Home.h"

Home::Home()
{
	nickname = "";
	age = 0;
	gender = man;
}

Home::Home(const string& nickname, int age, Gender_T gender)
{
	this->nickname = nickname;
	this->age = age;
	this->gender = gender;
}

Home::~Home()
{
}

void Home::Marriage(Home& spouse)//聚合关系
{
	if (spouse.gender == gender) { return; }//同性就不结婚

	this->spouse = &spouse;//我的配偶=你
	spouse.spouse = this;//你的配偶=我
}

void Home::divorce()
{
	if (this->spouse == NULL) { 
		cout << "你这个单身汉,离啥婚呢.\n";//扎心
			return;}

	spouse->spouse = NULL;//配偶的配偶=NULL;
	spouse = NULL;//我的配偶=NULL;伤心
}

void Home::MakeFriends(Home& friendss)
{
	friends.push_back(&friendss);
}

void Home::Break_Off_Friendship(Home& friendss)
{
	//auto x = 100;//int x=100;//C++11的新特性.自动分配类型方法
	//调用.begin();方法的时候返回一个特殊的指针,指向第一个成员!!!(迭代器)
	//不是&friends[0];
	//.end();返回一个迭代器,指向最后一个元素的下一个位置
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &friendss) {
			//.erase();方法,返回值是一个迭代器,指向下一个成员
			//找到你了,使用erase()方法删除掉你,返回下一个成员赋值给it
			//相当于无缝链接
			it=friends.erase(it);
		}
		else {
			it++;
		}
	}
}
/*
void Home::Break_Off_Friendship(Home& friendss)
{//使用此方法会触发断点
	for (auto it = friends.begin(); it != friends.end();it++) {
		if (*it == &friendss) {
		//.erase()方法销毁it,返回it下一个成员,it指向的地方为空
			friends.erase(it);
		}
	}
}*/

string Home::getnickname() const
{
	return nickname;
}

int Home::getage() const
{
	return age;
}

Gender_T Home::getgender() const
{
	return gender;
}

string Home::Brief_introduction() const
{
	stringstream jj;
	jj << "nickname:" << nickname << "-age:" << age << "-gender:" << (gender==man?"男":"女") << endl;

	return jj.str();
}

Home* Home::getspouse() const
{
	return spouse;
}

vector<Home*> Home::getfriends() const
{
	return friends;
}
