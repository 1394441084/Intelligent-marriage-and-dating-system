#include "Son.h"

//�򵥵�����ʵ��"����" "�̳�",(�����и���Ҳ�л���)������Ϊ����
//����        ����
//�̳з�ʽ��:����,˽��,���������ַ�ʽ
/*
���࣬һ�������Լ������ݳ�Ա/��Ա������
���ߣ����¶���Ӹ���̳еķ���!!!������������Լ�����ķ���,��������ø������������
*/
/*
��Ŀ-����-C/C++-��������   ���: /d1 reportSingleClassLayoutFather   /d1 reportSingleClassLayoutSon   
/d1 reportSingleClassLayout ����  Father  ����   ���ǲ鿴���ڴ�ֲ����vs2019ûɶ�ô�
*/

/*��ķ���Ȩ���ܽ�:
public:
�ⲿ����ֱ�ӷ���,ͨ�����������������Ա��:
Father wjl("������", 66);
cout<<wjl.getname()<<endl;

private:
�ⲿ�����Է���
�Լ��ڲ��ĳ�Ա�������Է���
Father wjl("������", 66);
cout<<name<<endl;//����
����ĳ�Ա����������ֱ�ӷ���
ֻ���Լ������г�Ա�����ڲ���ֱ�ӷ���

protected:
������public
������private:
��private������,��ͬ��������ĳ�Ա�����п���ֱ�ӷ���
*/

class M {
public:
	M() {
		cout << __FUNCTION__ << endl;
	}

	~M() {
		cout << __FUNCTION__ << endl;
	}
};

class N {
public:
	N() {
		cout << __FUNCTION__ << endl;
	}

	~N() {
		cout << __FUNCTION__ << endl;
	}
};

class A {
public:
	A() {
		cout << __FUNCTION__ << endl;
	}

	~A() {
		cout << __FUNCTION__ << endl << endl;
	}
};

class B : public A {
public:
	B() {
		cout << __FUNCTION__ << endl << endl;
	}

	~B() {
		cout << __FUNCTION__ << endl;
	}
private:
	M m1;
	M m2;
	static N ms;
};

N B::ms;  //��̬��Ա

int main(void) {
	while(0){//���м̳з�ʽ:Son�̳�Father�ĳ�Ա����,public��protected����ֱ�ӷ���,�������̳з�
	Father wjl("������", 66);
	cout << "------------\n";
	Son wsc("��˼��", 32,"Ӣ������");

	cout << wjl.description() << endl;
	cout << wsc.description() << endl;
	//cout << wsc.getname() << "  ��Ϸ:" << wsc.getgame() << endl;

	cout << sizeof(wjl) << endl;
	//��Ա������ռ�ռ�,ֻ�������ݳ�Ա���ڴ�
	cout << sizeof(wsc) << endl;

	break;}

	while (0) {//˽�м̳з�ʽ:Son�̳�Father�ĳ�Ա����(��Father��Աȫ��Ϊprivate),˽�����̳з�(�̳и���,�����㲻�ܸ��߱���)
		Son wsc("��˼��", 32, "Ӣ������");
		cout << wsc.getage();//˽�����޷����ʸ���̳�������public:��Ա
		break; }

	while (1) { //����͸���Ĺ��캯���ĵ���˳��
		/*
		�������������ʱ, ���캯���ĵ���˳��
��̬���ݳ�Ա�Ĺ��캯�� ->  ����Ĺ��캯�� ->  �Ǿ�̬�����ݳ�Ա�Ĺ��캯�� -> �Լ��Ĺ��캯��

ע��: 
���۴�����������, ����ľ�̬��Աֻ����һ��, ���Ծ�̬��Ա�Ĺ��캯��ֻ����1��!!!
		*/
		/*
		��������������ĵ���˳�򣬺�����Ĺ��캯���ĵ���˳���෴������
��ס���෴���ɡ�
		*/
		B b;
		cout << "\n\n**************************\n\n";
		B c;


		break; }


	system("pause");
	return 0;
}