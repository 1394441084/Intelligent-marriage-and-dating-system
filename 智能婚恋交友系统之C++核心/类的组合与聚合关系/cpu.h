#pragma once
//组合与聚合
#include <string>
using namespace std;

class cpu
{
public:
	cpu(const char * Brand="intel", const char* Model = "i5");//默认构造函数
	~cpu();//析构构造函数

private:
	string Brand;//品牌
	string Model;//型号
};

