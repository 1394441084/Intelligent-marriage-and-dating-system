#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

//��ʯ�ȼ�(ö��) //����ʹ�õ���C++11���±�׼,���Բ���ֱ�Ӻ�int�ҹ�
enum class LingShiGrade {
	PRIMARY,     //����
	MIDDLE_RANK, //�н�
	EXPERT,      //�߽�
	TOTAL_GRADE  //�ܽ׼�,�ж��ٵȼ�(�����ڱ߽紦��)
};

//��ʯ��
class LingShi
{
public:
	LingShi(int number=0, LingShiGrade grade= LingShiGrade::PRIMARY);//ע��:�ڴ�ʹ��ö�������޶���

	string str()const;//ת���ַ���,���������ܵõ��ַ���

	friend ostream& operator<<(ostream& os,const LingShi& lingshi);//����<<

	LingShi operator+(const LingShi& other)const;//����+
	LingShi operator-(const LingShi& other)const;//����+
	bool operator>=(const LingShi& other)const;//����>=

	int getNumber()const;//��ȡ���ٿ���ʯ
private:
	int number;//����:  ��
	LingShiGrade grade;//��ʯ�ĵȼ�:���� �н� �߽�
};

