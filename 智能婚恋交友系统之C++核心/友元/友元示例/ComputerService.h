#pragma once

class Computer;

class ComputerService//计算机服务类
{
public:
	void upgrade1(Computer* computer);//类的成员函数作为友元函数
	void clean(Computer* computer);//友元类,清理
	void kill(Computer* computer);//友元类,杀毒

};

