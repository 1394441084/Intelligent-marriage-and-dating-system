#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

using namespace std;

#define addrlin 64 

//����һ����"����"
class Human {
public:  //���е�,�����
	Human();//�ֶ�����Ĭ�Ϲ��캯��.û�з���ֵ,��void�����ܼ�
	Human(string name, int age);//�Զ���һ������Ĭ�Ϲ��캯��,������Ҫ�����������캯��
	Human(string name, int age, int salary, char* addr);//�Զ���һ������Ĭ�Ϲ��캯��,������Ҫ�����������캯��
	Human(int age, int salary);

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

private:  //˽�˵�
	string name = "����";//��������,��Ա����
	int age;//C++11����,����ֱ�����ڳ�ʼֵ
	int salary;
	
	char* addr;//��ַ,����C++11���Ի����Ǳ�����,���Ա���Ҫ������ָ���ʼ��ֵ,��Ȼ���м���Σ��,��ָ���

	/*
	ע�⣺
ֻҪ�ֶ��������κ�һ�����캯�����������Ͳ������ɡ��ϳɵ�Ĭ�Ϲ��캯����
һ������£���Ӧ�ö����Լ��Ĺ��캯������Ҫʹ�á��ϳɵ�Ĭ�Ϲ��캯����
���������ݳ�Աȫ��ʹ���ˡ����ڳ�ʼֵ��������ʹ�á��ϳɵ�Ĭ�Ϲ��캯������
	*/
};//������,�������ܶ��ֺ�

void Human::eat() {//ʵ��������ķ���(ʵ�ֳ�Ա����)
	cout << "eat��\n";
}
void Human::sleep() {
	cout << "sleep˯��\n";
}
void Human::play() {
	cout << "play��\n";
}
void Human::work() {
	cout << "work����\n";
}
string Human::getname() const {//����,�����const,������ʵ�ֲ����޸ĳ�Ա
	return name;
}
int Human::getage() {
	return age;
}
int Human::getsalary() const {
	return salary;
}
Human::Human() {//ʹ���Զ����Ĭ�Ϲ��캯������ʼ����������ֵ,����Ҫ�������������ֵ��ʼ��,��Ȼ��Σ��
	cout << "�����Զ���Ĭ�Ϲ��캯��:" << this << endl;
	name = "������.1";
	age = 23;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "�����Զ���Ĭ�Ϲ��캯��");
}
Human::Human(int age, int salary) {
	this->name = name;//this������ָ��,ָ�������
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "���ô��������캯��");
}
Human::Human(string name, int age) {//ʹ���Զ��������Ĭ�Ϲ��캯������ʼ����������ֵ
	//age=age;��Ϊ�����������������ı�.Ҫô����,Ҫô����
	this->name = name;//this������ָ��,ָ�������
	this->age = age;
	salary = 3000;
	addr = new char[addrlin];
	strcpy_s(addr, addrlin, "���ô��������캯��");
}
Human::Human(string name, int age, int salary, char* addr) {//ʹ���Զ��������Ĭ�Ϲ��캯������ʼ����������ֵ
	//age=age;��Ϊ�����������������ı�.Ҫô����,Ҫô����
	cout << "���ô˺�������\n";
	this->name = name;//this������ָ��,ָ�������
	this->age = age;//thisָ����ú����Ķ�����,�����ʻ����޸ĳ�Ա,��̬�������
	this->salary = salary;
	addr = new char[addrlin];
	strcpy_s(this->addr, addrlin, addr);
}


//Human hwx2 = hwx1;//const Human &other=hwx1
Human::Human(const Human& other) {//���忽�����̺���,��������,�����Ƕ���
	cout << "���ÿ������캯��\n";//ʹ�ñ�����Ĭ�Ͽ������캯����Σ��(ǳ����)
	name = other.name;//ʹ���Զ��忽������,������Ҫ���������ʼ��,��Ȼ���������Զ�Ĭ�Ϻϳɳ�ʼֵ,ָ���ֱ�ӹ�
	age = other.age;
	salary = other.salary;
	addr = other.addr;
}

void Human::test() const {
	cout << "����:" << name << endl;//�����෽��,�����ú���
	cout << "����:" << age << endl;
	cout << "н��:" << salary << endl;
	cout << "��ַ:" << addr << endl;
}

void Human::addr1(const char* addr) {//�޸ĵ�ַ
	if (!addr)return;
	strcpy_s(this->addr, addrlin, addr);
}

