#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>

using namespace std;

typedef enum Gender {
	man,	//男人
	women	//女人
}Gender_T;

class Home
{
public:
	Home();//默认构造函数
	Home(const string& nickname, int age, Gender_T gender);//昵称,年龄,性别
	~Home();//析构函数

	void Marriage(Home &spouse);//结婚,聚合关系
	void divorce();//离婚
	void MakeFriends(Home &friendss);//交友
	void Break_Off_Friendship(Home& friendss);//断交
	string getnickname()const;//询问昵称
	int getage()const;//询问年龄
	Gender_T getgender()const;//询问性别
	string Brief_introduction()const;//自我简介
	Home* getspouse()const;//询问配偶是谁
	vector<Home*> getfriends()const;//询问朋友是谁

private:
	string nickname;//昵称
	int age;//年龄
	Gender_T gender;//性别
	Home* spouse=NULL;//配偶,定义一个对象指针
	vector<Home*>friends;//朋友,由于vector属于备份关系,所以用指针
};

