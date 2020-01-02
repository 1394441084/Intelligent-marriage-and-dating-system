#include "cpu.h"
//组合与聚合
#include <iostream>

//默认构造函数
cpu::cpu(const char* Brand, const char* Model) {
	this->Brand = Brand;
	this->Model = Model;
	cout << ":Cpu(cpuBrand,cpuModel)" << endl;
}
//析构函数
cpu::~cpu() {
	cout << "cpu析构" << endl;
}