//���û���������,����,�����浽�ļ���
//ֱ���û�����ctrl+z����
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>//�ļ���,�������,fstream(��������ļ�ȫ�ܶ�����)
#include <sstream>

using namespace std;

typedef long long int_64;

/*
ģʽ��־		����
ios::in			����ʽ���ļ�
ios:out			д��ʽ���ļ�
ios::trunc		������ļ��Ѿ�����, �ͻ���ļ�֮ǰ���ļ����Ƚض�Ϊ0
ios::app		β����ӷ�ʽ(��β��д��)
ios::ate		�ļ��򿪺�, ��λ���ļ�β
ios::binary		�����Ʒ�ʽ(Ĭ�����ı���ʽ)
���ϴ򿪷�ʽ������ʹ��λ���� |  �������
�������������.open("�ļ���",����ķ��� | ����ķ��� | (���Զ��))����:���ļ��ķ���,���������ݽ��
�������������.is_open()����:�����ļ��Ƿ�ɹ�,�ɹ�������
�������������.eof()����:�ļ�β���и�������ļ�������,��⵽������
�������������.close()����:�ر��ļ�,�����ļ�û�б���;

s.fail( )
��s��failbit����badbit����λʱ, ����true
failbit: ���ַ��������󣬿����, һ�����������
badbit��λ, ������������, һ����Ӳ�������ϵͳ�ײ����, �������

s.bad( )
��s��badbit��λʱ, ����true

s.good( )
��s������Ч״̬ʱ, ����true

s.clear( )
��s������״̬������λ
*/
void д�ı��ļ�();
void ���ı��ļ�();
void д�������ļ�();
void ���������ļ�();
void ��ָ����ʽд�ļ�();
void ��ָ����ʽ���ļ�();

void �ļ����Ķ�λ();/*seekp�����д(�ļ����Ķ�λ)
seekg( off_type offset,      //ƫ����
ios::seekdir origin );  //��ʼλ��
���ã�������������λ��
����1�� ƫ����
����2�� ���λ��
  beg  	����ڿ�ʼλ��
  cur  	����ڵ�ǰλ��
  end	����ڽ���λ��
  //�ļ��ж���һ��ָ��ָ��һ��λ��,�հ��ַ�Ҳָ
*/

long long ��ȡָ���ļ�����(const char*);//tellg ���ظ��������ĵ�ǰλ��(�����ļ�����ʼλ�õ�ƫ����)

/*seekp() ���ø��������λ����:
�������ļ�д�룺��123456789��
Ȼ�����ڵ�4���ַ�λ��д�롰ABC��*/
void ���������λ��();

int main(void) {
	//д�ı��ļ�();
	//���ı��ļ�();
	//д�������ļ�();
	//���������ļ�();
	//��ָ����ʽд�ļ�();
	//��ָ����ʽ���ļ�();
	//�ļ����Ķ�λ();
	//cout << ��ȡָ���ļ�����("��д�ı��ļ�.cpp") << endl;
	���������λ��();
	system("pause");
	return 0;
}

