//#define _CRTDEG_MAP_ALLOC //��⶯̬�ڴ�й©

#include <iostream>
#include <stdlib.h>//��⶯̬�ڴ�й©
#include "Cow.h"
#include "Goat.h"
#include "pork.h"

/*
//��⶯̬�ڴ�й©
#include <crtdbg.h>
//���new
#ifdef _DEBUG  
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK,__FILE__,__LINE__)
#define new DBG_NEW
#endif
#endif
*/

using namespace std;

ostream& operator<<(ostream& os, const Cow& cow0)
{
	cow0.name ? os<< "ţ������:" << cow0.name << "\tţ������:"
		<< cow0.weight :
		os << "ţ������:" << cow0.weight;
	return os;
}

pork operator-(const Cow& cow1, const Cow& cow2) {//ʹ����Ԫ����ʵ�����������
	int tmp = (cow1.weight - cow2.weight)*2;
	return pork(tmp);
}

pork operator-(const Goat& cow1, const Cow& cow2) {//ʹ����Ԫ����ʵ�����������
	int tmp = cow1.getweight()*3 - cow2.weight*2;
	return pork(tmp);
}

pork operator-(const Cow& cow2, const Goat& cow1) {//ʹ����Ԫ����ʵ�����������
	int tmp = cow2.weight * 2- cow1.getweight() * 3;
	return pork(tmp);
}

//ʹ����Ԫ��������<<�����
ostream& operator<<(ostream& os, const pork& pork) {
	pork.name ? os << "��" << pork.ID << "ͷ�������:" << pork.name << "\t�������:" 
		<< pork.weight << "\t��ļ۸�:" << pork.price :
		os << "�������:" << pork.weight;
	return os;
}
//ʹ����Ԫ��������>>�����
istream& operator>>(istream& is, pork& pork) {
	//��Ϊpork.name��char *name;������������¿ռ䲻������ʵ������ڴ�
	//ʹ��string�����ݵĴ洢������ַ���,�ں������·���ռ��pork.name
	string name1;
	char* p = NULL;
	p = pork.name;//ָ��ͬһ���
	delete[] p;//�ڴ�й©������,��pork.name������NULL,�����ָ��һ���ڴ�,���ֶ�ָ��Ļ�,�ᷢ�����µĺ��
	//cout << pork.name << endl;//��ӡ������������,���������:����=�����,����Ҳ������ѽ
	
	cout << "��?ͷ��\t����:?\t����:?\t����:?\n";
	is >> pork.ID >> name1 >> pork.weight >> pork.price;//����cin���治�˿ո�,���Բ���Ҫ���name1�Ƿ�Ϊ��
	pork.name = (char*)malloc((name1.length() + 1) * sizeof(char));//����ռ��С
	//��name1������pork.name,����string�Ǵ�0��ʼ����,���Լ�1;
	strcpy_s(pork.name, name1.length() + 1, name1.c_str());
	return is;
}

int main(void) {
	//ʹ�ó�Ա����ʵ�����������ʾ��:
	while (0) { 
		Cow c1(100);
		Cow c2(200);
		//pork p =c1 + c2;//���õ���c1.operator+(c2);
		pork p = c1.operator+(c2);
		cout << p.describe() << endl;

		Goat g(100);
		//p = c1+g;
		p = c1.operator+(g);
		cout << p.describe() << endl;
		break;
	}

	//ʹ����Ԫ����ʵ�����������ʾ��:
	while (0) { 
		Cow c1(100);
		Cow c2(200);

		pork p = c1 - c2;//-200
		cout << p.describe() << endl;

		Goat g(100);
		p = g - c1;//100
		cout << p.describe() << endl;

		p = c1 - g;//-100
		cout << p.describe() << endl;
		break;
	}

	//��Ԫ�����ͳ�Ա��������ʾ��:
	while (0) { 
		Cow c(100);
		Cow c1 = c + 200;//300
		Cow c2 = 300 + c;//��������Ԫ��������

		cout << c1.describe() << endl;
		cout << c2.describe() << endl;
		break;
	}

	// =���������
	while (0) {
		pork p("С��", 50, 30); pork p1(80), p2(90);
		cout << p.describe() << endl;
		cout << p1.describe() << endl;
		cout << p2.describe() << endl;
		p1 = p2 = p;
		cout << "\n-------------��ֵ��-------------\n\n";
		cout << p.describe() << endl;
		cout << p1.describe() << endl;
		cout << p2.describe() << endl;
		break;
	}

	//��ϵ���������
	while (0) { 
		Goat y1(80), y2(100);
		if (y1 > y2) {
			cout << "y1��\n";
		}
		else if (y1 == y2) {
			cout << "һ����\n";
		}
		else {
			cout << "y2��\n";
		}
		break;
	}
	
	//�±���������� []
	while (1) {

		pork p("������", 1000, 100);
		/*
		if(p["����"]){
		cout << p["����"] << endl;
		}
		else {
			cout << "kongkong\n";
		}*/
	
		//�Ż���,���ɶ�,���ܱ������

		//��ʹ��operator int()const;//������ش����"pork::operator []": 2�����������Ƶ�ת��
		//cout << p[WEIGHT_KEY] << "\t" << p["45"] << "\t" << p[PRICE_KEY] << endl;//ʹ���ַ��������ж�д���Ǻܼ���

		cout << "-----------���غ�----------\n";
		cout << p[weight_key] << "\t" << p[id_key] << "\t" << p[price_key] << endl;
		break;
	}


	//����������������
	while (0) {
		pork p("������", 1000, 100);
		pork p1(300);
		/*ʹ�ó�Ա��������<<�����
		p1<<(p << cout << endl)<<endl;//p.operator<<(cout);���ַ�ʽ�ö���ѽ,������
		//cout << p;
		//cout.operator<<(p);//.operator<<()������p��,cout�޷�����
		*/

		//ʹ����Ԫ��������<<�����
		cout << p << endl << p1 << endl;

		cin >> p;

		cout << p << endl;

		break;
	}

	/*
	string n = "\0";
	cout << n.length() << endl;
	cout << size(n) << endl;
	cout << strlen(n.c_str()) << endl;
	*/

	//��ͨ����ת������
	while (0) {
		pork pork1 = 1000;//���� ���캯��pork(int);
		pork pork2 = "huahua";//���� ���캯��pork(char *);

		cout << pork1 << endl;
		cout << pork2 << endl;
		break;
	}

	//������ת��ͨ����
	while (0) { 
		Cow c(250);
		Cow a("����");
		int weight = c;//250
		char* name = a;//"����"

		cout << a.describe() << endl;
		cout << weight << endl;
		cout << name << endl;
		break; }

	//������ת������
	while (0) { 
		pork p("", 2000, 50);
		Cow c = p;
		char* n = p;
		int i = p;
		cout << p << "\n";
		cout << c << "\n";
		cout << n << endl;
		cout << i << endl;
		break; }

	//_CrtDumpMemoryLeaks();//��⶯̬�ڴ�й©
	system("pause");
	return 0;
}
Cow operator+(int n, const Cow& cow) {
	int tmp = cow.weight + n;
	return Cow(tmp);
}