#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;
//�����ϵ(һ)
class HmlFq {
public:
	HmlFq(){}
	~HmlFq(){}
	void kill() { cout << "��ľ������.kill\n"; }

private:

};

class Hml : public HmlFq {
public:
	Hml(){}
	~Hml(){}
	void kill() { cout << "��ľ��.kill\n"; }
private:

};

void tifucongjun(HmlFq HmlFq) {
	//�β���Ϊ�������ʱ,ʵ�ο��������������(�������)
	//ֻ��public�̳з�ʽ���ܴ���,�����̳з�ʽ���������� 
	HmlFq.kill();//���õ�ʽHmlFq.kill()����,������ȫ���Դ��游��
}

//�����ϵ(��)
class Father {
public:
	void play() {
		cout << "�������\n";
	}
};
class Son : public Father {
public:
	void play() {
		cout << "�������\n";
	}
	void ccc() {
		cout << "neng?\n";
	}
};

void party(Father* a,Father* b) {
	a->play();
	b->play();
}

int main(void) {
	while (0) { //�����͹�ϵ(һ),����������
	HmlFq HmlFq;
	Hml hml;
	tifucongjun(hml);
	hml.kill();
	break;
	}

	while (0) { //�����͹�ϵ(��)
		Father a;
		Son b;
		party(&a, &b);
		break;
	}

	while (1) {//�������ָ�����ָ���������
		Son son;
		Father *father = &son;
		father->play();//ֻ�ܵ��ø���ĳ�Ա

		//Father f;
		//Son *s = &f;//�������ָ�벻��ָ�������

		Father& f1 = son;//����������Ķ�����Գ�ʼ�����������
		f1.play();//������ĸ���ָ��һ��

		Father B = son;//����������ֱ�ӱ���ֵΪ�������

		//���Ϸ������ͻ�������
		break;
	}


	system("pause");
	return 0;
}