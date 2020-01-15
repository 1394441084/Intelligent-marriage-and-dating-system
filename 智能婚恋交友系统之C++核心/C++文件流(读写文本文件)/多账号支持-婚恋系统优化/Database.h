#pragma once
#include <fstream>
#include "Boy.h"

#define BOYS_FILE "boys.txt"
#define GIRLS_FILE "girls.txt"

class Database
{
public:
	Database();
	//~Database();

	void init(); //初始化， 从文件中读取数据信息， 来初始化用户数据
	void autoPair(); //自动配对
	void print();  // 打印该数据库中的所有用户信息

	void addOne(Boy& boy);//增加单个Boy用户信息
	void addOne(Girl& girl);//增加单个Girl用户信息
private:
	vector<Boy> boys;  //所有的单身男信息,创建一个boys[]
	vector<Girl> girls; //所有单生女信息

	void initBoysFromFile();//从文件初始化boys信息,不对外,只对内的函数
	void initGirlsFromFile();//从文件初始化girls信息

//protected://这样好给Boy类和Girl类继承
	void saveBoys();//保存Boys信息到文件
	void saveGirls();//保存Girls信息到文件
};

/*
文件数据库类Database的设计
需求： 要使用文件来保存用户信息
分析： 设计一个类， 来实现信息的保存功能
Database  数据库
功能：
	init() //初始化， 从文件中读取数据信息， 来初始化用户数据
	autoPair() //自动配对
	print()  // 打印该数据库中的所有用户信息
数据：
	vector<Boy> boys;  //所有的单身男信息
	vector<Girl> girls; //所有单生女信息
*/