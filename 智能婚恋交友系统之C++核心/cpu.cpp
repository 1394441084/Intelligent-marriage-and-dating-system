#include "cpu.h"
//�����ۺ�
#include <iostream>

//Ĭ�Ϲ��캯��
cpu::cpu(const char* Brand, const char* Model) {
	this->Brand = Brand;
	this->Model = Model;
	cout << ":Cpu(cpuBrand,cpuModel)" << endl;
}
//��������
cpu::~cpu() {
	cout << "cpu����" << endl;
}