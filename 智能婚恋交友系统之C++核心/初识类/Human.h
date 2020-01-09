#pragma once

#include <string>
#include <string.h>

using namespace std;

#define addrlin 64 

extern int HumanCount;//����,���㶨���˶��ٸ�����,ȫ�ֱ�������ȫ,˭�������޸�

//int Human::Humancount = 0;//����ľ�̬���ݳ�Ա���г�ʼ��,��̬���ݳ�Ա��ʼҪ��.cpp�ļ���


//����һ����"����"
class Human {
public:  //���е�,�����
	Human();//�ֶ�����Ĭ�Ϲ��캯��.û�з���ֵ,��void�����ܼ�
	Human(string name, int age);//�Զ���һ������Ĭ�Ϲ��캯��,������Ҫ�����������캯��
	Human(string name, int age, int salary, char* addr);//�Զ���һ������Ĭ�Ϲ��캯��,������Ҫ�����������캯��
	Human(int age, int salary);
	Human(string blodType);//����const���͵����ݶ����ʼ��������

	Human(const Human& other);//���忽�����̺���,��������,ֻ��һ����������,�޷�����

	//(operator=)(������)=���������
	Human& operator=(const Human& other);//��ֵ���캯��f6=f5ʱ�Զ�����

	~Human();//������������,���ܴ�����,ֻ��һ���汾

	void eat();//���巽��,"��Ա����",��
	void sleep();//˯��
	void play();//��
	void work();//����
	void test() const;//��ӡ������Ϣ
	void addr1(const char* addr);

	string getname() const;//����,�����const,������ʵ�ֲ����޸ĳ�Ա
	int getsalary() const;//н��
	int getage();//����

	//int getHumancount();//���ʾ�̬���ݳ�Ա�ķ���,��ͨ���ຯ��,��bug
	//����:��̬����,����ʹ��thisָ��,ֻ�ܷ���ȫ�����ݳ�Ա
	static int getHumancount();//��ľ�̬��Ա����,���ʾ�̬���ݳ�Ա�ķ���

private:  //˽�˵�
	string name = "����";//��������,��Ա����
	int age;//C++11����,����ֱ�����ڳ�ʼֵ
	int salary;

	char* addr;//��ַ,����C++11���Ի����Ǳ�����,���Ա���Ҫ������ָ���ʼ��ֵ,��Ȼ���м���Σ��,��ָ���

	static int Humancount;//����һ����̬���ݳ�Ա

	const char bloodtype = 'A';//���峣�����ݳ�ԱѪ��A,���ڳ�ʼ(C++11����)
	const string bloodType;//ͨ����ʼ���б��ʼ;
	/*
	ע�⣺
ֻҪ�ֶ��������κ�һ�����캯�����������Ͳ������ɡ��ϳɵ�Ĭ�Ϲ��캯����
һ������£���Ӧ�ö����Լ��Ĺ��캯������Ҫʹ�á��ϳɵ�Ĭ�Ϲ��캯����
���������ݳ�Աȫ��ʹ���ˡ����ڳ�ʼֵ��������ʹ�á��ϳɵ�Ĭ�Ϲ��캯������
	*/
};//������,�������ܶ��ֺ�

void showmsg(const Human& man);
const Human& getBetterman(const Human& man1, const Human& man2);