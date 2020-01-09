#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

class Father {
public:
	Father(const char* lastName="������",const char* fristName="������"){
		this->lastName=lastName;this->fristName=fristName; cout << __FUNCTION__ << endl;}
	~Father() {}

	void playBasketball() {//������
		cout << "������\n";}
	void dance() {//����
		cout << "��������\n";}

protected:
	string lastName;//��
	string fristName;//��
};

class Mother {
public:
	Mother(const char* food = "Ǯ",const char* lastName="ĸ����", const char* fristName="ĸ����") {
		this->food = food;this->lastName = lastName;this->fristName = fristName; cout << __FUNCTION__ << endl;}
	~Mother(){}

	void dance() {//����
		cout << "ĸ������\n";}
	string getfood() {
		return food;
	}

private:
	string lastName;//��
	string fristName;//��
//protected:
	string food;//ϲ��������
};

class Son : public Mother,public Father {//���ؼ̳�,class Son : public Father,private Mother Ҳ��������
	//Ĭ�Ϲ��캯����˳��͵�ϵ�̳�һ��,ֻ���ڸ���̳���˳��������Ϊ��׼
public:
	Son(const char *lastName,const char *fristName,const char *food,const char *game);
	~Son(){}

	void playgame();
	void dance() {//����
		Father::dance();
		Mother::dance();
	}
private:
	string game;

};

int main(void) {
	Son wsc("��", "˼��", "B","�࿪");
	wsc.playBasketball();
	//wsc.dance();
	wsc.Father::dance();//����Աʱ,�޶��ĸ�����ķ���,���ܽ�������ò���ȷ������
	//������ؼ̳еĶ����Եķ���(1)
	wsc.Mother::dance();//ʹ��"����::"ָ��,ָ�����ô��ĸ�����̳еķ���(��Ա)
	wsc.playgame();
	cout << "\n------------*************-------------\n";
	wsc.dance();//������ؼ̳еĶ����Եķ���(2),������������ʵ����������,�ڷ����ڲ�ʹ�û������޶����ö�Ӧ�ķ���

	system("pause");
	return 0;
}

Son::Son(const char* lastName, const char* fristName, const char* food, 
	const char* game):Father(lastName,fristName),Mother(food)
{
	/*Mother(food)�����:
	Mother(const char* food = "Ǯ",const char* lastName="ĸ����", const char* fristName="ĸ����") ,
	��˳�򸲸�,ֻ��һ����ֻ���ǵ�һ��,���水���Զ���������,���û���Զ���Ļ��������ͻ������ڳ�ʼ��>���Ժϳ�Ĭ�ϳ�ʼ��*/
	this->game = game;
	cout << __FUNCTION__ << endl;
}

void Son::playgame() {

	cout << "һ����" << game << "��,ʳ��:" << getfood() << endl;
}