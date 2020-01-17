#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

void 写入任意10个整数并保存到txt(const char* txt) {
	/*
输入任意多个整数, 把这些数据保存到文件data.txt中.
如果在输入的过程中, 输入错误, 则提示用户重新输入.
指导用户输入结束(按ctrl + z)
[每行最多保存10个整数]

cin.ignore(count, c);
从输入流中提取并丢弃字符，直到遇到下列三种情况
1.提取的字符达到了参数count指定的数量
2.在输入序列中遇到文件结束（EOF）
3.输入序列中的下一个字符为参数c指定的字符（这个字符会被提取并丢弃）

count常常取：
std::numeric_limits<std::streamsize>::max()  相当于IO流的最大字符个数

常见用法：（把标准输入缓冲区cin的所有数据都清空）
cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
*/
		ofstream int10;//写入
		int10.open(txt);//默认方式打开文件
		if (!int10.is_open()) { exit(0); }
		int inttxt = 0;
		int n = 0;
		while (1) {
			cout << "请输入一个整数:";
			cin >> inttxt;
			if (cin.eof()) { break; }//遇到文件符跳出循环

			while (cin.fail()) {//输入错误,需重新输入,如输入A,清空缓冲区
				cin.clear();//清除错误标志
				//cin.sync();//清空缓存区,在vs中无效,下面的模板代替
				//表示最多扔多少个;''表示遇到什么时停止(ASCII码)
				//numeric_limits<streamsize>::max();相当于IO流的最大字符个数,即当前标准缓冲区的所有数据
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//遇到回车符停止,并包含
				cout << "输入错误,请重新输入:";
				cin >> inttxt;
			}

			int10 << inttxt << "\t";//写入数据到文件
			if (++n % 10 == 0) { int10 << endl; }//输够十个整数了,那就换行吧
		}
		int10.close();//用户写完了,关闭文件
}

void 读取文件各个整数并打印出最大值和最小值和平均值(const char* txt) {
	ifstream inttxt;
	inttxt.open(txt);
	if (!inttxt.is_open()) { exit(1); }
	
	int da = 0; //最大值
	int xiao = 0;//最小值
	int he = 0;//求和
	int gs = 0;//读取个数
	int txtint = 0;//读取到的数
	
	inttxt >> txtint;//从文件读取数
	if (inttxt.eof()) { return; }
	da = txtint;
	xiao = txtint;
	he += txtint;
	gs++;

	while (1) {
		inttxt >> txtint;
		if (inttxt.eof()) { break; }
		gs++;
		he += txtint;
		if (da < txtint) { da = txtint; }else if (xiao > txtint) { xiao = txtint; }//判断读取的数是否最大,不是就判断是否最小
	}
	inttxt.close();
	cout << "最大值:" << da << "\t最小值:" << xiao << "\t平均值:" << float(he) / float(gs) << endl;
}

int main(void) {
	//写入任意10个整数并保存到txt("任意多个整数.txt");
	读取文件各个整数并打印出最大值和最小值和平均值("任意多个整数.txt");

	system("pause");
	return 0;
}
