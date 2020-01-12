//让用户输入姓名,年龄,并保存到文件中
//直到用户输入ctrl+z结束
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>//文件流,输出输入,fstream(输出输入文件全能定义流)
#include <sstream>

using namespace std;

typedef long long int_64;

/*
模式标志		描述
ios::in			读方式打开文件
ios:out			写方式打开文件
ios::trunc		如果此文件已经存在, 就会打开文件之前把文件长度截断为0
ios::app		尾部最加方式(在尾部写入)
ios::ate		文件打开后, 定位到文件尾
ios::binary		二进制方式(默认是文本方式)
以上打开方式，可以使用位操作 |  组合起来
输出输入流对象.open("文件名",上面的方法 | 上面的方法 | (可以多个))方法:打开文件的方法,跟以上内容结合
输出输入流对象.is_open()方法:检测打开文件是否成功,成功返回真
输出输入流对象.eof()方法:文件尾部有个特殊的文件结束符,检测到返回真
输出输入流对象.close()方法:关闭文件,避免文件没有保存;

s.fail( )
流s的failbit或者badbit被置位时, 返回true
failbit: 出现非致命错误，可挽回, 一般是软件错误
badbit置位, 出现致命错误, 一般是硬件错误或系统底层错误, 不可挽回

s.bad( )
流s的badbit置位时, 返回true

s.good( )
流s处于有效状态时, 返回true

s.clear( )
流s的所有状态都被复位
*/
void 写文本文件();
void 读文本文件();
void 写二进制文件();
void 读二进制文件();
void 按指定格式写文件();
void 按指定格式读文件();

void 文件流的定位();/*seekp随机读写(文件流的定位)
seekg( off_type offset,      //偏移量
ios::seekdir origin );  //起始位置
作用：设置输入流的位置
参数1： 偏移量
参数2： 相对位置
  beg  	相对于开始位置
  cur  	相对于当前位置
  end	相对于结束位置
  //文件中都有一个指针指向一个位置,空白字符也指
*/

long long 获取指定文件长度(const char*);//tellg 返回该输入流的当前位置(距离文件的起始位置的偏移量)

/*seekp() 设置该输出流的位置例:
先向新文件写入：“123456789”
然后再在第4个字符位置写入“ABC”*/
void 设置输出流位置();

int main(void) {
	//写文本文件();
	//读文本文件();
	//写二进制文件();
	//读二进制文件();
	//按指定格式写文件();
	//按指定格式读文件();
	//文件流的定位();
	//cout << 获取指定文件长度("读写文本文件.cpp") << endl;
	设置输出流位置();
	system("pause");
	return 0;
}

