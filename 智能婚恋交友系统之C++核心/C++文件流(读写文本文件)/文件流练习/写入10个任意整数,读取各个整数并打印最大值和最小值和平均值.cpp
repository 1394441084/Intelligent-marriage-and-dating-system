#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

void д������10�����������浽txt(const char* txt) {
	/*
��������������, ����Щ���ݱ��浽�ļ�data.txt��.
���������Ĺ�����, �������, ����ʾ�û���������.
ָ���û��������(��ctrl + z)
[ÿ����ౣ��10������]

cin.ignore(count, c);
������������ȡ�������ַ���ֱ�����������������
1.��ȡ���ַ��ﵽ�˲���countָ��������
2.�����������������ļ�������EOF��
3.���������е���һ���ַ�Ϊ����cָ�����ַ�������ַ��ᱻ��ȡ��������

count����ȡ��
std::numeric_limits<std::streamsize>::max()  �൱��IO��������ַ�����

�����÷������ѱ�׼���뻺����cin���������ݶ���գ�
cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
*/
		ofstream int10;//д��
		int10.open(txt);//Ĭ�Ϸ�ʽ���ļ�
		if (!int10.is_open()) { exit(0); }
		int inttxt = 0;
		int n = 0;
		while (1) {
			cout << "������һ������:";
			cin >> inttxt;
			if (cin.eof()) { break; }//�����ļ�������ѭ��

			while (cin.fail()) {//�������,����������,������A,��ջ�����
				cin.clear();//��������־
				//cin.sync();//��ջ�����,��vs����Ч,�����ģ�����
				//��ʾ����Ӷ��ٸ�;''��ʾ����ʲôʱֹͣ(ASCII��)
				//numeric_limits<streamsize>::max();�൱��IO��������ַ�����,����ǰ��׼����������������
				cin.ignore(std::numeric_limits<streamsize>::max(), '\n');//�����س���ֹͣ,������
				cout << "�������,����������:";
				cin >> inttxt;
			}

			int10 << inttxt << "\t";//д�����ݵ��ļ�
			if (++n % 10 == 0) { int10 << endl; }//�乻ʮ��������,�Ǿͻ��а�
		}
		int10.close();//�û�д����,�ر��ļ�
}

void ��ȡ�ļ�������������ӡ�����ֵ����Сֵ��ƽ��ֵ(const char* txt) {
	ifstream inttxt;
	inttxt.open(txt);
	if (!inttxt.is_open()) { exit(1); }
	
	int da = 0; //���ֵ
	int xiao = 0;//��Сֵ
	int he = 0;//���
	int gs = 0;//��ȡ����
	int txtint = 0;//��ȡ������
	
	inttxt >> txtint;//���ļ���ȡ��
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
		if (da < txtint) { da = txtint; }else if (xiao > txtint) { xiao = txtint; }//�ж϶�ȡ�����Ƿ����,���Ǿ��ж��Ƿ���С
	}
	inttxt.close();
	cout << "���ֵ:" << da << "\t��Сֵ:" << xiao << "\tƽ��ֵ:" << float(he) / float(gs) << endl;
}

int main(void) {
	//д������10�����������浽txt("����������.txt");
	��ȡ�ļ�������������ӡ�����ֵ����Сֵ��ƽ��ֵ("����������.txt");

	system("pause");
	return 0;
}
