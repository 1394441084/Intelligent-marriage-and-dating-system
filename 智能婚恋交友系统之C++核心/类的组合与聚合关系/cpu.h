#pragma once
//�����ۺ�
#include <string>
using namespace std;

class cpu
{
public:
	cpu(const char * Brand="intel", const char* Model = "i5");//Ĭ�Ϲ��캯��
	~cpu();//�������캯��

private:
	string Brand;//Ʒ��
	string Model;//�ͺ�
};

