#pragma once
#include "cpu.h" //class cpu;cpu *Cpu;//两种写法(组合)
//组合与聚合
//聚合,不负责创建和销毁

class Speaker;//声明音箱类


class computer
{
public:
	computer(const char * cpuBrand,const char * cpuModel,int HardDisk,int Memory);//默认构造函数
	~computer();//析构函数
	void addSpeaker(Speaker* speaker);//加音箱,通过此接口发生聚合关系

private:
	cpu Cpu;//定义了cpu类对象(computer和cpu之间就是"组合"关系)
	//cpu* Cpu;
	int HardDisk;//硬盘,单位:G
	int Memory;//内存,单位:G
	Speaker* speaker;//定义音箱类speaker指针指向音箱类对象;聚合
};