void 写文本文件() {
	string name;
	int age;
	ofstream outflie;//定义了一个文件输出流对象

	//使用输出流对象打开一个文件,文件不存在它会创建一个,已经存在的(默认打开方式)会打开文件并清空内容.
	outflie.open("写入测试.txt");//有多种打开方式,不写为默认

	//是要判断有没打开成功,虽然一般都不会出错,后面再写
	if (!outflie.is_open()) {cout << "文件打开失败\n";return;}

	while (1) {
		cout << "请输入姓名:[ctrl+z退出]\n";
		cin >> name;
		if (cin.eof()) { break; }//判断是否输入了退出

		//把输入的姓名写入文件
		outflie << name << "\t";

		cout << "请输入年龄:\n";
		cin >> age;
		outflie << age << "\n";
	}

	outflie.close();//关闭打开的文件流(避免没有保存好输入的数据)
}
void 读文本文件() {
	string name;
	int age;
	ifstream inFlie;
	inFlie.open("写入测试.txt");//以读的方式打开文件
	if (!inFlie.is_open()) { cout << "文件打开失败\n"; exit(0); }
	while (1) {
		//读姓名
		inFlie >> name;//遇到字表,空格,回车符会自动跳过去
		if (inFlie.eof()) { break; }
		cout << name << "\t";

		//读年龄
		inFlie >> age;
		cout << age << "\n";

	}
	inFlie.close();
}
void 写二进制文件() {
	string name;
	int age;
	ofstream dat;
	dat.open("写二进制文件测试.dat", ios::out | ios::trunc | ios::binary);
	if (dat.is_open()) { cout << "文件打开失败"; return; }
	while (1) {
		cout << "请输入姓名:[ctrl+z退出]\n";
		cin >> name;
		if (cin.eof()) { break; }
		dat << name << "\t";

		cout << "请输入年龄:\n";
		cin >> age;
		//dat << age << "\n";//int会转为string,结果并不是整数,而是字符串
		dat.write((char*)&age, sizeof(age));//转为字符,这样才是真二进制数
	}
	dat.close();//关闭文件,避免没有保存好
}
void 读二进制文件() {
	string name;
	int age;
	ifstream dat;
	dat.open("写二进制文件测试.dat", ios::in | ios::binary);
	if (!dat.is_open()) {cout << "打开文件失败"; return;}
	while (1) {
		dat >> name;//读前面字符串没问题
		if (dat.eof()) { break; }
		cout << name << "\t";

		char tmd;//读二进制遇到空格,字表,回车符不会跳
		dat.read(&tmd, sizeof(tmd));//将字表符放进tmd

		//dat >> age;//age转二进制了,这样读死循环
		dat.read((char*)&age, sizeof(age));//这里进行转换,结果没对,应该也读入了\t(字表符)
		cout << age << endl;
	}
	dat.close();
}
void 按指定格式写文件() {
	string name; int age;
	ofstream txt;
	txt.open("按指定格式写文件.txt");
	if (txt.is_open()) { cout << "文件打开失败"; return; }
	while (1) {
		cout << "请输入姓名:[ctrl+z退出]\n";
		cin >> name;
		if (cin.eof()) { break; }
		cout << "请输入年龄:\n";
		cin >> age;

		stringstream str;
		str << "姓名:" << name << "\t\t年龄:" << age << endl;

		//把指定格式的数据写入文件
		txt << str.str();
	}
	txt.close();
}
void 按指定格式读文件() {
	ifstream txt;
	string line;
	char name[32];
	int age;
	txt.open("按指定格式写文件.txt");
	if (txt.is_open()) { cout << "文件打开失败"; return; }
	while (1) {
		getline(txt, line);//从txt读取一行到line
		if (txt.eof()) { break; }
		//读取到的一行string转换char[],要完全对应文本的(如半角字符对半角,不然乱码,空格为跳过空白字符),name,age;
		sscanf_s(line.c_str(),"姓名:%s 年龄:%d", name, sizeof(name), &age);
		cout << "姓名:" << name << "\t\t年龄:" << age << endl;
	}
	txt.close();
}
void 文件流的定位() {
	ifstream txt;
	string len;
	txt.open("读写文本文件.cpp");
	if (!txt.is_open()) { exit(7); }
	txt.seekg(-50, txt.end);//从文件尾部算起,-50个数
	while (!txt.eof()) {
		getline(txt, len);//回车符不包含,包含空格
		cout << len << endl;
	}
	txt.close();
}
long long 获取指定文件长度(const char* txtname) {
	ifstream txt;
	txt.open(txtname);
	if (!txt.is_open()) { exit(8); }
	txt.seekg(0, txt.end);//定位到文件尾部
	int_64 len = txt.tellg();
	txt.close();
	return len;
}//123456789a123456789b123456789c123456789d123456789e
void 设置输出流位置() {
	{ofstream txt; 
	txt.open("设置输出流.txt");
	if (!txt.is_open()) { cout << "设置输出流文件没有打开成功\n"; exit(9); }
	txt << "1234567890\n12  5	8";
	txt.seekp(4, txt.beg);
	txt << "ABC";
	txt.close(); }

	ifstream txt; string len;
	txt.open("设置输出流.txt"); if (!txt.is_open()) { cout << "设置输出流文件没有打开成功\n"; exit(9); }
	
	while (1) {
		txt >> len; 
		cout << len << endl;
		if (txt.eof()) { break; }
	}
	txt.close();
}