void д�ı��ļ�() {
	string name;
	int age;
	ofstream outflie;//������һ���ļ����������

	//ʹ������������һ���ļ�,�ļ����������ᴴ��һ��,�Ѿ����ڵ�(Ĭ�ϴ򿪷�ʽ)����ļ����������.
	outflie.open("д�����.txt");//�ж��ִ򿪷�ʽ,��дΪĬ��

	//��Ҫ�ж���û�򿪳ɹ�,��Ȼһ�㶼�������,������д
	if (!outflie.is_open()) {cout << "�ļ���ʧ��\n";return;}

	while (1) {
		cout << "����������:[ctrl+z�˳�]\n";
		cin >> name;
		if (cin.eof()) { break; }//�ж��Ƿ��������˳�

		//�����������д���ļ�
		outflie << name << "\t";

		cout << "����������:\n";
		cin >> age;
		outflie << age << "\n";
	}

	outflie.close();//�رմ򿪵��ļ���(����û�б�������������)
}
void ���ı��ļ�() {
	string name;
	int age;
	ifstream inFlie;
	inFlie.open("д�����.txt");//�Զ��ķ�ʽ���ļ�
	if (!inFlie.is_open()) { cout << "�ļ���ʧ��\n"; exit(0); }
	while (1) {
		//������
		inFlie >> name;//�����ֱ�,�ո�,�س������Զ�����ȥ
		if (inFlie.eof()) { break; }
		cout << name << "\t";

		//������
		inFlie >> age;
		cout << age << "\n";

	}
	inFlie.close();
}
void д�������ļ�() {
	string name;
	int age;
	ofstream dat;
	dat.open("д�������ļ�����.dat", ios::out | ios::trunc | ios::binary);
	if (dat.is_open()) { cout << "�ļ���ʧ��"; return; }
	while (1) {
		cout << "����������:[ctrl+z�˳�]\n";
		cin >> name;
		if (cin.eof()) { break; }
		dat << name << "\t";

		cout << "����������:\n";
		cin >> age;
		//dat << age << "\n";//int��תΪstring,�������������,�����ַ���
		dat.write((char*)&age, sizeof(age));//תΪ�ַ�,�����������������
	}
	dat.close();//�ر��ļ�,����û�б����
}
void ���������ļ�() {
	string name;
	int age;
	ifstream dat;
	dat.open("д�������ļ�����.dat", ios::in | ios::binary);
	if (!dat.is_open()) {cout << "���ļ�ʧ��"; return;}
	while (1) {
		dat >> name;//��ǰ���ַ���û����
		if (dat.eof()) { break; }
		cout << name << "\t";

		char tmd;//�������������ո�,�ֱ�,�س���������
		dat.read(&tmd, sizeof(tmd));//���ֱ���Ž�tmd

		//dat >> age;//ageת��������,��������ѭ��
		dat.read((char*)&age, sizeof(age));//�������ת��,���û��,Ӧ��Ҳ������\t(�ֱ��)
		cout << age << endl;
	}
	dat.close();
}
void ��ָ����ʽд�ļ�() {
	string name; int age;
	ofstream txt;
	txt.open("��ָ����ʽд�ļ�.txt");
	if (txt.is_open()) { cout << "�ļ���ʧ��"; return; }
	while (1) {
		cout << "����������:[ctrl+z�˳�]\n";
		cin >> name;
		if (cin.eof()) { break; }
		cout << "����������:\n";
		cin >> age;

		stringstream str;
		str << "����:" << name << "\t\t����:" << age << endl;

		//��ָ����ʽ������д���ļ�
		txt << str.str();
	}
	txt.close();
}
void ��ָ����ʽ���ļ�() {
	ifstream txt;
	string line;
	char name[32];
	int age;
	txt.open("��ָ����ʽд�ļ�.txt");
	if (txt.is_open()) { cout << "�ļ���ʧ��"; return; }
	while (1) {
		getline(txt, line);//��txt��ȡһ�е�line
		if (txt.eof()) { break; }
		//��ȡ����һ��stringת��char[],Ҫ��ȫ��Ӧ�ı���(�����ַ��԰��,��Ȼ����,�ո�Ϊ�����հ��ַ�),name,age;
		sscanf_s(line.c_str(),"����:%s ����:%d", name, sizeof(name), &age);
		cout << "����:" << name << "\t\t����:" << age << endl;
	}
	txt.close();
}
void �ļ����Ķ�λ() {
	ifstream txt;
	string len;
	txt.open("��д�ı��ļ�.cpp");
	if (!txt.is_open()) { exit(7); }
	txt.seekg(-50, txt.end);//���ļ�β������,-50����
	while (!txt.eof()) {
		getline(txt, len);//�س���������,�����ո�
		cout << len << endl;
	}
	txt.close();
}
long long ��ȡָ���ļ�����(const char* txtname) {
	ifstream txt;
	txt.open(txtname);
	if (!txt.is_open()) { exit(8); }
	txt.seekg(0, txt.end);//��λ���ļ�β��
	int_64 len = txt.tellg();
	txt.close();
	return len;
}//123456789a123456789b123456789c123456789d123456789e
void ���������λ��() {
	{ofstream txt; 
	txt.open("���������.txt");
	if (!txt.is_open()) { cout << "����������ļ�û�д򿪳ɹ�\n"; exit(9); }
	txt << "1234567890\n12  5	8";
	txt.seekp(4, txt.beg);
	txt << "ABC";
	txt.close(); }

	ifstream txt; string len;
	txt.open("���������.txt"); if (!txt.is_open()) { cout << "����������ļ�û�д򿪳ɹ�\n"; exit(9); }
	
	while (1) {
		txt >> len; 
		cout << len << endl;
		if (txt.eof()) { break; }
	}
	txt.close();
}