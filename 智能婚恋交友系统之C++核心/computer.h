#pragma once
#include "cpu.h" //class cpu;cpu *Cpu;//����д��(���)
//�����ۺ�
//�ۺ�,�����𴴽�������

class Speaker;//����������


class computer
{
public:
	computer(const char * cpuBrand,const char * cpuModel,int HardDisk,int Memory);//Ĭ�Ϲ��캯��
	~computer();//��������
	void addSpeaker(Speaker* speaker);//������,ͨ���˽ӿڷ����ۺϹ�ϵ

private:
	cpu Cpu;//������cpu�����(computer��cpu֮�����"���"��ϵ)
	//cpu* Cpu;
	int HardDisk;//Ӳ��,��λ:G
	int Memory;//�ڴ�,��λ:G
	Speaker* speaker;//����������speakerָ��ָ�����������;�ۺ�
};

