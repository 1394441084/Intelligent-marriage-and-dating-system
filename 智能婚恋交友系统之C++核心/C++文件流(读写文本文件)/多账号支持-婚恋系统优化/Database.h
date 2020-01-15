#pragma once
#include <fstream>
#include "Boy.h"

#define BOYS_FILE "boys.txt"
#define GIRLS_FILE "girls.txt"

class Database
{
public:
	Database();
	//~Database();

	void init(); //��ʼ���� ���ļ��ж�ȡ������Ϣ�� ����ʼ���û�����
	void autoPair(); //�Զ����
	void print();  // ��ӡ�����ݿ��е������û���Ϣ

	void addOne(Boy& boy);//���ӵ���Boy�û���Ϣ
	void addOne(Girl& girl);//���ӵ���Girl�û���Ϣ
private:
	vector<Boy> boys;  //���еĵ�������Ϣ,����һ��boys[]
	vector<Girl> girls; //���е���Ů��Ϣ

	void initBoysFromFile();//���ļ���ʼ��boys��Ϣ,������,ֻ���ڵĺ���
	void initGirlsFromFile();//���ļ���ʼ��girls��Ϣ

//protected://�����ø�Boy���Girl��̳�
	void saveBoys();//����Boys��Ϣ���ļ�
	void saveGirls();//����Girls��Ϣ���ļ�
};

/*
�ļ����ݿ���Database�����
���� Ҫʹ���ļ��������û���Ϣ
������ ���һ���࣬ ��ʵ����Ϣ�ı��湦��
Database  ���ݿ�
���ܣ�
	init() //��ʼ���� ���ļ��ж�ȡ������Ϣ�� ����ʼ���û�����
	autoPair() //�Զ����
	print()  // ��ӡ�����ݿ��е������û���Ϣ
���ݣ�
	vector<Boy> boys;  //���еĵ�������Ϣ
	vector<Girl> girls; //���е���Ů��Ϣ
*/