#include "Home.h"

/*
����һ�������࣬��������������

����һ���࣬����ʾĳģ��������Ϸ�����
ÿ����� ���ǳƣ����䣬�Ա� ��ż�� ����,
֧�ֵĻ�У���飬���, ���ѣ��Ͻ���ѯ���ǳƣ�ѯ���Ա�ѯ������, ���ȡ�
*/

int main(void) {
	Home hwx("������", 24, women);
	Home zsf("������", 106, man);
	Home ym("����", 33, women);
	Home dlrb("�����Ȱ�", 28, women);
	Home zwc("��ΰ��", 24, man);
	
	cout << "-----------------���-----------------\n";
	zwc.Marriage(hwx);
	Home* who = zwc.getspouse();
	cout << zwc.getnickname() << "��������:" << who->Brief_introduction()<< endl;
	cout << who->getnickname() << "���Ϲ���:" << who->getspouse()->Brief_introduction() << endl;
	cout << "\n-----------------���-----------------\n";
	//hwx.divorce();
	if (hwx.getspouse() == NULL) {
		cout << hwx.getnickname() << "������\n";
	}
	else {
		cout << hwx.getnickname()<<"û��,��"<<hwx.getspouse()->getnickname()<<"������\n";
	}
	cout << "\n-----------------����-----------------\n";
	zwc.MakeFriends(ym);
	zwc.MakeFriends(zsf);
	zwc.MakeFriends(dlrb);
	//auto friends = zwc.getfriends();������һ��
	vector<Home*>friends = zwc.getfriends();
	for (int i = 0; i < friends.size(); i++) {//�������ѵ���Ϣ��ӡ
		cout << friends[i]->Brief_introduction() << endl;
	}
	cout << "\n-----------------�Ͻ�-----------------\n";
	zwc.Break_Off_Friendship(zsf);
	cout << zwc.getnickname() << "��" << zsf.getnickname() << "�Ͻ���.\n";
	friends = zwc.getfriends();//��ȡ�����б�
	for (int i = 0; i < friends.size(); i++) {//�������ѵ���Ϣ��ӡ
		cout << friends[i]->Brief_introduction() << endl;
	}



	system("pause");
	return 0;
}