//���ú��� showmsg(h1)
//�ڽ��в�������ʱ,�Զ�ִ��:Human &man =h1;
void showmsg(const Human& man) {//���ݵĲ����Ƕ���,�Զ������˿������̺���
	//���ݵĲ��������õĻ�,�Ͳ����ÿ������̺���,�ô������˿���,�����ᱻ�޸�,���const
	cout << man.getname() << "�Ļ�����Ϣ:\n";
	man.test();
}

/*
Human getBetterman(Human &man1, Human &man2) {//�����������õĻ�,����ÿ������캯��
	if (man1.getsalary() > man2.getsalary()) {
		return man1;
	}
	else {
		return man2;
	}
}
*/

const Human& getBetterman(const Human& man1, const Human& man2) {
	if (man1.getsalary() > man2.getsalary()) {
		cout << "man1\n";
		return man1;
	}
	else {
		cout << "man2\n";
		return man2;
	}
}

Human& Human::operator=(const Human& other) {//��ֵ���캯��f6=f5ʱ�Զ�����
	cout << "�����˸�ֵ���캯��\n";
	if (this == &other) {
		return *this;//Ϊ�˷�ֹf1=f1;��ֹ������Լ���ֵ
	}
	//���f1=f2;�ͻ��Զ�����operator=(this);operator=(f2);
	name = other.name;
	age = other.age;
	salary = other.salary;
	//����б�Ҫ���ͷ��Լ�����Դ(�綯̬�ڴ�)
	//addr = other.addr;//ǳ����
	strcpy_s(addr, addrlin, other.addr);//���

	//���ض����������,Ϊ�˷�������ʽ������:f1=f2=f3.
	return *this;//���뷵��.Ϊ��ֹf1=f2=f3;�������,ͻȻ���ؿյ����
}
//��������,������������,��Ȼ�����г���,��Σ��
Human::~Human() {
	cout << "������������:"<<this<<endl;
	delete addr;//�����������ڶ�������ǰ�Զ����õĺ���
}
void testxg() {//�������������ĺ���
	Human h1;
	{
		Human h2;
	}//h2����

	cout << "���Ժ�������\n";
}//h1����

int main(void) {

	while (0) {

		while (0) {//�Զ�������Ĺ��캯���ͱ�����Ĭ�ϵĹ��캯��
			Human hwx;//����һ��hwx����,Ĭ��ʹ��Ĭ�Ϲ��캯��(�Զ���>���ڳ�ʼֵ>�������ϳ�)
			Human hwx1("������", 23);//�����Զ���Ĺ��캯��,���õ�ʱ�򻹿��Դ�ӡ
			Human hwx2 = hwx1;//���ÿ������캯��,չ����������һ����
			Human hwx3(hwx1);//���ÿ������캯��,չ����������һ����

			char addr[addrlin] = "����";

			hwx1.addr1(addr);//ʹ������Զ��忽��������,�޸ĵ�ֻ����

			hwx.test();
			/*ע��!
			//(��������û��ʹ���Զ���,��ô���ֵ�ֵ�����ڳ�ʼֵ(û�����ڳ�ʼֵ���Ǳ������ϳɵ�Ĭ�Ϲ��캯��))
			�����������ĸ����ݲ���,���Զ���Ĺ��캯��ֻ��������,��ôû�д��ݵ���������
			��Ϊ(���ڳ�ʼֵ(û�����ڳ�ʼֵ���Ǳ������ϳɵ�Ĭ�Ϲ��캯��)
			*/
			hwx1.test();//ʹ������Զ��忽��������,�޸ĵ�ֻ����
			hwx2.test();
			hwx3.test();
			break;
		}
		while (0) {//�������캯���Ļ���ʹ��
			Human h1(25, 3500);
			Human h2(28, 4000);
			//showmsg(h1);
			getBetterman(h1, h2);//����һ����ʱ����,������һ�ο������캯��,����������ú�����ô�Ͳ�����ÿ������캯��
			break;
		}

		while (0) {//�������캯���ĵ���ʱ��
			Human f1, f2, f3, f4;
			Human F4[4] = { f1,f2,f3,f4 };
			break;
		}
		while (0) {//��ֵ���캯��ʾ��:
			Human f5, f6;
			f6 = f5;//�Զ����úϳɸ�ֵ���캯��,����ǳ����(λ����)
			f5.test();
			f6.test();

			cout << "\n�����\n\n";

			f5.addr1("xin");
			f5.test();
			f6.test();
			break;
		}
		break;
	}

	while (1) {//��������(�������)
		testxg();



		break;
	}



	system("pause");
	return 0;
}