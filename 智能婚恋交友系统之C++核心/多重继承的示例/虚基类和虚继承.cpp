#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//�绰��
class Tall {//����ɼ̳к�,��ʱ��ͬ�Ļ���ͳ�Ϊ"�����"
public:
	Tall(const char* number="������") {
		this->number = number;
	}

protected:
	string number;//�绰����
};

//������
class Landline :virtual public Tall {};//��Ϊ��̳�

//�ֻ���
class Phone :virtual public Tall{};//��̳�

//����������
class WirelessTel :public Landline, public Phone {
public:
	void setnumber(const char* number) {
		this->number = number;//���ò���ȷ,����virtual����ȷ��ֱ�ӷ���number
		//this->Landline::number = number;
	}

	string getnumber() {
		//return this->Phone::number;
		return number;//ֱ�ӷ���number
	}
};

int main(void) {
	while (1) { 
	WirelessTel phone;
	phone.setnumber("123456");
	cout << phone.getnumber() << endl;
	//���ؼ̳������ͼ̳��е��ش�ȱ��:�˷ѿռ�,����Ȩ�޲���ȷ(�ܲ�����)
	//��̳к�������û�������ȱ����
	//��̳й�ͬ�ĳ�Աֻ����һ��,�����Ͳ����˷ѿռ�ͷ���Ȩ�޲���ȷ��
	break;
	}

	system("pause");
	return 0;
}